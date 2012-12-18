#ifndef CUB_BUFFER_H
#define CUB_BUFFER_H

#include <GL/gl_core.hpp>

namespace cub
{

class Buffer
{
public:
    enum BufferType
    {
        Vertex,
        Index
    };

    Buffer(BufferType type);
    void Bind();
    void Attach(const void *data, size_t size);
    
private:
    BufferType _type;
    GLenum _target;
    GLenum _usage;
    GLuint _buffer;
};
}

#endif /*CUB_BUFFER_H*/