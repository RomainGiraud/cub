#include <engine/component.h>

#include <engine/game.h>

cub::Component::Component(Game *game)
	: _game(game)
{
}

cub::Component::~Component()
{
}