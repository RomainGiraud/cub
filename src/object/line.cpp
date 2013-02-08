#include <object/line.h>

#include <engine/game.h>
#include <engine/content.h>

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

glm::vec3 cub::Line::GetDirection() const
{
	return _direction;
}

void cub::Line::SetDirection(const glm::vec3& direction)
{
	_direction = direction;
	UpdateSize();
}

glm::vec3 cub::Line::GetEnd() const
{
	return _position + _direction;
}

void cub::Line::SetEnd(const glm::vec3& end)
{
	_direction = end - _position;
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
	const unsigned int sizeVert = 3 * 2;
	float vertices[sizeVert] = {
		0, 0, 0,
		_direction.x, _direction.y, _direction.z
	};

	_indiceLength = 2;
	unsigned int indices[2] = {
		0, 1
	};

    _indiceBuffer.Attach(indices, _indiceLength * sizeof(unsigned int));
    _vertexBuffer.Attach(vertices, sizeVert * sizeof(float));
}

glm::quat cub::Line::GetRotation() const
{
	return Object::GetRotation();
}

void cub::Line::SetRotation(const glm::quat& rotation)
{
	Object::SetRotation(rotation);
}

glm::vec3 cub::Line::GetScale() const
{
	return Object::GetScale();
}

void cub::Line::SetScale(const glm::vec3& scale)
{
	Object::SetScale(scale);
}