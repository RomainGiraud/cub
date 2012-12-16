#include <engine/chunk.h>
#include <engine/game.h>

#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>

#include <iostream>
#include <vector>
using namespace std;

cub::Chunk::Chunk(Game *game)
    : _indiceBuffer(Buffer::Index),
      _vertexBuffer(Buffer::Vertex),
      _textureBuffer(Buffer::Vertex),
      _normalBuffer(Buffer::Vertex),
      _tangentBuffer(Buffer::Vertex),
      _bitangentBuffer(Buffer::Vertex)
{
    _game = game;

    _xLength = 20;
    _yLength = 10;
    _zLength = 20;

    _data = new int[_xLength * _yLength * _zLength];
}

// x is the height, y is the width and z is the depth
// height + width * WIDTH + depth * WIDTH * DEPTH
//#define get(height,width,depth) _data[height + width * _xLength + depth * _xLength * _zLength]
inline int val(int y, int x, int z, int _xLength, int _zLength)
{
    return y * _xLength * _zLength + x * _zLength + z;
    //return (x + _xLength * (y + z * _zLength));
}
#define get(y,x,z) _data[val(y,x,z,_xLength,_zLength)]

void cub::Chunk::Display()
{
    for (int y = 0; y < _yLength; ++y)
    {
        cout << "--- Level: " << y << endl;
        for (int z = 0; z < _zLength; ++z)
        {
            for (int x = 0; x < _xLength; ++x)
            {
                cout << get(y, x, z) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void cub::Chunk::Load()
{
    _shader = _game->GetContent().LoadShaders("shaders/phong.vert", "shaders/phong.frag");

    for (int i = 0; i < _xLength * _yLength * _zLength; ++i)
    {
        _data[i] = 0;
    }

    
    for (int z = 0; z < _zLength; ++z)
    {
        for (int x = 0; x < _xLength; ++x)
        {
            get(9,x,z) = 1;
        }
    }
    
    for (int z = 0; z < _zLength; ++z)
    {
        get(8,0,z) = 2;
    }

    unsigned int indices[36] = {
        0, 1, 2,
        0, 2, 3,
        4, 5, 6,
        4, 6, 7,
        8, 9, 10,
        8, 10, 11,
        12, 13, 14,
        12, 14, 15,
        16, 17, 18,
        16, 18, 19,
        20, 21, 22,
        20, 22, 23,
    };
    float vertices[24 * 3] = {
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
    };
    float normals[24 * 3] = {
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, 1, 0,
        0, 1, 0,
        0, 1, 0,
        0, 1, 0,
        0, 0, 1,
        0, 0, 1,
        0, 0, 1,
        0, 0, 1,
        1, 0, 0,
        1, 0, 0,
        1, 0, 0,
        1, 0, 0,
        0, 0, -1,
        0, 0, -1,
        0, 0, -1,
        0, 0, -1,
        -1, 0, 0,
        -1, 0, 0,
        -1, 0, 0,
        -1, 0, 0,
    };
    float texcoords[24 * 2] = {
        1, 0,
        1, 1,
        0, 1,
        0, 0,
        0, 0,
        1, 0,
        1, 1,
        0, 1,
        0, 0,
        1, 0,
        1, 1,
        0, 1,
        0, 0,
        1, 0,
        1, 1,
        0, 1,
        0, 0,
        1, 0,
        1, 1,
        0, 1,
        0, 0,
        1, 0,
        1, 1,
        0, 1,
    };
    float tangents[24 * 3] = {
        -1, 0, 0,
        -1, 0, 0,
        -1, 0, 0,
        -1, 0, 0,
        1, 0, 0,
        1, 0, 0,
        1, 0, 0,
        1, 0, 0,
        1, 0, 0,
        1, 0, 0,
        1, 0, 0,
        1, 0, 0,
        0, 0, -1,
        0, 0, -1,
        0, 0, -1,
        0, 0, -1,
        -1, 0, 0,
        -1, 0, 0,
        -1, 0, 0,
        -1, 0, 0,
        0, 0, 1,
        0, 0, 1,
        0, 0, 1,
        0, 0, 1,
    };
    float bitangents[24 * 3] = {
        0, 0, 1,
        0, 0, 1,
        0, 0, 1,
        0, 0, 1,
        0, 0, 1,
        0, 0, 1,
        0, 0, 1,
        0, 0, 1,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
        0, -1, 0,
    };

    _indiceBuffer.Attach(indices, 36 * sizeof(unsigned int));
    _vertexBuffer.Attach(vertices, 72 * sizeof(float));
    _textureBuffer.Attach(texcoords, 48 * sizeof(float));
    _normalBuffer.Attach(normals, 72 * sizeof(float));
    _tangentBuffer.Attach(tangents, 72 * sizeof(float));
    _bitangentBuffer.Attach(bitangents, 72 * sizeof(float));

}

void cub::Chunk::Render(double time)
{
    glm::vec2 size = _game->GetSize();
    float aspectRatio = size.x / (float)(size.y);
    glm::mat4 projectionMatrix = _game->GetCamera().GetProjectionMatrix();
    glm::mat4 viewMatrix = _game->GetCamera().GetViewMatrix();

    _shader.Bind();
    _shader.SetUniformValue("Light.Position", viewMatrix * glm::vec4(0, -8, 0, 1));
    _shader.SetUniformValue("Light.La", glm::vec3(1, 1, 1));
    _shader.SetUniformValue("Light.Ld", glm::vec3(1, 1, 1));
    _shader.SetUniformValue("Light.Ls", glm::vec3(1, 1, 1));
    _shader.SetUniformValue("Material.Ka", glm::vec3(0.329412f, 0.223529f, 0.027451f));
    _shader.SetUniformValue("Material.Kd", glm::vec3(0.780392f, 0.568627f, 0.113725f));
    _shader.SetUniformValue("Material.Ks", glm::vec3(0.992157f, 0.941176f, 0.807843f));
    _shader.SetUniformValue("Material.Shininess", 27.89743616f);
    
    _shader.EnableVertexAttribArray("in_Position");
    _vertexBuffer.Bind();
    _shader.VertexAttribPointer("in_Position", 3, gl::FLOAT, false, 0, 0);

    _shader.EnableVertexAttribArray("in_TexCoord", false);
    _textureBuffer.Bind();
    _shader.VertexAttribPointer("in_TexCoord", 2, gl::FLOAT, false, 0, 0, false);

    _shader.EnableVertexAttribArray("in_Normal", false);
    _normalBuffer.Bind();
    _shader.VertexAttribPointer("in_Normal", 3, gl::FLOAT, false, 0, 0, false);

    _shader.EnableVertexAttribArray("in_Tangent", false);
    _tangentBuffer.Bind();
    _shader.VertexAttribPointer("in_Tangent", 3, gl::FLOAT, false, 0, 0, false);

    _shader.EnableVertexAttribArray("in_Bitangent", false);
    _bitangentBuffer.Bind();
    _shader.VertexAttribPointer("in_Bitangent", 3, gl::FLOAT, false, 0, 0, false);

    _indiceBuffer.Bind();
    
    for (int y = 0; y < _yLength; ++y)
    {
        for (int z = 0; z < _zLength; ++z)
        {
            for (int x = 0; x < _xLength; ++x)
            {
                if (get(y,x,z) == 0) continue;

                glm::mat4 modelMatrix = glm::translate(glm::vec3(x-10, -y, z-10));

                glm::mat4 mvMatrix = viewMatrix * modelMatrix;
                glm::mat4 mvpMatrix = projectionMatrix * mvMatrix;
                glm::mat3 normalMatrix = glm::inverseTranspose(glm::mat3(mvMatrix));

                _shader.Bind();
                _shader.SetUniformValue("mvMatrix", mvMatrix);
                _shader.SetUniformValue("mvpMatrix", mvpMatrix);
                _shader.SetUniformValue("normalMatrix", normalMatrix);
                
                gl::DrawElements(gl::TRIANGLES, 36, gl::UNSIGNED_INT, 0);
            }
        }
    }
}