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

    void Update(double time);

    glm::vec3 GetPosition() const;
    void SetPosition(glm::vec3 p);
    
    glm::vec3 GetTargetPosition() const;
    void SetTargetPosition(glm::vec3 p);

    float GetAspectRatio() const;
    void SetAspectRatio(float v);

    glm::vec3 GetDirection() const;
    glm::vec3 GetTarget() const;

    float GetZNear() const;
    void SetZNear(float v);

    float GetZFar() const;
    void SetZFar(float v);

    float GetFieldOfView() const;
    void SetFieldOfView(float v);

    const BoundingFrustum& GetBoundingFrustum() const;
    glm::mat4 GetProjectionMatrix() const;
    glm::mat4 GetViewMatrix() const;
    
    void Translate(glm::vec3 v);
    
private:
    Game *_game;

    glm::vec3 _position;
    glm::quat _orientation;

    glm::vec3 _targetPosition;
    glm::quat _targetOrientation;

    glm::mat4 _projectionMatrix;
    glm::mat4 _viewMatrix;

    glm::vec3 _target;
    glm::vec3 _direction;

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
