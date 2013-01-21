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

using namespace noise;

const int cub::Chunk::_xLength = 32;
const int cub::Chunk::_yLength = 10;
const int cub::Chunk::_zLength = 32;

cub::Chunk::Chunk(Game *game)
    : _textureID(-1),
      _indiceBuffer(Buffer::Index),
      _vertexBuffer(Buffer::Vertex),
      _textureBuffer(Buffer::Vertex),
      _normalBuffer(Buffer::Vertex),
      _tangentBuffer(Buffer::Vertex),
      _bitangentBuffer(Buffer::Vertex)
{
    _game = game;

    _data = new int[_xLength * _yLength * _zLength];

    _box = Box(glm::vec3(_position.x * _xLength, _position.y * _yLength, _position.z * _zLength), glm::vec3(_xLength, _yLength, _zLength));
}

// x is the height, y is the width and z is the depth
// height + width * WIDTH + depth * WIDTH * DEPTH
inline int val(int x, int y, int z, int _xLength, int _zLength)
{
    return y * _xLength * _zLength + x * _zLength + z;
}
#define get(x,y,z) _data[val(x,y,z,_xLength,_zLength)]

void cub::Chunk::Display()
{
    for (int y = 0; y < _yLength; ++y)
    {
        cout << "--- Level: " << y << endl;
        for (int z = 0; z < _zLength; ++z)
        {
            for (int x = 0; x < _xLength; ++x)
            {
                cout << get(x, y, z) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

const cub::Box& cub::Chunk::GetBox() const
{
    return _box;
}

void cub::Chunk::Load(utils::NoiseMap heightMap)
{
    _shader = _game->GetContent().LoadShaders("shaders/phong_tex.vert", "shaders/phong_tex.frag");

    for (int i = 0; i < _xLength * _yLength * _zLength; ++i)
    {
        _data[i] = 0;
    }

    for (int z = 0; z < _zLength; ++z)
    {
        for (int x = 0; x < _xLength; ++x)
        {
            float height = heightMap.GetValue(x,z) + 1;
            height = clamp(height * _yLength / 2.0f, 0, _yLength - 1);
            
            for (int y = 0; y < height; ++y)
                get(x, y, z) = 2;
        }
    }

    //gl::ActiveTexture(gl::TEXTURE0);
    _textureID = _game->GetContent().LoadTexture("textures/terrain.png");

    Generate();
}

int cub::Chunk::GetXLength()
{
    return _xLength;
}

int cub::Chunk::GetYLength()
{
    return _yLength;
}

int cub::Chunk::GetZLength()
{
    return _zLength;
}

struct Voxel
{
    vector<unsigned int> indices;
    int x, y, z;
    int s, t;
};

void cub::Chunk::Generate()
{
    vector<Voxel> voxels;
    const int texNum = 16;
    const float texSizz = 0.0625f; // 1 / texNum
    const float texOffset = 0.005f;
    int size = 0;
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

                Voxel vox;
                vox.x = x;
                vox.y = y;
                vox.z = z;
                int n = get(x,y,z) - 1;
                vox.s = n % texNum;
                vox.t = (texNum - 1) - n / texNum;

                vox.indices = CubeBuilder::Build(yp, yn, xp, xn, zp, zn);
                size += vox.indices.size();

                voxels.push_back(vox);
            }
        }
    }
    
    vector<unsigned int> indices;
    indices.reserve(size);
    vector<float> vertices;
    vertices.reserve(size * 3 * 4 / 6.f);
    vector<float> texcoords;
    texcoords.reserve(size * 2 * 4 / 6.f);
    vector<float> normals;
    normals.reserve(size * 3 * 4 / 6.f);
    vector<float> tangents;
    tangents.reserve(size * 3 * 4 / 6.f);
    vector<float> bitangents;
    bitangents.reserve(size * 3 * 4 / 6.f);
    
    for (vector<Voxel>::iterator vox = voxels.begin(); vox != voxels.end(); ++vox)
    {
        for (vector<unsigned int>::iterator it = vox->indices.begin(); it != vox->indices.end(); it += 6)
        {
            unsigned int id[4] = { *(it+0), *(it+1), *(it+2), *(it+5) };

            for (int i = 0; i < 4; ++i)
            {
                vertices.push_back((CubeBuilder::Vertices[id[i] * 3 + 0]) + vox->x);
                vertices.push_back((CubeBuilder::Vertices[id[i] * 3 + 1]) + vox->y);
                vertices.push_back((CubeBuilder::Vertices[id[i] * 3 + 2]) + vox->z);
                
                int s = CubeBuilder::TexCoords[id[i] * 2 + 0];
                int t = CubeBuilder::TexCoords[id[i] * 2 + 1];
                float ss = 0, tt = 0;
                if (s == 1)
                    ss = texSizz * (vox->s + 1) - texOffset;
                else if (s == 0)
                    ss = texSizz * vox->s + texOffset;
                if (t == 1)
                    tt = texSizz * (vox->t + 1) - texOffset;
                else if (t == 0)
                    tt = texSizz * vox->t + texOffset;
                texcoords.push_back(ss);
                texcoords.push_back(tt);
            
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
    }

    for (unsigned int i = 0, offset = 0; i < size; i += 6, ++offset)
    {
        indices.push_back(0 + offset * 4);
        indices.push_back(1 + offset * 4);
        indices.push_back(2 + offset * 4);
        indices.push_back(0 + offset * 4);
        indices.push_back(2 + offset * 4);
        indices.push_back(3 + offset * 4);
    }

    /*
    for (vector<float>::iterator it = texcoords.begin(); it != texcoords.end(); )
    {
        if (*it == 1)
            *it = v * 3 - m;
        else if (*it == 0)
            *it = v * 2 + m;
        ++it;
        
        if (*it == 1)
            *it = v * 16 - m;
        else if (*it == 0)
            *it = v * 15 + m;
        ++it;
    }
    */

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

    return get(x, y, z) != 0;
}

glm::vec3 cub::Chunk::GetPosition() const
{
    return _position;
}

void cub::Chunk::SetPosition(glm::vec3 position)
{
    _position = position;
    _box = Box(glm::vec3(_position.x * _xLength, _position.y * _yLength, _position.z * _zLength), glm::vec3(_xLength, _yLength, _zLength));
}

void cub::Chunk::Render(double time)
{
    glm::mat4 projectionMatrix = _game->GetCamera().GetProjectionMatrix();
    glm::mat4 viewMatrix = _game->GetCamera().GetViewMatrix();
    //glm::mat4 viewMatrix = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    glm::mat4 modelMatrix = glm::translate(_position * glm::vec3(_xLength, _yLength, _zLength));

    glm::mat4 mvMatrix = viewMatrix * modelMatrix;
    glm::mat4 mvpMatrix = projectionMatrix * mvMatrix;
    glm::mat3 normalMatrix = glm::inverseTranspose(glm::mat3(mvMatrix));

    _shader->Bind();
    _shader->SetUniformValue("mvMatrix", mvMatrix);
    _shader->SetUniformValue("mvpMatrix", mvpMatrix);
    _shader->SetUniformValue("normalMatrix", normalMatrix);
    //_shader->SetUniformValue("Light.Position", viewMatrix * glm::vec4(0, 3, 0, 1));
    _shader->SetUniformValue("Light.Position", viewMatrix * glm::vec4(0.1f, 1, 0.1f, 0));
    _shader->SetUniformValue("Light.Intensity", glm::vec3(1, 1, 1));
    //_shader->SetUniformValue("Material.Ka", glm::vec3(0.329412f, 0.223529f, 0.027451f));
    //_shader->SetUniformValue("Material.Kd", glm::vec3(0.780392f, 0.568627f, 0.113725f));
    //_shader->SetUniformValue("Material.Ks", glm::vec3(0.992157f, 0.941176f, 0.807843f));
    //_shader->SetUniformValue("Material.Shininess", 27.89743616f);
    _shader->SetUniformValue("Material.Ka", glm::vec3(0.2f, 0.2f, 0.2f));
    _shader->SetUniformValue("Material.Kd", glm::vec3(0.8f, 0.8f, 0.8f));
    _shader->SetUniformValue("Material.Ks", glm::vec3(0.5f, 0.5f, 0.5f));
    _shader->SetUniformValue("Material.Shininess", 50.0f);

    gl::ActiveTexture(gl::TEXTURE0);
    gl::BindTexture(gl::TEXTURE_2D, _textureID);
    _shader->SetUniformValue("Tex1", 0);
    
    _shader->EnableVertexAttribArray("in_Position");
    _vertexBuffer.Bind();
    _shader->VertexAttribPointer("in_Position", 3, gl::FLOAT, false, 0, 0);

    _shader->EnableVertexAttribArray("in_TexCoord", false);
    _textureBuffer.Bind();
    _shader->VertexAttribPointer("in_TexCoord", 2, gl::FLOAT, false, 0, 0, false);

    _shader->EnableVertexAttribArray("in_Normal", false);
    _normalBuffer.Bind();
    _shader->VertexAttribPointer("in_Normal", 3, gl::FLOAT, false, 0, 0, false);

    _shader->EnableVertexAttribArray("in_Tangent", false);
    _tangentBuffer.Bind();
    _shader->VertexAttribPointer("in_Tangent", 3, gl::FLOAT, false, 0, 0, false);

    _shader->EnableVertexAttribArray("in_Bitangent", false);
    _bitangentBuffer.Bind();
    _shader->VertexAttribPointer("in_Bitangent", 3, gl::FLOAT, false, 0, 0, false);

    _indiceBuffer.Bind();
    
    gl::DrawElements(gl::TRIANGLES, _indiceLength, gl::UNSIGNED_INT, 0);
}