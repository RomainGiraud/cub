#ifndef CUB_SHADERPROGRAM_H
#define CUB_SHADERPROGRAM_H

#include <GL/gl_core.hpp>

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

    int UniformLocation(const std::string& name, bool exceptionOnError);
    void SetUniformValue(const std::string& name, int value, bool exceptionOnError = true);
    void SetUniformValue(int location, int value);
    void SetUniformValue(const std::string& name, float value, bool exceptionOnError = true);
    void SetUniformValue(int location, float value);
    void SetUniformValue(const std::string& name, const glm::vec3& value, bool exceptionOnError = true);
    void SetUniformValue(int location, const glm::vec3& value);
    void SetUniformValue(const std::string& name, const glm::vec4& value, bool exceptionOnError = true);
    void SetUniformValue(int location, const glm::vec4& value);
    void SetUniformValue(const std::string& name, const glm::mat3& value, bool exceptionOnError = true);
    void SetUniformValue(int location, const glm::mat3& value);
    void SetUniformValue(const std::string& name, const glm::mat4& value, bool exceptionOnError = true);
    void SetUniformValue(int location, const glm::mat4& value);
    
    int AttributeLocation(const std::string& name, bool exceptionOnError);
    void EnableVertexAttribArray(const std::string& name, bool exceptionOnError = true);
    void EnableVertexAttribArray(int location);
    void DisableVertexAttribArray(const std::string& name, bool exceptionOnError = true);
    void DisableVertexAttribArray(int location);
    void VertexAttribPointer(const std::string& name, int size, GLenum type, bool normalized, int stride, int offset, bool exceptionOnError = true);
    void VertexAttribPointer(int location, int size, GLenum type, bool normalized, int stride, int offset);

private:
    GLuint _id;
};

}

#endif /*CUB_SHADERPROGRAM_H*/