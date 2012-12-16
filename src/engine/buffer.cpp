#include <engine/buffer.h>

cub::Buffer::Buffer(BufferType type)
{
    _type = type;
    switch (_type)
    {
        case Vertex:
            _target = gl::ARRAY_BUFFER;
            break;
        case Index:
            _target = gl::ELEMENT_ARRAY_BUFFER;
            break;
    }
    _usage = gl::STATIC_DRAW;

    gl::GenBuffers(1, &_buffer);
}

void cub::Buffer::Bind()
{
    gl::BindBuffer(_target, _buffer);
}

void cub::Buffer::Attach(const void *data, size_t size)
{
    Bind();
    gl::BufferData(_target, size, data, _usage);
}