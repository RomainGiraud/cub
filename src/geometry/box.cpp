#include <geometry/box.h>
#include <global/exception.h>

cub::Box::Box()
{
}

cub::Box::Box(const glm::vec3& cornerMin, const glm::vec3& cornerMax)
	: _cornerMin(cornerMin), _cornerMax(cornerMax)
{
	_center = _cornerMin + (_cornerMax - _cornerMin) / 2.0f;
}

glm::vec3 cub::Box::GetCorner(int i) const
{
	switch (i)
	{
		case 0:
			return glm::vec3(_cornerMin.x, _cornerMax.y, _cornerMax.z);
		case 1:
			return glm::vec3(_cornerMax.x, _cornerMax.y, _cornerMax.z);
		case 2:
			return glm::vec3(_cornerMax.x, _cornerMin.y, _cornerMax.z);
		case 3:
			return glm::vec3(_cornerMin.x, _cornerMin.y, _cornerMax.z);
		case 4:
			return glm::vec3(_cornerMin.x, _cornerMax.y, _cornerMin.z);
		case 5:
			return glm::vec3(_cornerMax.x, _cornerMax.y, _cornerMin.z);
		case 6:
			return glm::vec3(_cornerMax.x, _cornerMin.y, _cornerMin.z);
		case 7:
			return glm::vec3(_cornerMin.x, _cornerMin.y, _cornerMin.z);
		default:
			throw Exception("[Box] invalid id corner");
	}
}

glm::vec3 cub::Box::GetCenter() const
{
	return _center;
}

glm::vec3 cub::Box::GetMin() const
{
	return _cornerMin;
}

glm::vec3 cub::Box::GetMax() const
{
	return _cornerMax;
}