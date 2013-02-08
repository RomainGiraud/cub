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

    glm::vec3 GetDirection() const;
    void SetDirection(const glm::vec3& direction);

    glm::vec3 GetEnd() const;
    void SetEnd(const glm::vec3& end);

    void Load();
    void Update(double time);
    void Render(double time);
    
private:
    glm::vec3 _direction;

	void UpdateSize();

    Buffer _indiceBuffer;
    Buffer _vertexBuffer;

    unsigned int _indiceLength;

    ShaderProgram *_shader;


    glm::quat GetRotation() const;
    void SetRotation(const glm::quat& rotation);

    glm::vec3 GetScale() const;
    void SetScale(const glm::vec3& scale);
};
}

#endif /*CUB_CUBE_H*/