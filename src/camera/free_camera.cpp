#include <camera/free_camera.h>
#include <engine/game.h>

cub::FreeCamera::FreeCamera(Game *game)
    : AbstractCamera(game)
{
    _speed = 50.0f;
    _targetPosition = _position = glm::vec3(0.0f);
    _targetOrientation = _orientation = glm::quat();
    _mouseRotation = glm::vec2(0, 0);
    _movement = glm::vec3(0, 0, 0);
    _mouseLookEnabled = true;

    _aspectRatio = 1.333f;
    _fov = 60;
    _znear = 0.1f;
    _zfar = 1000;

    if (_mouseLookEnabled)
    {
        //_game->CursorHide();
        ResetMouse();
        ApplyRotation();
        _orientation = _targetOrientation;
    }
}

void cub::FreeCamera::Update(double time)
{
    if (time == 0)
        return;

    if (_mouseLookEnabled)
    {
        UpdateRotations(time);
    }
    UpdateMovement(time);


    if (_targetOrientation != _orientation)
    {
        _orientation = glm::mix(_orientation, _targetOrientation, (float)time);
    }

    if (_targetPosition != _position)
    {
        _position = glm::mix(_position, _targetPosition, time);
    }

}

glm::mat4 cub::FreeCamera::GetProjectionMatrix()
{
    return glm::perspective(_fov, _aspectRatio, _znear, _zfar);
}

glm::mat4 cub::FreeCamera::GetViewMatrix()
{
    glm::mat4 translationMatrix = glm::translate(-_position);
    glm::mat4 rotationMatrix = glm::mat4_cast(_orientation);
    return translationMatrix * rotationMatrix;
}

glm::mat4 cub::FreeCamera::GetViewMatrixWithoutTranslation()
{
    return glm::mat4_cast(_orientation);
}

void cub::FreeCamera::FixMouse()
{
    ResetMouse();
    CalculateMouseDelta();
    ApplyRotation();
    _orientation = _targetOrientation;
}

void cub::FreeCamera::CalculateMouseDelta()
{
    _mouseDelta = _game->GetMousePosition() - WindowCenter();
}

void cub::FreeCamera::ResetMouse()
{
    _game->SetMousePosition(WindowCenter());
}

void cub::FreeCamera::ClampMouseValues()
{
    if (_mouseRotation.y >= 90) //90 degrees in radians
        _mouseRotation.y = 90;
    if (_mouseRotation.y <= -90)
        _mouseRotation.y = -90;

    if (_mouseRotation.x >= 360) //360 degrees in radians (or something in radians)
        _mouseRotation.x -= 360;
    if (_mouseRotation.x <= -360)
        _mouseRotation.x += 360;
}

void cub::FreeCamera::UpdateRotations(double time)
{
    CalculateMouseDelta();
    _mouseRotation.x += (float)(_mouseDelta.x * _mouseXSensitivity * time);
    _mouseRotation.y += (float)(_mouseDelta.y * _mouseYSensitivity * time);

    ClampMouseValues();
    ApplyRotation();
    if (_cameraMode != FlightCamera)
    {
        _orientation = _targetOrientation;
    }
    ResetMouse();
}

void cub::FreeCamera::ApplyRotation()
{
    _targetOrientationY = glm::quat(glm::pi<float>() + _mouseRotation.x, glm::vec3(0, 1, 0));
    _targetOrientation = glm::quat(_mouseRotation.y, glm::vec3(1, 0, 0)) + _targetOrientationY;

}

void cub::FreeCamera::UpdateMovement(double time)
{
    /*
    if (m_Keyboard[Key.Z] && !m_Keyboard[Key.S])
    {
        Movement.Z = 0;
        Movement.Z -= Speed * (float)time;
    }
    else if (m_Keyboard[Key.S] && !m_Keyboard[Key.Z])
    {
        Movement.Z = 0;
        Movement.Z += Speed * (float)time;
    }
    else Movement.Z = 0.0f;

    if (m_Keyboard[Key.Q] && !m_Keyboard[Key.D])
    {
        Movement.X = 0.0f;
        Movement.X -= Speed * (float)time;
    }
    else if (m_Keyboard[Key.D] && !m_Keyboard[Key.Q])
    {
        Movement.X = 0.0f;
        Movement.X += Speed * (float)time;
    }
    else
        Movement.X = 0.0f;

    if (CameraMode == CamMode.FirstPerson)
    {
        TargetPosition += Vector3.Transform(Movement, Quaternion.Invert(TargetOrientationY));
        TargetPosition = new Vector3(TargetPosition.X, 5, TargetPosition.Z);
    }
    else
        TargetPosition += Vector3.Transform(Movement, Quaternion.Invert(Orientation));
    if (CameraMode != CamMode.FlightCamera)
        Position = TargetPosition;
    */
}

