#ifndef CUB_CHUNK_H
#define CUB_CHUNK_H

#include <GL/gl_core_3_3.hpp>

#include <engine/shader_program.h>
#include <engine/buffer.h>

namespace cub
{

class Game;

class Chunk
{
public:
    Chunk(Game *game);
    void Load();
    void Render(double time);
    void Display();
    
private:
    Game *_game;
    int _xLength, _yLength, _zLength;
    int *_data;
    ShaderProgram _shader;

    Buffer _indiceBuffer;
    Buffer _vertexBuffer;
    Buffer _textureBuffer;
    Buffer _normalBuffer;
    Buffer _tangentBuffer;
    Buffer _bitangentBuffer;
};
}

#endif /*CUB_CHUNK_H*/