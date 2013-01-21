#ifndef CUB_BOUNDINGBOX_H
#define CUB_BOUNDINGBOX_H

#include <GL/gl_core.hpp>

namespace cub
{

class BoundingFrustum;

class BoundingBox
{
public:
    BoundingBox();
    bool Intersects(BoundingFrustum *frustum);
    
private:
};
}

#endif /*CUB_BOUNDINGBOX_H*/