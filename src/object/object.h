#ifndef CUB_OBJECT_H
#define CUB_OBJECT_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

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

    virtual glm::quat GetRotation() const;
    virtual void SetRotation(const glm::quat& rotation);

    virtual glm::vec3 GetScale() const;
    virtual void SetScale(const glm::vec3& scale);


    virtual void Load() = 0;
    virtual void Update(double time) = 0;
    virtual void Render(double time) = 0;
    
protected:
	Game *_game;

	glm::vec3 _position;
	glm::quat _rotation;
	glm::vec3 _scale;
};
}

#endif /*CUB_OBJECT_H*/