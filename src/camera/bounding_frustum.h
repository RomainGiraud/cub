#ifndef CUB_BOUNDINGFRUSTUM_H
#define CUB_BOUNDINGFRUSTUM_H

#include <GL/gl_core.hpp>

#include <glm/glm.hpp>

#include <camera/plane.h>
#include <camera/sphere.h>

namespace cub
{

enum class ContainmentType
{
    Intersect,
    Outside,
    Inside
};

class BoundingFrustum
{
public:
    
    BoundingFrustum();
    void SetMatrix(const glm::mat4 &matrix);
    
    ContainmentType Contains(const glm::vec3& point);
    ContainmentType Contains(const Sphere& sphere);
    ContainmentType Contains(const Plane& plane);
    
private:
    Plane _planes[6];
};
}

#endif /*CUB_BOUNDINGBOX_H*/