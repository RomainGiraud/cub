#include <camera/sphere.h>

cub::Sphere::Sphere()
    : _center(0, 0, 0), _radius(1)
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