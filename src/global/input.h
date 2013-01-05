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

    void Update();

    bool IsMoving() const;
    glm::vec3 GetMovingVector() const;
    
private:
	Game *_game;
    bool _isMoving;
    glm::vec3 _move;
    char _forw, _backw, _rightw, _leftw;
};
}

#endif /*CUB_INPUT_H*/