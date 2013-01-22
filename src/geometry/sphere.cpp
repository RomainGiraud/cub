#include <geometry/sphere.h>

cub::Sphere::Sphere()
{
}

cub::Sphere::Sphere(glm::vec3 center, float radius)
    : _center(center), _radius(radius)
{
}

glm::vec3 cub::Sphere::GetCenter() const
{
    return _center;
}

float cub::Sphere::GetRadius() const
{
    return _radius;
}