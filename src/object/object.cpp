#include <object/object.h>

#include <engine/game.h>

cub::Object::Object(Game *game)
	: _game(game), _position(0.0f), _scale(1.0f)
{
}

cub::Object::~Object()
{
}

glm::vec3 cub::Object::GetPosition() const
{
	return _position;
}

void cub::Object::SetPosition(const glm::vec3& position)
{
	_position = position;
}

glm::quat cub::Object::GetRotation() const
{
	return _rotation;
}

void cub::Object::SetRotation(const glm::quat& rotation)
{
	_rotation = rotation;
}

glm::vec3 cub::Object::GetScale() const
{
	return _scale;
}

void cub::Object::SetScale(const glm::vec3& scale)
{
	_scale = scale;
}