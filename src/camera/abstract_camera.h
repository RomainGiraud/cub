#ifndef CUB_ABSTRACTCAMERA_H
#define CUB_ABSTRACTCAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace cub
{

class Game;

class AbstractCamera
{
public:
    AbstractCamera(Game *game);
    virtual void SetPosition(glm::vec3 p) = 0;
    virtual void Translate(glm::vec3 v) = 0;
    virtual glm::mat4 GetProjectionMatrix() = 0;
    virtual glm::mat4 GetViewMatrix() = 0;
    
protected:
    Game *_game;
};

}

#endif /*CUB_ABSTRACTCAMERA_H*/