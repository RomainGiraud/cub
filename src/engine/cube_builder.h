#ifndef CUB_CUBEBUILDER_H
#define CUB_CUBEBUILDER_H

#include <vector>

namespace cub
{

class CubeBuilder
{
public:
    static const unsigned int Indices[36];
    static const float Vertices[24 * 3];
    static const float Normals[24 * 3];
    static const float TexCoords[24 * 2];
    static const float Tangents[24 * 3];
    static const float Bitangents[24 * 3];
    
    static std::vector<unsigned int> Build(bool yp, bool yn, bool xp, bool xn, bool zp, bool zn);
    
private:
};
}

#endif /*CUB_CUBEBUILDER_H*/