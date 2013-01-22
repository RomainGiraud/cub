#ifndef CUB_OBJECT_H
#define CUB_OBJECT_H

#include <glm/glm.hpp>

namespace cub
{

class Game;

class Object
{
public:
    Object(Game *game);
    virtual ~Object();

    virtual glm::vec3 GetPosition() const;
    virtual void SetPosition(const glm::vec3& position);

    virtual void Load() = 0;
    virtual void Update(double time) = 0;
    virtual void Render(double time) = 0;
    
protected:
	Game *_game;

	glm::vec3 _position;
};
}

#endif /*CUB_OBJECT_H*/