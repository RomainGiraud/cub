#include <camera/bounding_frustum.h>

cub::BoundingFrustum::BoundingFrustum()
{
}

cub::ContainmentType cub::BoundingFrustum::Contains(const glm::vec3& point)
{
    ContainmentType result = ContainmentType::Inside;

	for (int i = 0; i < 6; ++i)
    {
		if (_planes[i].Distance(point) < 0)
			return ContainmentType::Outside;
	}
	return result;
}

cub::ContainmentType cub::BoundingFrustum::Contains(const Sphere &sphere)
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

cub::ContainmentType cub::BoundingFrustum::Contains(const Plane& plane)
{
    return ContainmentType::Outside;
}

void cub::BoundingFrustum::SetMatrix(const glm::mat4 &matrix)
{
    float a, b, c, d;
    
    // Left clipping plane
    a = matrix[4][1] + matrix[1][1];
    b = matrix[4][2] + matrix[1][2];
    c = matrix[4][3] + matrix[1][3];
    d = matrix[4][4] + matrix[1][4];
    _planes[0].SetValues(a,b,c,d);
    _planes[0].Normalize();
    
    // Right clipping plane
    a = matrix[4][1] - matrix[1][1];
    b = matrix[4][2] - matrix[1][2];
    c = matrix[4][3] - matrix[1][3];
    d = matrix[4][4] - matrix[1][4];
    _planes[1].SetValues(a,b,c,d);
    _planes[1].Normalize();
    
    // Top clipping plane
    a = matrix[4][1] - matrix[2][1];
    b = matrix[4][2] - matrix[2][2];
    c = matrix[4][3] - matrix[2][3];
    d = matrix[4][4] - matrix[2][4];
    _planes[2].SetValues(a,b,c,d);
    _planes[2].Normalize();
    
    // Bottom clipping plane
    a = matrix[4][1] + matrix[2][1];
    b = matrix[4][2] + matrix[2][2];
    c = matrix[4][3] + matrix[2][3];
    d = matrix[4][4] + matrix[2][4];
    _planes[3].SetValues(a,b,c,d);
    _planes[3].Normalize();
    
    // Near clipping plane
    a = matrix[4][1] + matrix[3][1];
    b = matrix[4][2] + matrix[3][2];
    c = matrix[4][3] + matrix[3][3];
    d = matrix[4][4] + matrix[3][4];
    _planes[4].SetValues(a,b,c,d);
    _planes[4].Normalize();
    
    // Far clipping plane
    a = matrix[4][1] - matrix[3][1];
    b = matrix[4][2] - matrix[3][2];
    c = matrix[4][3] - matrix[3][3];
    d = matrix[4][4] - matrix[3][4];
    _planes[5].SetValues(a,b,c,d);
    _planes[5].Normalize();
}