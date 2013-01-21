#include <camera/bounding_sphere.h>
#include <camera/bounding_frustum.h>

cub::BoundingSphere::BoundingSphere()
{
}

bool cub::BoundingSphere::Intersects(BoundingFrustum *frustum)
{
    return false;
}