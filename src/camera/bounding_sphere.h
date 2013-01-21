#ifndef CUB_BOUNDINGSPHERE_H
#define CUB_BOUNDINGSPHERE_H

#include <GL/gl_core.hpp>

namespace cub
{

class BoundingFrustum;

class BoundingSphere
{
public:
    BoundingSphere();
    bool Intersects(BoundingFrustum *frustum);
    
private:
};
}

#endif /*CUB_BOUNDINGSPHERE_H*/