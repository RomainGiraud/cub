#include <engine/shader_program.h>

#include <global/exception.h>

#include <glm/gtc/type_ptr.hpp>

#include <iostream>
using namespace std;

cub::ShaderProgram::ShaderProgram()
{
    _id = gl::CreateProgram();
}

cub::ShaderProgram::~ShaderProgram()
{
    //glUseProgram(0);
}

void cub::ShaderProgram::AttachShader(const Shader &shader)
{
    gl::AttachShader(_id, shader.Id());
}

void cub::ShaderProgram::Bind()
{
    gl::UseProgram(_id);
}

void cub::ShaderProgram::Link()
{
    gl::LinkProgram(_id);

    GLint result;
    gl::GetProgramiv(_id, gl::LINK_STATUS, &result);
    if (!result)
    {
        char infoLog[1024];
        gl::GetProgramInfoLog(_id, 1024, NULL, infoLog);
        cout << "The program at " << _id
                << " failed to link with the following error:" << endl
                << infoLog << endl;
        gl::DeleteProgram(_id);
        throw Exception("", "createShaders", "glLinkProgram");
    }
}

int cub::ShaderProgram::UniformLocation(string name, bool exceptionOnError)
{
    int id = gl::GetUniformLocation(_id, name.c_str());

    if (id == -1)
    {
        if (!exceptionOnError)
            return id;

        throw Exception("Unknown uniform location \"" + name + "\"");
    }

    return id;
}

void cub::ShaderProgram::SetUniformValue(string name, int value, bool exceptionOnError)
{
    SetUniformValue(UniformLocation(name, exceptionOnError), value);
}

void cub::ShaderProgram::SetUniformValue(int location, int value)
{
    gl::Uniform1i(location, value);
}

void cub::ShaderProgram::SetUniformValue(string name, float value, bool exceptionOnError)
{
    SetUniformValue(UniformLocation(name, exceptionOnError), value);
}

void cub::ShaderProgram::SetUniformValue(int location, float value)
{
    gl::Uniform1f(location, value);
}

void cub::ShaderProgram::SetUniformValue(string name, glm::vec3 value, bool exceptionOnError)
{
    SetUniformValue(UniformLocation(name, exceptionOnError), value);
}

void cub::ShaderProgram::SetUniformValue(int location, glm::vec3 value)
{
    gl::Uniform3fv(location, 1, glm::value_ptr(value));
}

void cub::ShaderProgram::SetUniformValue(string name, glm::vec4 value, bool exceptionOnError)
{
    SetUniformValue(UniformLocation(name, exceptionOnError), value);
}

void cub::ShaderProgram::SetUniformValue(int location, glm::vec4 value)
{
    gl::Uniform4fv(location, 1, glm::value_ptr(value));
}

void cub::ShaderProgram::SetUniformValue(string name, glm::mat3 value, bool exceptionOnError)
{
    SetUniformValue(UniformLocation(name, exceptionOnError), value);
}

void cub::ShaderProgram::SetUniformValue(int location, glm::mat3 value)
{
    gl::UniformMatrix3fv(location, 1, false, glm::value_ptr(value));
}

void cub::ShaderProgram::SetUniformValue(string name, glm::mat4 value, bool exceptionOnError)
{
    SetUniformValue(UniformLocation(name, exceptionOnError), value);
}

void cub::ShaderProgram::SetUniformValue(int location, glm::mat4 value)
{
    gl::UniformMatrix4fv(location, 1, false, glm::value_ptr(value));
}

int cub::ShaderProgram::AttributeLocation(string name, bool exceptionOnError)
{
    int id = gl::GetAttribLocation(_id, name.c_str());

    if (id == -1)
    {
        if (!exceptionOnError)
            return id;
        
        throw Exception("Unknown attribute location \"" + name + "\"");
    }

    return id;
}

void cub::ShaderProgram::EnableVertexAttribArray(string name, bool exceptionOnError)
{
    EnableVertexAttribArray(AttributeLocation(name, exceptionOnError));
}

void cub::ShaderProgram::EnableVertexAttribArray(int location)
{
    gl::EnableVertexAttribArray(location);
}

void cub::ShaderProgram::DisableVertexAttribArray(string name, bool exceptionOnError)
{
    DisableVertexAttribArray(AttributeLocation(name, exceptionOnError));
}

void cub::ShaderProgram::DisableVertexAttribArray(int location)
{
    gl::DisableVertexAttribArray(location);
}

void cub::ShaderProgram::VertexAttribPointer(string name, int size, GLenum type, bool normalized, int stride, int offset, bool exceptionOnError)
{
    VertexAttribPointer(AttributeLocation(name, exceptionOnError), size, type, normalized, stride, offset);
}

void cub::ShaderProgram::VertexAttribPointer(int location, int size, GLenum type, bool normalized, int stride, int offset)
{
    gl::VertexAttribPointer(location, size, type, normalized, stride, reinterpret_cast<void*>(offset));
}