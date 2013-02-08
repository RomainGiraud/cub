#include <object/screen_aligned_quad.h>

#include <engine/game.h>
#include <engine/content.h>
#include <global/tools.h>

#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>

#include <iostream>
using namespace std;

cub::ScreenAlignedQuad::ScreenAlignedQuad(Game *game)
	: Object(game),
      _indiceBuffer(Buffer::Index),
      _vertexBuffer(Buffer::Vertex),
      _normalBuffer(Buffer::Vertex),
      _textureBuffer(Buffer::Vertex),
      _textureID(-1)
{
    UpdateSize();
}

cub::ScreenAlignedQuad::~ScreenAlignedQuad()
{
}

void cub::ScreenAlignedQuad::SetTexture(GLuint textureID)
{
    _textureID = textureID;
}

void cub::ScreenAlignedQuad::Load()
{
    _shader = _game->GetContent().LoadShaders("shaders/ui.vert", "shaders/ui.frag");
}

void cub::ScreenAlignedQuad::Update(double time)
{
}

void cub::ScreenAlignedQuad::Render(double time)
{
    glm::mat4 projectionMatrix = (glm::mat4)glm::ortho(0, 1, 0, 1, 0, 100);
    glm::mat4 viewMatrix       = glm::lookAt(glm::vec3(0,0,1), glm::vec3(0,0,0), glm::vec3(0,1,0));
    glm::mat4 modelMatrix      = glm::mat4(1.0f);

    glm::mat4 mvMatrix = viewMatrix * modelMatrix;
    glm::mat4 mvpMatrix = projectionMatrix * mvMatrix;

    _shader->Bind();
    _shader->SetUniformValue("mvpMatrix", mvpMatrix);

    if (_textureID != (GLuint)-1)
    {
        gl::ActiveTexture(gl::TEXTURE0);
        gl::BindTexture(gl::TEXTURE_2D, _textureID);
        _shader->SetUniformValue("DiffuseTexture", 0);
    }

    _shader->EnableVertexAttribArray("in_Position");
    _vertexBuffer.Bind();
    _shader->VertexAttribPointer("in_Position", 3, gl::FLOAT, false, 0, 0);

    _shader->EnableVertexAttribArray("in_TexCoord");
    _textureBuffer.Bind();
    _shader->VertexAttribPointer("in_TexCoord", 2, gl::FLOAT, false, 0, 0);

    _indiceBuffer.Bind();
    
    gl::DrawElements(gl::TRIANGLES, _indiceLength, gl::UNSIGNED_INT, 0);
}

void cub::ScreenAlignedQuad::UpdateSize()
{
    const unsigned int sizeVert = 3 * 4;
    float vertices[sizeVert] = {
        0.0f, 0.0f,  0.0f,
        1.0f, 0.0f,  0.0f,
        1.0f, 1.0f,  0.0f,
        0.0f, 1.0f,  0.0f,
    };

    const unsigned int sizeTexcoords = 2 * 4;
    float texcoords[sizeTexcoords] = {
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f
    };

    _indiceLength = 6;
    unsigned int indices[6] = {
        0, 1, 2, 0, 2, 3
    };

    _indiceBuffer.Attach(indices, _indiceLength * sizeof(unsigned int));
    _vertexBuffer.Attach(vertices, sizeVert * sizeof(float));
    _textureBuffer.Attach(texcoords, sizeTexcoords * sizeof(float));
}