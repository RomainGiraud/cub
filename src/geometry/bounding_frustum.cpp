#include <geometry/bounding_frustum.h>

#include <glm/gtc/type_ptr.hpp>

cub::BoundingFrustum::BoundingFrustum()
{
}

cub::ContainmentType cub::BoundingFrustum::Contains(const glm::vec3& point) const
{
    ContainmentType result = ContainmentType::Inside;

    for (int i = 0; i < 6; ++i)
    {
        if (_planes[i].Distance(point) < 0)
            return ContainmentType::Outside;
    }
    return result;
}

cub::ContainmentType cub::BoundingFrustum::Contains(const Sphere &sphere) const
{
    ContainmentType result = ContainmentType::Inside;

    for (int i = 0; i < 6; ++i)
    {
        float distance = _planes[i].Distance(sphere.GetCenter());
        if (distance < -sphere.GetRadius())
            return ContainmentType::Outside;
        else if (distance < sphere.GetRadius())
            result = ContainmentType::Intersect;
    }

    return result;
}

cub::ContainmentType cub::BoundingFrustum::Contains(const Box& box) const
{
    ContainmentType result = ContainmentType::Inside;
    int out, in;

    // for each plane do ...
    for (int i = 0; i < 6; ++i)
    {
        // reset counters for corners in and out
        out = 0;
        in = 0;

        // for each corner of the box do ...
        // get out of the cycle as soon as a box as corners
        // both inside and out of the frustum
        for (int k = 0; k < 8; ++k)
        //for (int k = 0; k < 8 && (in == 0 || out == 0); ++k)
        {
            // is the corner outside or inside
            if (_planes[i].Distance(box.GetCorner(k)) < 0)
                ++out;
            else
                ++in;
        }

        //if all corners are out
        if (!in)
            return ContainmentType::Outside;
        // if some corners are out and others are in
        else if (out)
            result = ContainmentType::Intersect;
    }

    return result;
}

void cub::BoundingFrustum::SetMatrix(const glm::mat4 &matrix)
{
    float a, b, c, d;

    // Left clipping plane
    a = matrix[0][3] + matrix[0][0];
    b = matrix[1][3] + matrix[1][0];
    c = matrix[2][3] + matrix[2][0];
    d = matrix[3][3] + matrix[3][0];
    _planes[0].SetValues(a,b,c,d);
    _planes[0].Normalize();
    
    // Right clipping plane
    a = matrix[0][3] - matrix[0][0];
    b = matrix[1][3] - matrix[1][0];
    c = matrix[2][3] - matrix[2][0];
    d = matrix[3][3] - matrix[3][0];
    _planes[1].SetValues(a,b,c,d);
    _planes[1].Normalize();
    
    // Top clipping plane
    a = matrix[0][3] - matrix[0][1];
    b = matrix[1][3] - matrix[1][1];
    c = matrix[2][3] - matrix[2][1];
    d = matrix[3][3] - matrix[3][1];
    _planes[2].SetValues(a,b,c,d);
    _planes[2].Normalize();
    
    // Bottom clipping plane
    a = matrix[0][3] + matrix[0][1];
    b = matrix[1][3] + matrix[1][1];
    c = matrix[2][3] + matrix[2][1];
    d = matrix[3][3] + matrix[3][1];
    _planes[3].SetValues(a,b,c,d);
    _planes[3].Normalize();
    
    // Near clipping plane
    a = matrix[0][3] + matrix[0][2];
    b = matrix[1][3] + matrix[1][2];
    c = matrix[2][3] + matrix[2][2];
    d = matrix[3][3] + matrix[3][2];
    _planes[4].SetValues(a,b,c,d);
    _planes[4].Normalize();
    
    // Far clipping plane
    a = matrix[0][3] - matrix[0][2];
    b = matrix[1][3] - matrix[1][2];
    c = matrix[2][3] - matrix[2][2];
    d = matrix[3][3] - matrix[3][2];
    _planes[5].SetValues(a,b,c,d);
    _planes[5].Normalize();
}