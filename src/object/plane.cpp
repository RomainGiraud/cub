#include <object/plane.h>

#include <engine/game.h>
#include <engine/content.h>
#include <global/tools.h>

#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>

#include <iostream>
using namespace std;

cub::Plane::Plane(Game *game)
	: Object(game),
      _indiceBuffer(Buffer::Index),
      _vertexBuffer(Buffer::Vertex),
      _normalBuffer(Buffer::Vertex),
      _textureBuffer(Buffer::Vertex),
      _textureID(-1)
{
    UpdateSize();
}

cub::Plane::~Plane()
{
}

void cub::Plane::SetTexture(GLuint textureID)
{
    _textureID = textureID;
}

void cub::Plane::Load()
{
    _shader = _game->GetContent().LoadShaders("shaders/phong_tex.vert", "shaders/phong_tex.frag");
}

void cub::Plane::Update(double time)
{
}

void cub::Plane::Render(double time)
{
    glm::mat4 projectionMatrix = _game->GetCamera().GetProjectionMatrix();
    glm::mat4 viewMatrix       = _game->GetCamera().GetViewMatrix();
    glm::mat4 modelMatrix      = glm::translate(_position) * glm::toMat4(_rotation) * glm::scale(_scale);

    glm::mat4 mvMatrix = viewMatrix * modelMatrix;
    glm::mat4 mvpMatrix = projectionMatrix * mvMatrix;
    glm::mat3 normalMatrix = glm::inverseTranspose(glm::mat3(mvMatrix));

    glm::vec4 light = glm::vec4(0, 0, 5, 1) * viewMatrix;
    //light.w = 0;

    _shader->Bind();
    _shader->SetUniformValue("mvMatrix", mvMatrix);
    _shader->SetUniformValue("mvpMatrix", mvpMatrix);
    _shader->SetUniformValue("normalMatrix", normalMatrix);
    _shader->SetUniformValue("Light.Position", light);
    _shader->SetUniformValue("Light.Intensity", glm::vec3(1, 1, 1));
    _shader->SetUniformValue("Material.Ka", glm::vec3(0.15f, 0.15f, 0.15f));
    _shader->SetUniformValue("Material.Kd", glm::vec3(0.75f, 0.75f, 0.75f));
    _shader->SetUniformValue("Material.Ks", glm::vec3(0.992157f, 0.941176f, 0.807843f));
    _shader->SetUniformValue("Material.Shininess", 27.9f);

    if (_textureID != (GLuint)-1)
    {
        gl::ActiveTexture(gl::TEXTURE0);
        gl::BindTexture(gl::TEXTURE_2D, _textureID);
        _shader->SetUniformValue("DiffuseTexture", 0);
    }

    _shader->EnableVertexAttribArray("in_Position");
    _vertexBuffer.Bind();
    _shader->VertexAttribPointer("in_Position", 3, gl::FLOAT, false, 0, 0);

    _shader->EnableVertexAttribArray("in_Normal");
    _normalBuffer.Bind();
    _shader->VertexAttribPointer("in_Normal", 3, gl::FLOAT, false, 0, 0);

    _shader->EnableVertexAttribArray("in_TexCoord");
    _textureBuffer.Bind();
    _shader->VertexAttribPointer("in_TexCoord", 2, gl::FLOAT, false, 0, 0);

    _indiceBuffer.Bind();
    
    gl::DrawElements(gl::TRIANGLES, _indiceLength, gl::UNSIGNED_INT, 0);
}

void cub::Plane::UpdateSize()
{
    const unsigned int sizeVert = 3 * 4;
    float vertices[sizeVert] = {
        -0.5f, -0.5f,  0.0f,
         0.5f, -0.5f,  0.0f,
         0.5f,  0.5f,  0.0f,
        -0.5f,  0.5f,  0.0f,
    };

    const unsigned int sizeNorm = 3 * 4;
    float normals[sizeNorm] = {
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f
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
    _normalBuffer.Attach(normals, sizeNorm * sizeof(float));
    _textureBuffer.Attach(texcoords, sizeTexcoords * sizeof(float));
}