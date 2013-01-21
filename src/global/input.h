#ifndef CUB_INPUT_H
#define CUB_INPUT_H

#include <glm/glm.hpp>

namespace cub
{

class Game;

class Input
{
public:
    Input(Game *game);

    void KeyChanged(int key, int action);
    void Update();

    bool IsMoving() const;
    glm::vec3 GetMovingVector() const;

	bool RenderWireframe() const;
    
private:
	Game *_game;
    
    bool _isMoving;
    glm::vec3 _move;
    char _forw, _backw, _rightw, _leftw;

    bool _renderWireframe;
    char _toggleWire;
};
}

#endif /*CUB_INPUT_H*/