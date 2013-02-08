#ifndef CUB_CONTENT_H
#define CUB_CONTENT_H

#include <engine/shader_program.h>

#include <string>
#include <map>

namespace cub
{

class Content
{
public:
    Content();
    Content(std::string path);
    ~Content();
    int LoadTexture(std::string filename);
    int LoadDDSTexture(std::string filename);
    int LoadSkyBox(std::string filename);
    ShaderProgram* LoadShaders(std::string fileVert, std::string fileFrag);
    //ShaderProgram LoadShaders(std::string fileVert, std::string fileGeom, std::string fileFrag);
    std::string GetPath() const;
    
protected:
    std::string _path;
    std::map<std::string, ShaderProgram*> _cachedShaders;
    std::map<std::string, int> _cachedTextures;
    void LoadCubeMap(GLenum target, std::string filename);
};

}

#endif /*CUB_CONTENT_H*/