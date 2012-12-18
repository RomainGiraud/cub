#include <engine/shader.h>

#include <global/exception.h>

#include <string>
#include <fstream>
using namespace std;

cub::Shader::Shader(ShaderType type)
{
    _type = type;

    GLenum typeSh;
    switch (_type)
    {
        case Vertex:
            typeSh = gl::VERTEX_SHADER;
            break;
        // No gemetry shader in OpenGL 2.x
        //case Geometry:
        //    typeSh = gl::GEOMETRY_SHADER;
        //    break;
        case Fragment:
            typeSh = gl::FRAGMENT_SHADER;
            break;
    }
    _id = gl::CreateShader(typeSh);
}


void cub::Shader::LoadFile(const string &filename)
{
    ifstream fs (filename.c_str());
    if (!fs)
        throw Exception("", "loadFile", "file \"" + filename + "\" doesn't exist");
    
    filebuf *pbuf = fs.rdbuf();
    
    long size = pbuf->pubseekoff(0, ios::end, ios::in);
    pbuf->pubseekpos(0, ios::in);
    
    char *src = new char[size+1];
    long ss = pbuf->sgetn(src, size);
    fs.close();
    src[ss] = '\0';
        
    Compile(src);

    delete[] src;
}

void cub::Shader::LoadSource(const string &source)
{
    Compile(source.c_str());
}

void cub::Shader::Compile(const char *src)
{
    gl::ShaderSource(_id, 1, &src, NULL);
    gl::CompileShader(_id);

    GLint result;
    gl::GetShaderiv(_id, gl::COMPILE_STATUS, &result);
    if (!result)
    {
        char infoLog[1024];
        gl::GetShaderInfoLog(_id, 1024, NULL, infoLog);
        cout << "The shader at " << _id
                << " failed to compile with the following error:" << endl
                << infoLog << endl;
        gl::DeleteShader(_id);
        throw Exception("", "compileShader", "glCompileShader");
    }
}

GLuint cub::Shader::Id() const
{
    return _id;
}