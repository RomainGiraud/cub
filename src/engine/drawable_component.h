#ifndef CUB_DRAWABLECOMPONENT_H
#define CUB_DRAWABLECOMPONENT_H

#include <engine/component.h>

namespace cub
{

class Game;

class DrawableComponent : public Component
{
public:
    DrawableComponent(Game *game);
    virtual ~DrawableComponent();

    virtual void Load() = 0;
    virtual void Update(double timeSec) = 0;
    virtual void Render(double timeSec) = 0;
};

}

#endif /*CUB_DRAWABLECOMPONENT_H*/