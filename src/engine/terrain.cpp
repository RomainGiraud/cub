#include <engine/terrain.h>

#include <engine/game.h>
#include <engine/chunk.h>

#include <iostream>
using namespace std;

#include <noise/noise.h>
#include "noise/noiseutils.h"
using namespace noise;

cub::Terrain::Terrain(Game *game)
	: _game(game)
{
}

cub::Terrain::~Terrain()
{
    for (list<Chunk*>::const_iterator it = _chunks.begin(); it != _chunks.end(); ++it)
    {
    	delete (*it);
    }
}

void cub::Terrain::Load()
{
	module::Perlin myModule;
	utils::NoiseMap heightMap;

	//myModule.SetSeed(XXX);

	utils::NoiseMapBuilderPlane heightMapBuilder;
	heightMapBuilder.SetSourceModule(myModule);
	heightMapBuilder.SetDestNoiseMap(heightMap);
	heightMapBuilder.SetDestSize(Chunk::GetXLength(), Chunk::GetZLength());

	for (int x = 0; x < 5; ++x)
	{
		for (int z = 0; z < 5; ++z)
		{
			heightMapBuilder.SetBounds(x * 5.0, (x+1) * 5.0, z * 5.0, (z+1) * 5.0);
			heightMapBuilder.Build();

			Chunk *ch = new Chunk(_game);
			ch->SetPosition(glm::vec3(x,0,z));
			ch->Load(heightMap);

		    _chunks.push_back(ch);
		}
	}
}

void cub::Terrain::Render(double time)
{
	int nb = 0;
    for (list<Chunk*>::const_iterator it = _chunks.begin(); it != _chunks.end(); ++it)
    {
    	if (_game->GetCamera().GetBoundingFrustum().Contains((*it)->GetBox()) != ContainmentType::Outside)
    	{
	        (*it)->Render(time);
	        ++nb;
    	}
    }
    cout << nb << endl;
}

void cub::Terrain::Generate()
{
}