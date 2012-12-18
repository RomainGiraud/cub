#ifndef CUB_SHADER_H
#define CUB_SHADER_H

#include <GL/gl_core.hpp>

#include <string>

namespace cub
{

class Shader
{
public:
    enum ShaderType
    {
        Vertex,
        //Geometry,
        Fragment
    };

    Shader(ShaderType type);
    void LoadFile(const std::string &filename);
    void LoadSource(const std::string &source);
    
    GLuint Id() const;

private:
    GLuint _id;
    ShaderType _type;

    void Compile(const char *src);
};

}

#endif /*CUB_SHADER_H*/