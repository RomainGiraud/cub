#include <object/line.h>

#include <engine/game.h>

#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

cub::Line::Line(Game *game, glm::vec3 direction)
	: Object(game),
      _indiceBuffer(Buffer::Index),
      _vertexBuffer(Buffer::Vertex)
{
	SetDirection(direction);
	UpdateSize();
}

cub::Line::~Line()
{
}

float cub::Line::GetSize() const
{
	return _size;
}

void cub::Line::SetSize(float size)
{
	_size = size;
	UpdateSize();
}

glm::vec3 cub::Line::GetDirection() const
{
	return _direction;
}

void cub::Line::SetDirection(const glm::vec3& direction)
{
	_size = glm::length(direction);
	_direction = glm::normalize(direction);
	UpdateSize();
}

glm::vec3 cub::Line::GetEnd() const
{
	return _position + _direction * _size;
}

void cub::Line::SetEnd(const glm::vec3& end)
{
	glm::vec3 dir = end - _position;
	_direction = glm::normalize(dir);
	_size = glm::length(dir);

	UpdateSize();
}

void cub::Line::Load()
{
    _shader = _game->GetContent().LoadShaders("shaders/base.vert", "shaders/base.frag");
}

void cub::Line::Update(double time)
{
}

void cub::Line::Render(double time)
{
    glm::mat4 projectionMatrix = _game->GetCamera().GetProjectionMatrix();
    glm::mat4 viewMatrix = _game->GetCamera().GetViewMatrix();
    glm::mat4 modelMatrix = glm::translate(_position);

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

void cub::Line::UpdateSize()
{
	glm::vec3 end = _direction * _size;

	const unsigned int sizeVert = 3 * 2;
	float vertices[sizeVert] = {
		0, 0, 0,
		end.x, end.y, end.z
	};

	_indiceLength = 2;
	unsigned int indices[2] = {
		0, 1
	};

    _indiceBuffer.Attach(indices, _indiceLength * sizeof(unsigned int));
    _vertexBuffer.Attach(vertices, sizeVert * sizeof(float));
}