#include <object/object.h>

#include <engine/game.h>

cub::Object::Object(Game *game)
	: _game(game)
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