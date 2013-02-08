#include <geometry/ray.h>

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/constants.hpp>

#include <cmath>
#include <algorithm>
using namespace std;

cub::Ray::Ray()
{
}

cub::Ray::Ray(glm::vec3 origin, glm::vec3 direction, float maxDistance)
	: _origin(origin), _direction(direction), _maxDistance(maxDistance)
{
	//_direction = glm::normalize(_direction);
}

bool cub::Ray::Intersect(const Sphere& sphere, float *distance) const
{
	glm::vec3 l = sphere.GetCenter() - _origin;
	float s = glm::dot(l, _direction);
	float l2 = glm::dot(l, l);
	float r2 = sphere.GetRadius() * sphere.GetRadius();

	if (s < 0 && l2 > r2)
		return false;

	float m2 = l2 - (s * s);
	if (m2 > r2)
		return false;

	float q = sqrt(r2 - m2);
	float t = 0;
	if (l2 > r2)
		t = s - q;
	else
		t = s + q;

	if (distance != 0)
		*distance = t;

	return true;
}

bool cub::Ray::Intersect(const Box& box, float *distance) const
{
	float tmin = -1.0f / 0.0f;
	float tmax =  1.0f / 0.0f;

	glm::vec3 amin = box.GetMin();
	glm::vec3 amax = box.GetMax();

	for (int i = 0; i < 3; ++i)
	{
		if (std::abs(_direction[i]) < glm::epsilon<float>())
		{
			if (_origin[i] < amin[i] || _origin[i] > amax[i])
				return false;
		}
		else
		{
			float ood = 1.0f / _direction[i];
			float t1 = (amin[i] - _origin[i]) * ood;
			float t2 = (amax[i] - _origin[i]) * ood;

			if (t1 > t2)
			{
				float tmp = t1;
				t1 = t2;
				t2 = tmp;
			}

			tmin = max(t1, tmin);
			tmax = min(t2, tmax);

			if (tmin > tmax)
				return false;
		}
	}

	*distance = tmin;
	return true;
}