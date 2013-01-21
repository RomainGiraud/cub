#include <camera/box.h>

cub::Box::Box()
{
}

cub::Box::Box(glm::vec3 cornerTopLeftNear, glm::vec3 size)
	: _cornerTopLeftNear(cornerTopLeftNear), _size(size)
{
}

glm::vec3 cub::Box::GetVertex(int i) const
{
	switch (i)
	{
		default:
		case 0:
			return _cornerTopLeftNear;
		case 1:
			return _cornerTopLeftNear + glm::vec3(_size.x, 0, 0);
		case 2:
			return _cornerTopLeftNear + glm::vec3(0, _size.y, 0);
		case 3:
			return _cornerTopLeftNear + glm::vec3(0, 0, _size.z);
		case 4:
			return _cornerTopLeftNear + glm::vec3(_size.x, _size.y, 0);
		case 5:
			return _cornerTopLeftNear + glm::vec3(0, _size.y, _size.z);
		case 6:
			return _cornerTopLeftNear + glm::vec3(_size.x, 0, _size.z);
		case 7:
			return _cornerTopLeftNear + glm::vec3(_size.x, _size.y, _size.z);
	}
}