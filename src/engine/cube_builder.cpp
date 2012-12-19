#include <engine/cube_builder.h>

using namespace std;


const unsigned int cub::CubeBuilder::Indices[36] = {
    0, 1, 2, // -Y
    0, 2, 3,
    4, 5, 6, // +Y
    4, 6, 7,
    8, 9, 10, // +Z
    8, 10, 11,
    12, 13, 14, // +X
    12, 14, 15,
    16, 17, 18, // -Z
    16, 18, 19,
    20, 21, 22, // -X
    20, 22, 23,
};

const float cub::CubeBuilder::Vertices[24 * 3] = {
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

const float cub::CubeBuilder::Normals[24 * 3] = {
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

const float cub::CubeBuilder::TexCoords[24 * 2] = {
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

const float cub::CubeBuilder::Tangents[24 * 3] = {
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

const float cub::CubeBuilder::Bitangents[24 * 3] = {
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

vector<unsigned int> cub::CubeBuilder::Build(bool yp, bool yn, bool xp, bool xn, bool zp, bool zn)
{
	vector<unsigned int> indices;
	if (yp) // +Y
	{
		indices.push_back(4);
		indices.push_back(5);
		indices.push_back(6);

		indices.push_back(4);
		indices.push_back(6);
		indices.push_back(7);
	}
	if (yn) // -Y
	{
		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);

		indices.push_back(0);
		indices.push_back(2);
		indices.push_back(3);
	}

	if (xp) // +X
	{
		indices.push_back(12);
		indices.push_back(13);
		indices.push_back(14);

		indices.push_back(12);
		indices.push_back(14);
		indices.push_back(15);
	}
	if (xn) // -X
	{
		indices.push_back(20);
		indices.push_back(21);
		indices.push_back(22);

		indices.push_back(20);
		indices.push_back(22);
		indices.push_back(23);
	}

	if (zp) // +Z
	{
		indices.push_back(8);
		indices.push_back(9);
		indices.push_back(10);

		indices.push_back(8);
		indices.push_back(10);
		indices.push_back(11);
	}
	if (zn) // -Z
	{
		indices.push_back(16);
		indices.push_back(17);
		indices.push_back(18);

		indices.push_back(16);
		indices.push_back(18);
		indices.push_back(19);
	}
	return indices;
}