glm::vec3 cub::FreeCamera::Position()
{
    return _position;
}

void cub::FreeCamera::SetPosition(glm::vec3 p)
{
    _position = p;
}

void cub::FreeCamera::Translate(glm::vec3 v)
{
    _position += v;
}

glm::quat cub::FreeCamera::Orientation()
{
    return _orientation;
}

void cub::FreeCamera::SetOrientation(glm::quat o)
{
    _orientation = o;
}

glm::vec3 cub::FreeCamera::TargetPosition()
{
    return _targetPosition;
}

void cub::FreeCamera::SetTargetPosition(glm::vec3 t)
{
    _targetPosition = t;
}

glm::quat cub::FreeCamera::TargetOrientation()
{
    return _targetOrientation;
}

void cub::FreeCamera::SetTargetOrientation(glm::quat o)
{
    _targetOrientation = o;
}

glm::quat cub::FreeCamera::TargetOrientationY()
{
    return _targetOrientationY;
}

void cub::FreeCamera::SetTargetOrientationY(glm::quat o)
{
    _targetOrientationY = o;
}


bool _mouseLookEnabled;
bool cub::FreeCamera::MouseLookEnabled()
{
    return _mouseLookEnabled;
}

void cub::FreeCamera::SetMouseLookEnabled(bool b)
{
    _mouseLookEnabled = b;
    if (_mouseLookEnabled)
    {
        _game->CursorHide();
        ResetMouse();
    }
    else
    {
        _game->CursorShow();
    }
}

float cub::FreeCamera::MouseYSensitivity()
{
    return _mouseYSensitivity;
}

void cub::FreeCamera::SetMouseYSensitivity(float v)
{
    _mouseYSensitivity = v;
}

float cub::FreeCamera::MouseXSensitivity()
{
    return _mouseXSensitivity;
}

void cub::FreeCamera::SetMouseXSensitivity(float v)
{
    _mouseXSensitivity = v;
}

glm::vec2 cub::FreeCamera::MouseRotation()
{
    return _mouseRotation;
}

void cub::FreeCamera::SetMouseRotation(glm::vec2 m)
{
    _mouseRotation = m;
}

glm::vec3 cub::FreeCamera::Movement()
{
    return _movement;
}

void cub::FreeCamera::SetMovement(glm::vec3 m)
{
    _movement = m;
}

float cub::FreeCamera::Speed()
{
    return _speed;
}

void cub::FreeCamera::SetSpeed(float v)
{
    _speed = v;
}

float cub::FreeCamera::Acceleration()
{
    return _acceleration;
}

void cub::FreeCamera::SetAcceleration(float v)
{
    _acceleration = v;
}

glm::vec2 cub::FreeCamera::WindowCenter()
{
    return _game->GetSize() * 0.5f;
}

float cub::FreeCamera::ZNear()
{
    return _znear;
}

void cub::FreeCamera::SetZNear(float v)
{
    _znear = v;
}

float cub::FreeCamera::ZFar()
{
    return _zfar;
}

void cub::FreeCamera::SetZFar(float v)
{
    _zfar = v;
}

float cub::FreeCamera::FieldOfView()
{
    return _fov;
}

void cub::FreeCamera::SetFieldOfView(float v)
{
    _fov = v;
}

float cub::FreeCamera::AspectRatio()
{
    return _aspectRatio;
}

void cub::FreeCamera::SetAspectRatio(float v)
{
    _aspectRatio = v;
}

cub::FreeCamera::CamMode cub::FreeCamera::CameraMode()
{
    return _cameraMode;
}

void cub::FreeCamera::SetCameraMode(CamMode mode)
{
    _cameraMode = mode;
}
