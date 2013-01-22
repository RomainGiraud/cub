#ifndef CUB_BOX_H
#define CUB_BOX_H

#include <glm/glm.hpp>

namespace cub
{

class Box
{
public:
    Box();
    Box(const glm::vec3& cornerMin, const glm::vec3& cornerMax);
    glm::vec3 GetCorner(int i) const;
    glm::vec3 GetCenter() const;
    glm::vec3 GetMin() const;
    glm::vec3 GetMax() const;
    
private:
	glm::vec3 _cornerMin;
	glm::vec3 _cornerMax;
	glm::vec3 _center;
};
}

#endif /*CUB_BOX_H*/