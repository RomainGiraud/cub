#include <camera/rts_camera.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

cub::RTSCamera::RTSCamera(Game *game)
    : AbstractCamera(game)
{
    _position = glm::vec3(0.0f);
    _orientation = glm::quat();

    _aspectRatio = 1.333f;
    _fov = 60;
    _znear = 0.1f;
    _zfar = 1000;

    UpdateProjectionMatrix();
    UpdateViewMatrix();
}

glm::mat4 cub::RTSCamera::GetProjectionMatrix()
{
    return _projectionMatrix;
}

glm::mat4 cub::RTSCamera::GetViewMatrix()
{
    return _viewMatrix;
}

void cub::RTSCamera::Translate(glm::vec3 v)
{
    _position += v;
    UpdateViewMatrix();
}

glm::vec3 cub::RTSCamera::Position()
{
    return _position;
}

void cub::RTSCamera::SetPosition(glm::vec3 p)
{
    _position = p;
    UpdateViewMatrix();
}

float cub::RTSCamera::ZNear()
{
    return _znear;
}

void cub::RTSCamera::SetZNear(float v)
{
    _znear = v;
    UpdateProjectionMatrix();
}

float cub::RTSCamera::ZFar()
{
    return _zfar;
}

void cub::RTSCamera::SetZFar(float v)
{
    _zfar = v;
    UpdateProjectionMatrix();
}

float cub::RTSCamera::FieldOfView()
{
    return _fov;
}

void cub::RTSCamera::SetFieldOfView(float v)
{
    _fov = v;
    UpdateProjectionMatrix();
}

float cub::RTSCamera::AspectRatio()
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
    glm::mat4 rot = glm::rotate(30.0f, glm::vec3(1, 0, 0));
    glm::vec3 target = _position + glm::vec3(glm::vec4(0, 0, -1, 1) * rot);
    _viewMatrix = glm::lookAt(_position, target, glm::vec3(0, 1, 0));

    UpdateBoundingFrustum();
}

cub::BoundingFrustum& cub::RTSCamera::GetBoundingFrustum()
{
    return _boundingFrustum;
}

void cub::RTSCamera::UpdateBoundingFrustum()
{
    glm::mat4 m = _projectionMatrix * _viewMatrix;
    _boundingFrustum.SetMatrix(m);
}