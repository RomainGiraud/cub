#ifndef CUB_SHADERPROGRAM_H
#define CUB_SHADERPROGRAM_H

#include <GL/gl_core_3_3.hpp>

#include <engine/shader.h>

#include <string>

#include <glm/glm.hpp>

namespace cub
{

class ShaderProgram
{
public:
    ShaderProgram();
    ~ShaderProgram();
    void AttachShader(const Shader &shader);
    void Bind();
    void Link();

    int UniformLocation(std::string name, bool exceptionOnError);
    void SetUniformValue(std::string name, int value, bool exceptionOnError = true);
    void SetUniformValue(int location, int value);
    void SetUniformValue(std::string name, float value, bool exceptionOnError = true);
    void SetUniformValue(int location, float value);
    void SetUniformValue(std::string name, glm::vec3 value, bool exceptionOnError = true);
    void SetUniformValue(int location, glm::vec3 value);
    void SetUniformValue(std::string name, glm::vec4 value, bool exceptionOnError = true);
    void SetUniformValue(int location, glm::vec4 value);
    void SetUniformValue(std::string name, glm::mat3 value, bool exceptionOnError = true);
    void SetUniformValue(int location, glm::mat3 value);
    void SetUniformValue(std::string name, glm::mat4 value, bool exceptionOnError = true);
    void SetUniformValue(int location, glm::mat4 value);
    
    int AttributeLocation(std::string name, bool exceptionOnError);
    void EnableVertexAttribArray(std::string name, bool exceptionOnError = true);
    void EnableVertexAttribArray(int location);
    void DisableVertexAttribArray(std::string name, bool exceptionOnError = true);
    void DisableVertexAttribArray(int location);
    void VertexAttribPointer(std::string name, int size, GLenum type, bool normalized, int stride, int offset, bool exceptionOnError = true);
    void VertexAttribPointer(int location, int size, GLenum type, bool normalized, int stride, int offset);

private:
    GLuint _id;
};

}

#endif /*CUB_SHADERPROGRAM_H*/