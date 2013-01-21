#ifndef CUB_BOX_H
#define CUB_BOX_H

#include <glm/glm.hpp>

namespace cub
{

class Box
{
public:
    Box();
    Box(glm::vec3 cornerTopLeftNear, glm::vec3 size);
    glm::vec3 GetVertex(int i) const;
    
private:
	glm::vec3 _cornerTopLeftNear;
	glm::vec3 _size;
};
}

#endif /*CUB_BOX_H*/