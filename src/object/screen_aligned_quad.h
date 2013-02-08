#ifndef CUB_SCREENALIGNEDQUAD_H
#define CUB_SCREENALIGNEDQUAD_H

#include <object/plane.h>

namespace cub
{

class ScreenAlignedQuad : public Object
{
public:
    ScreenAlignedQuad(Game *game);
    virtual ~ScreenAlignedQuad();

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

#endif /*CUB_SCREENALIGNEDQUAD_H*/