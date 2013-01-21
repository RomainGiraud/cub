#ifndef CUB_RTSCAMERA_H
#define CUB_RTSCAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <camera/abstract_camera.h>

namespace cub
{

class Game;

class RTSCamera : public AbstractCamera
{
public:
    RTSCamera(Game *game);
    glm::mat4 GetProjectionMatrix();
    glm::mat4 GetViewMatrix();
    void Translate(glm::vec3 v);

    glm::vec3 Position();
    void SetPosition(glm::vec3 p);

    float ZNear();
    void SetZNear(float v);

    float ZFar();
    void SetZFar(float v);

    float FieldOfView();
    void SetFieldOfView(float v);

    float AspectRatio();
    void SetAspectRatio(float v);

    BoundingFrustum& GetBoundingFrustum();
    
private:
    Game *_game;

    glm::vec3 _position;
    glm::quat _orientation;

    glm::mat4 _projectionMatrix;
    glm::mat4 _viewMatrix;

    BoundingFrustum _boundingFrustum;

    float _znear;
    float _zfar;
    float _fov;
    float _aspectRatio;
    
    void UpdateProjectionMatrix();
    void UpdateViewMatrix();
    void UpdateBoundingFrustum();
};

}

#endif /*CUB_RTSCAMERA_H*/
