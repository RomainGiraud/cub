#ifndef CUB_FREECAMERA_H
#define CUB_FREECAMERA_H

#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <global/tools.h>

#include <camera/abstract_camera.h>

namespace cub
{

class Game;

class FreeCamera : public AbstractCamera
{
public:

    enum CamMode
    {
        FlightCamera,
        NoOne
    };

    FreeCamera(Game *game);
    void Update(double time);
    glm::mat4 GetProjectionMatrix();
    glm::mat4 GetViewMatrix();
    glm::mat4 GetViewMatrixWithoutTranslation();
    void FixMouse();
    void CalculateMouseDelta();
    void ResetMouse();
    void ClampMouseValues();
    void UpdateRotations(double time);
    void ApplyRotation();
    void UpdateMovement(double time);

    glm::vec3 Position();
    void SetPosition(glm::vec3 p);
    void Translate(glm::vec3 v);

    glm::quat Orientation();
    void SetOrientation(glm::quat o);

    glm::vec3 TargetPosition();
    void SetTargetPosition(glm::vec3 t);
        
    glm::quat TargetOrientation();
    void SetTargetOrientation(glm::quat o);
        
    glm::quat TargetOrientationY();
    void SetTargetOrientationY(glm::quat o);

    bool MouseLookEnabled();
    void SetMouseLookEnabled(bool b);

    float MouseYSensitivity();
    void SetMouseYSensitivity(float v);

    float MouseXSensitivity();
    void SetMouseXSensitivity(float v);

    glm::vec2 MouseRotation();
    void SetMouseRotation(glm::vec2 m);

    glm::vec3 Movement();
    void SetMovement(glm::vec3 m);

    float Speed();
    void SetSpeed(float v);

    float Acceleration();
    void SetAcceleration(float v);

    glm::vec2 WindowCenter();

    float ZNear();
    void SetZNear(float v);

    float ZFar();
    void SetZFar(float v);

    float FieldOfView();
    void SetFieldOfView(float v);

    float AspectRatio();
    void SetAspectRatio(float v);

    CamMode CameraMode();
    void SetCameraMode(CamMode mode);
    
private:
    glm::vec3 _position;
    glm::quat _orientation;
    glm::vec3 _targetPosition;
    glm::quat _targetOrientation;
    glm::quat _targetOrientationY;
    bool _mouseLookEnabled;
    float _mouseYSensitivity;
    float _mouseXSensitivity;
    glm::vec2 _mouseRotation;
    glm::vec3 _movement;
    float _speed;
    float _acceleration;
    float _znear;
    float _zfar;
    float _fov;
    float _aspectRatio;
    CamMode _cameraMode;
    glm::vec2 _mouseDelta;
};

}

#endif /*CUB_FREECAMERA_H*/
