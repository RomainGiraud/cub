#ifndef CUB_CUBE_H
#define CUB_CUBE_H

#include <object/object.h>

#include <engine/shader_program.h>
#include <engine/buffer.h>

namespace cub
{

class Cube : public Object
{
public:
    Cube(Game *game);
    virtual ~Cube();

    void Load();
    void Update(double time);
    void Render(double time);
    
private:
	bool _isWireframe;

	void UpdateSize();
	void UpdateSizeWireframe();
	void UpdateSizePlain();
	
    void RenderWireframe(double time);
    void RenderPlain(double time);

    Buffer _indiceBuffer;
    Buffer _vertexBuffer;
    Buffer _normalBuffer;

    unsigned int _indiceLength;

    ShaderProgram *_shader;
};
}

#endif /*CUB_CUBE_H*/