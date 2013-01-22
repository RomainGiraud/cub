#include <geometry/plane.h>

#include <cmath>
using namespace std;

cub::Plane::Plane()
    : _a(0), _b(0), _c(0), _d(0)
{
}

cub::Plane::Plane(float a, float b, float c, float d)
    : _a(a), _b(b), _c(c), _d(d)
{
}

void cub::Plane::SetValues(float a, float b, float c, float d)
{
    _a = a;
    _b = b;
    _c = c;
    _d = d;
}

void cub::Plane::Normalize()
{
    float mag = sqrt(_a * _a + _b * _b + _c * _c);
    _a = _a / mag;
    _b = _b / mag;
    _c = _c / mag;
    _d = _d / mag;
}

float cub::Plane::Distance(const glm::vec3 &point) const
{
    return _d + glm::dot(glm::vec3(_a, _b, _c), point);
}