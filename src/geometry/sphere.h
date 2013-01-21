#ifndef CUB_SPHERE_H
#define CUB_SPHERE_H

#include <glm/glm.hpp>

namespace cub
{

class Sphere
{
public:
    Sphere();
    Sphere(glm::vec3 center, float radius);

    glm::vec3 GetCenter() const;
    float GetRadius() const;
    
private:
    glm::vec3 _center;
    float _radius;
};
}

#endif /*CUB_SPHERE_H*/