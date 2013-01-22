#ifndef CUB_ABSTRACTCAMERA_H
#define CUB_ABSTRACTCAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <geometry/bounding_frustum.h>

namespace cub
{

class Game;

class AbstractCamera
{
public:
    AbstractCamera(Game *game);
    virtual ~AbstractCamera();

    virtual glm::vec3 GetPosition() const = 0;
    virtual void SetPosition(glm::vec3 p) = 0;

    virtual float GetAspectRatio() const = 0;
    virtual void SetAspectRatio(float ratio) = 0;

    virtual glm::vec3 GetDirection() const = 0;
    virtual glm::vec3 GetTarget() const = 0;
    
    virtual const BoundingFrustum& GetBoundingFrustum() const = 0;

    virtual glm::mat4 GetProjectionMatrix() const = 0;
    virtual glm::mat4 GetViewMatrix() const = 0;

    virtual void Translate(glm::vec3 v) = 0;
    
protected:
    Game *_game;
};

}

#endif /*CUB_ABSTRACTCAMERA_H*/
