#include <global/input.h>
#include <engine/game.h>

#define GLFW_NO_GLU
#include <GL/glfw.h>

using namespace std;

cub::Input::Input(Game *game)
	: _game(game), _isMoving(false), _renderWireframe(false)
{
    _forw = _game->GetSettings().GetForward();
    _backw = _game->GetSettings().GetBackward();
    _rightw = _game->GetSettings().GetRightward();
    _leftw = _game->GetSettings().GetLeftward();

    _toggleWire = _game->GetSettings().GetToggleWireframe();
}

void cub::Input::KeyChanged(int key, int action)
{
    if (key == _toggleWire && action == GLFW_PRESS)
    {
        _renderWireframe = !_renderWireframe;
    }
}

void cub::Input::Update()
{
    _isMoving = false;
    _move = glm::vec3(0.f);

    if (glfwGetKey(_forw) == GLFW_PRESS)
    {
        _move.z = -1;
        _isMoving = true;
    }
    else if (glfwGetKey(_backw) == GLFW_PRESS)
    {
        _move.z = +1;
        _isMoving = true;
    }
    
    if (glfwGetKey(_leftw) == GLFW_PRESS)
    {
        _move.x = -1;
        _isMoving = true;
    }
    else if (glfwGetKey(_rightw) == GLFW_PRESS)
    {
        _move.x = +1;
        _isMoving = true;
    }

    _move = glm::normalize(_move);
}

bool cub::Input::IsMoving() const
{
	return _isMoving;
}

glm::vec3 cub::Input::GetMovingVector() const
{
	return _move;
}

bool cub::Input::RenderWireframe() const
{
    return _renderWireframe;
}