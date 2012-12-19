#include <engine/chunk.h>
#include <engine/game.h>
#include <engine/cube_builder.h>
#include <global/tools.h>

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

    _xLength = 200;
    _yLength = 10;
    _zLength = 200;

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
            get(0,x,z) = 1;
        }
    }
    
    for (int z = 0; z < _zLength; ++z)
    {
        get(1,0,z) = 2;
    }

    Generate();
}

void cub::Chunk::Generate()
{
    vector< vector<int> > positions;
    vector<unsigned int> indices;
    for (int y = 0; y < _yLength; ++y)
    {
        for (int z = 0; z < _zLength; ++z)
        {
            for (int x = 0; x < _xLength; ++x)
            {
                if (!IsFilled(x,y,z)) continue;

                bool yp = !IsFilled(x,y+1,z);
                bool yn = !IsFilled(x,y-1,z);
                bool xp = !IsFilled(x+1,y,z);
                bool xn = !IsFilled(x-1,y,z);
                bool zp = !IsFilled(x,y,z+1);
                bool zn = !IsFilled(x,y,z-1);

                vector<unsigned int> current = CubeBuilder::Build(yp, yn, xp, xn, zp, zn);
                indices.insert(indices.end(), current.begin(), current.end());

                for (int i = 0; i < current.size(); ++i)
                {
                    vector<int> tmp;
                    tmp.push_back(x);
                    tmp.push_back(y);
                    tmp.push_back(z);

                    positions.push_back(tmp);
                }
            }
        }
    }

    vector<float> vertices;
    vertices.reserve(indices.size() * 3 * 4 / 6.f);
    vector<float> texcoords;
    texcoords.reserve(indices.size() * 2 * 4 / 6.f);
    vector<float> normals;
    normals.reserve(indices.size() * 3 * 4 / 6.f);
    vector<float> tangents;
    tangents.reserve(indices.size() * 3 * 4 / 6.f);
    vector<float> bitangents;
    bitangents.reserve(indices.size() * 3 * 4 / 6.f);

    unsigned int offset = 0;
    for (vector<unsigned int>::iterator it = indices.begin(); it != indices.end(); it += 6, offset += 6)
    {
        int id[4] = { *(it+0), *(it+1), *(it+2), *(it+5) };

        for (int i = 0; i < 4; ++i)
        {
            vertices.push_back((CubeBuilder::Vertices[id[i] * 3 + 0]) + positions[offset][0]);
            vertices.push_back((CubeBuilder::Vertices[id[i] * 3 + 1]) + positions[offset][1]);
            vertices.push_back((CubeBuilder::Vertices[id[i] * 3 + 2]) + positions[offset][2]);

            texcoords.push_back(CubeBuilder::TexCoords[id[i] * 2 + 0]);
            texcoords.push_back(CubeBuilder::TexCoords[id[i] * 2 + 1]);
            
            normals.push_back(CubeBuilder::Normals[id[i] * 3 + 0]);
            normals.push_back(CubeBuilder::Normals[id[i] * 3 + 1]);
            normals.push_back(CubeBuilder::Normals[id[i] * 3 + 2]);
            
            tangents.push_back(CubeBuilder::Tangents[id[i] * 3 + 0]);
            tangents.push_back(CubeBuilder::Tangents[id[i] * 3 + 1]);
            tangents.push_back(CubeBuilder::Tangents[id[i] * 3 + 2]);
            
            bitangents.push_back(CubeBuilder::Bitangents[id[i] * 3 + 0]);
            bitangents.push_back(CubeBuilder::Bitangents[id[i] * 3 + 1]);
            bitangents.push_back(CubeBuilder::Bitangents[id[i] * 3 + 2]);
        }
    }

    offset = 0;
    for (vector<unsigned int>::iterator it = indices.begin(); it != indices.end(); it += 6, ++offset)
    {
        *(it + 0) = 0 + offset * 4;
        *(it + 1) = 1 + offset * 4;
        *(it + 2) = 2 + offset * 4;
        *(it + 3) = 0 + offset * 4;
        *(it + 4) = 2 + offset * 4;
        *(it + 5) = 3 + offset * 4;
    }

    _indiceBuffer.Attach(indices.data(), indices.size() * sizeof(unsigned int));
    _vertexBuffer.Attach(vertices.data(), vertices.size() * sizeof(float));
    _textureBuffer.Attach(texcoords.data(), texcoords.size() * sizeof(float));
    _normalBuffer.Attach(normals.data(), normals.size() * sizeof(float));
    _tangentBuffer.Attach(tangents.data(), tangents.size() * sizeof(float));
    _bitangentBuffer.Attach(bitangents.data(), bitangents.size() * sizeof(float));

    _indiceLength = indices.size();
}

bool cub::Chunk::IsFilled(int x, int y, int z)
{
    if (x < 0 || x >= _xLength) return false;
    if (y < 0 || y >= _yLength) return false;
    if (z < 0 || z >= _zLength) return false;

    return get(y,x,z) != 0;
}


void cub::Chunk::Render(double time)
{
    glm::vec2 size = _game->GetSize();
    float aspectRatio = size.x / (float)(size.y);
    glm::mat4 projectionMatrix = _game->GetCamera().GetProjectionMatrix();
    glm::mat4 viewMatrix = _game->GetCamera().GetViewMatrix();
    //glm::mat4 viewMatrix = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    glm::mat4 modelMatrix = glm::mat4(1.0f);

    glm::mat4 mvMatrix = viewMatrix * modelMatrix;
    glm::mat4 mvpMatrix = projectionMatrix * mvMatrix;
    glm::mat3 normalMatrix = glm::inverseTranspose(glm::mat3(mvMatrix));

    _shader.Bind();
    _shader.SetUniformValue("mvMatrix", mvMatrix);
    _shader.SetUniformValue("mvpMatrix", mvpMatrix);
    _shader.SetUniformValue("normalMatrix", normalMatrix);
    _shader.SetUniformValue("Light.Position", viewMatrix * glm::vec4(0, 3, 0, 1));
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
    
    gl::DrawElements(gl::TRIANGLES, _indiceLength, gl::UNSIGNED_INT, 0);

    /*
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
                
                gl::DrawElements(gl::TRIANGLES, 6, gl::UNSIGNED_INT, (void*)(30 * sizeof(unsigned int)));
                //gl::DrawElements(gl::TRIANGLES, 36, gl::UNSIGNED_INT, 0);
            }
        }
    }
    */
}