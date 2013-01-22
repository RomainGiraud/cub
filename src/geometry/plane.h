#ifndef CUB_PLANE_H
#define CUB_PLANE_H

#include <glm/glm.hpp>

namespace cub
{

class Plane
{
public:
    Plane();
    Plane(float a, float b, float c, float d);

    void SetValues(float a, float b, float c, float d);
    void Normalize();
    
    float Distance(const glm::vec3 &point) const;
    
private:
    float _a, _b, _c, _d;
};
}

#endif /*CUB_PLANE_H*/