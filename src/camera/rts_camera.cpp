#include <camera/rts_camera.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

cub::RTSCamera::RTSCamera(Game *game)
    : AbstractCamera(game)
{
    _position = _targetPosition = glm::vec3(0.0f);
    _orientation = _targetOrientation = glm::quat();

    _aspectRatio = 1.333f;
    _fov = 60;
    _znear = 0.1f;
    _zfar = 1000;

    UpdateProjectionMatrix();
    UpdateViewMatrix();
}

void cub::RTSCamera::Update(double time)
{
    if (_position != _targetPosition)
    {
        _position = glm::mix(_position, _targetPosition, time * 5);
        UpdateViewMatrix();
    }
}

glm::mat4 cub::RTSCamera::GetProjectionMatrix() const
{
    return _projectionMatrix;
}

glm::mat4 cub::RTSCamera::GetViewMatrix() const
{
    return _viewMatrix;
}

void cub::RTSCamera::Translate(glm::vec3 v)
{
    _targetPosition += v;
    //_position += v;
    UpdateViewMatrix();
}

glm::vec3 cub::RTSCamera::GetPosition() const
{
    return _position;
}

void cub::RTSCamera::SetPosition(glm::vec3 p)
{
    //_position = _targetPosition = p;
    _position = p;
    UpdateViewMatrix();
}

float cub::RTSCamera::GetZNear() const
{
    return _znear;
}

void cub::RTSCamera::SetZNear(float v)
{
    _znear = v;
    UpdateProjectionMatrix();
}

float cub::RTSCamera::GetZFar() const
{
    return _zfar;
}

void cub::RTSCamera::SetZFar(float v)
{
    _zfar = v;
    UpdateProjectionMatrix();
}

float cub::RTSCamera::GetFieldOfView() const
{
    return _fov;
}

void cub::RTSCamera::SetFieldOfView(float v)
{
    _fov = v;
    UpdateProjectionMatrix();
}

float cub::RTSCamera::GetAspectRatio() const
{
    return _aspectRatio;
}

void cub::RTSCamera::SetAspectRatio(float v)
{
    _aspectRatio = v;
    UpdateProjectionMatrix();
}

void cub::RTSCamera::UpdateProjectionMatrix()
{
    _projectionMatrix = glm::perspective(_fov, _aspectRatio, _znear, _zfar);

    UpdateBoundingFrustum();
}

void cub::RTSCamera::UpdateViewMatrix()
{
    glm::mat4 rot = glm::rotate(45.0f, glm::vec3(1, 0, 0));
    _direction = glm::vec3(glm::vec4(0, 0, -1, 1) * rot);
    _target = _position + _direction;
    _viewMatrix = glm::lookAt(_position, _target, glm::vec3(0, 1, 0));

    UpdateBoundingFrustum();
}

const cub::BoundingFrustum& cub::RTSCamera::GetBoundingFrustum() const
{
    return _boundingFrustum;
}

void cub::RTSCamera::UpdateBoundingFrustum()
{
    glm::mat4 m = _projectionMatrix * _viewMatrix;
    _boundingFrustum.SetMatrix(m);
}

glm::vec3 cub::RTSCamera::GetDirection() const
{
    return _direction;
}

glm::vec3 cub::RTSCamera::GetTarget() const
{
    return _target;
}

glm::vec3 cub::RTSCamera::GetTargetPosition() const
{
    return _targetPosition;
}

void cub::RTSCamera::SetTargetPosition(glm::vec3 p)
{
    _targetPosition = p;
}