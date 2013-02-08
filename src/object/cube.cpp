#include <object/cube.h>

#include <engine/game.h>
#include <engine/content.h>

#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

cub::Cube::Cube(Game *game)
	: Object(game), _isWireframe(true),
      _indiceBuffer(Buffer::Index),
      _vertexBuffer(Buffer::Vertex),
      _normalBuffer(Buffer::Vertex)
{
	UpdateSize();
}

cub::Cube::~Cube()
{
}

void cub::Cube::Load()
{
    _shader = _game->GetContent().LoadShaders("shaders/base.vert", "shaders/base.frag");
}

void cub::Cube::Update(double time)
{
}

void cub::Cube::Render(double time)
{
	if (_isWireframe)
		RenderWireframe(time);
	else
		RenderPlain(time);
}

void cub::Cube::RenderWireframe(double time)
{
    glm::mat4 projectionMatrix = _game->GetCamera().GetProjectionMatrix();
    glm::mat4 viewMatrix = _game->GetCamera().GetViewMatrix();
    glm::mat4 modelMatrix = glm::translate(_position) * glm::toMat4(_rotation) * glm::scale(_scale);
    // myTranslationMatrix * myRotationMatrix * myScaleMatrix

    glm::mat4 mvMatrix = viewMatrix * modelMatrix;
    glm::mat4 mvpMatrix = projectionMatrix * mvMatrix;

    _shader->Bind();
    _shader->SetUniformValue("mvpMatrix", mvpMatrix);


    _shader->EnableVertexAttribArray("in_Position");
    _vertexBuffer.Bind();
    _shader->VertexAttribPointer("in_Position", 3, gl::FLOAT, false, 0, 0);

    _indiceBuffer.Bind();

    
    gl::DrawElements(gl::LINES, _indiceLength, gl::UNSIGNED_INT, 0);
}

void cub::Cube::RenderPlain(double time)
{
    glm::mat4 projectionMatrix = _game->GetCamera().GetProjectionMatrix();
    glm::mat4 viewMatrix = _game->GetCamera().GetViewMatrix();
    glm::mat4 modelMatrix = glm::translate(_position) * glm::toMat4(_rotation) * glm::scale(_scale);

    glm::mat4 mvMatrix = viewMatrix * modelMatrix;
    glm::mat4 mvpMatrix = projectionMatrix * mvMatrix;

    _shader->Bind();
    _shader->SetUniformValue("mvpMatrix", mvpMatrix);


    _shader->EnableVertexAttribArray("in_Position");
    _vertexBuffer.Bind();
    _shader->VertexAttribPointer("in_Position", 3, gl::FLOAT, false, 0, 0);

    _indiceBuffer.Bind();

    
    gl::DrawElements(gl::TRIANGLES, _indiceLength, gl::UNSIGNED_INT, 0);
}

void cub::Cube::UpdateSize()
{
    if (_isWireframe)
        UpdateSizeWireframe();
    else
        UpdateSizePlain();
}

void cub::Cube::UpdateSizeWireframe()
{
	const unsigned int sizeVert = 3 * 8;
	float vertices[sizeVert] = {
        1.0f, 1.0f, 1.0f, // Vertex 0 (X, Y, Z)
        0.0f, 1.0f, 1.0f, // Vertex 1 (X, Y, Z)
        0.0f, 0.0f, 1.0f, // Vertex 2 (X, Y, Z)
        1.0f, 0.0f, 1.0f, // Vertex 3 (X, Y, Z)
        1.0f, 1.0f, 0.0f, // Vertex 4 (X, Y, Z)
        0.0f, 1.0f, 0.0f, // Vertex 5 (X, Y, Z)
        0.0f, 0.0f, 0.0f, // Vertex 6 (X, Y, Z)
        1.0f, 0.0f, 0.0f  // Vertex 7 (X, Y, Z)
	};

	_indiceLength = 2 * 12;
	unsigned int indices[2 * 12] = {
		0, 1,
        1, 2,
        2, 3,
        3, 0,
        4, 5,
        5, 6,
        6, 7,
        7, 4,
        0, 4,
        1, 5,
        2, 6,
        3, 7
	};

    _indiceBuffer.Attach(indices, _indiceLength * sizeof(unsigned int));
    _vertexBuffer.Attach(vertices, sizeVert * sizeof(float));
}

void cub::Cube::UpdateSizePlain()
{
    const unsigned int sizeVert = 3 * 8;
    float vertices[sizeVert] = {
        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f
    };

    const unsigned int sizeNorm = 3 * 8;
    float normals[sizeNorm] = {
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f
    };

    _indiceLength = 6 * 6;
    unsigned int indices[6 * 6] = {
        0, 1, 2, 2, 3, 0,
        3, 2, 6, 6, 7, 3,
        7, 6, 5, 5, 4, 7,
        4, 0, 3, 3, 7, 4,
        0, 1, 5, 5, 4, 0,
        1, 5, 6, 6, 2, 1
    };

    _indiceBuffer.Attach(indices, _indiceLength * sizeof(unsigned int));
    _vertexBuffer.Attach(vertices, sizeVert * sizeof(float));
    _normalBuffer.Attach(normals, sizeNorm * sizeof(float));
}