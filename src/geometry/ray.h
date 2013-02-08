#ifndef CUB_RAY_H
#define CUB_RAY_H

#include <glm/glm.hpp>

#include <geometry/plane.h>
#include <geometry/box.h>
#include <geometry/sphere.h>

namespace cub
{

class Ray
{
public:
    Ray();
    Ray(glm::vec3 origin, glm::vec3 direction, float maxDistance = 1.0f / 0.0f);

    bool Intersect(const Sphere& sphere, float *distance = 0) const;
    bool Intersect(const Box& box, float *distance = 0) const;
    
private:
	glm::vec3 _origin;
	glm::vec3 _direction;
	glm::vec3 _maxDistance;
};
}

#endif /*CUB_RAY_H*/