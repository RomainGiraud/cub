#ifndef CUB_COMPONENT_H
#define CUB_COMPONENT_H

namespace cub
{

class Game;

class Component
{
public:
    Component(Game *game);
    virtual ~Component();

    virtual void Load() = 0;
    virtual void Update(double timeSec) = 0;

protected:
    Game *_game;
};

}

#endif /*CUB_COMPONENT_H*/