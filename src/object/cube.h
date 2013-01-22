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
    Cube(Game *game, float size = 1);
    virtual ~Cube();

    float GetSize() const;
    void SetSize(float size);

    void Load();
    void Update(double time);
    void Render(double time);
    
private:
	bool _isWireframe;
	float _size;

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