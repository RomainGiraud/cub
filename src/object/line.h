#ifndef CUB_LINE_H
#define CUB_LINE_H

#include <object/object.h>

#include <engine/shader_program.h>
#include <engine/buffer.h>

namespace cub
{

class Line : public Object
{
public:
    Line(Game *game, glm::vec3 direction = glm::vec3(0,0,0));
    virtual ~Line();

    float GetSize() const;
    void SetSize(float size);

    glm::vec3 GetDirection() const;
    void SetDirection(const glm::vec3& direction);

    glm::vec3 GetEnd() const;
    void SetEnd(const glm::vec3& end);

    void Load();
    void Update(double time);
    void Render(double time);
    
private:
    glm::vec3 _direction;
	float _size;

	void UpdateSize();

    Buffer _indiceBuffer;
    Buffer _vertexBuffer;

    unsigned int _indiceLength;

    ShaderProgram *_shader;
};
}

#endif /*CUB_CUBE_H*/