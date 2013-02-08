#ifndef CUB_PLANE_H
#define CUB_PLANE_H

#include <object/object.h>
#include <engine/buffer.h>
#include <engine/shader_program.h>

namespace cub
{

class Plane : public Object
{
public:
    Plane(Game *game);
    virtual ~Plane();

    virtual void Load();
    virtual void Update(double time);
    virtual void Render(double time);

    void SetTexture(GLuint textureID);
    
private:
	void UpdateSize();

    Buffer _indiceBuffer;
    Buffer _vertexBuffer;
    Buffer _normalBuffer;
    Buffer _textureBuffer;

    unsigned int _indiceLength;

    ShaderProgram *_shader;

    GLuint _textureID;
};
}

#endif /*CUB_PLANE_H*/