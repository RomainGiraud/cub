#ifndef CUB_CHUNK_H
#define CUB_CHUNK_H

#include <GL/gl_core.hpp>

#include <noise/noise.h>
#include "noise/noiseutils.h"

#include <engine/shader_program.h>
#include <engine/buffer.h>

namespace cub
{

class Game;

class Chunk
{
public:
    Chunk(Game *game);
    void Load(noise::utils::NoiseMap heightMap);
    void Render(double time);
    void Display();
    bool IsFilled(int x, int y, int z);

    glm::vec3 GetPosition() const;
    void SetPosition(glm::vec3 position);

    static int GetXLength();
    static int GetYLength();
    static int GetZLength();
    
private:
    static const int _xLength, _yLength, _zLength;

    Game *_game;
    int *_data;
    ShaderProgram *_shader;
    int _indiceLength;
    GLuint _textureID;
    glm::vec3 _position;

    Buffer _indiceBuffer;
    Buffer _vertexBuffer;
    Buffer _textureBuffer;
    Buffer _normalBuffer;
    Buffer _tangentBuffer;
    Buffer _bitangentBuffer;

    void Generate();
};
}

#endif /*CUB_CHUNK_H*/