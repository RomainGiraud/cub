#include <camera/bounding_box.h>
#include <camera/bounding_frustum.h>

cub::BoundingBox::BoundingBox()
{
}

bool cub::BoundingBox::Intersects(BoundingFrustum *frustum)
{
    return false;
}