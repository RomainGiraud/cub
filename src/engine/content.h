#ifndef CUB_CONTENT_H
#define CUB_CONTENT_H

#include <engine/shader_program.h>

#include <string>

namespace cub
{

class Content
{
public:
    Content();
    Content(std::string path);
    int LoadTexture(std::string filename);
    int LoadSkyBox(std::string filename);
    ShaderProgram LoadShaders(std::string fileVert, std::string fileFrag);
    ShaderProgram LoadShaders(std::string fileVert, std::string fileGeom, std::string fileFrag);
    
protected:
    std::string _path;
    void LoadCubeMap(GLenum target, std::string filename);
};

}

#endif /*CUB_CONTENT_H*/