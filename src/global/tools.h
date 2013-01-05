#ifndef CUB_TOOLS_H
#define CUB_TOOLS_H

#include <iostream>
#include <glm/glm.hpp>

namespace cub
{

//template<typename T>
inline float clamp(const float &val, const float &min, const float &max)
{
	return std::min(max, std::max(min, val));
}

inline std::ostream& operator<<(std::ostream& os, const glm::mat4 &m)
{
    return os << m[0][0] << " | " << m[1][0] << " | " << m[2][0] << " | " << m[3][0] << std::endl
              << m[0][1] << " | " << m[1][1] << " | " << m[2][1] << " | " << m[3][1] << std::endl
              << m[0][2] << " | " << m[1][2] << " | " << m[2][2] << " | " << m[3][2] << std::endl
              << m[0][3] << " | " << m[1][3] << " | " << m[2][3] << " | " << m[3][3] << std::endl;
}

inline std::ostream& operator<<(std::ostream& os, const glm::vec3 &v)
{
    return os << v[0] << ", " << v[1] << ", " << v[2];
}

inline std::ostream& operator<<(std::ostream& os, const glm::vec4 &v)
{
    return os << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3];
}

}

#endif /*CUB_TOOLS_H*/
