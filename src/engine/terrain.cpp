#include <engine/terrain.h>

#include <engine/game.h>
#include <engine/chunk.h>
#include <global/tools.h>

#include <iostream>
#include <vector>
using namespace std;

#include <noise/noise.h>
#include "noise/noiseutils.h"
using namespace noise;

cub::Terrain::Terrain(Game *game)
	: DrawableComponent(game)
{
}

cub::Terrain::~Terrain()
{
    for (list<Chunk*>::const_iterator it = _chunks.begin(); it != _chunks.end(); ++it)
    {
    	delete (*it);
    }
}

bool cub::Terrain::Raycast(const Ray& ray, vector<glm::vec3>& result) const
{
	float maxDistance = 1.0f / 0.0f;
    vector<const Chunk*> chunkResults;
    for (list<Chunk*>::const_iterator it = _chunks.begin(); it != _chunks.end(); ++it)
    {
    	float v = 0;
    	if (ray.Intersect((*it)->GetBox(), &v))
    	{
    		if (v < maxDistance)
    		{
                chunkResults.push_back(*it);
    			maxDistance = v;	
    		}
    	}
    }

    if (chunkResults.size() > 0)
    {
        for (vector<const Chunk*>::const_iterator it = chunkResults.begin(); it != chunkResults.end(); ++it)
        {
            (*it)->Raycast(ray, result);
        }
        //cout << "[pick] nb: " << result.size() << endl;
        return true;
    }

    return false;
}

void cub::Terrain::Load()
{
    module::Perlin myModule;
	utils::NoiseMap heightMap;

	//myModule.SetSeed(XXX);

    //module::Billow baseFlatTerrain;
    //module::ScaleBias flatTerrain;
    //flatTerrain.SetSourceModule (0, baseFlatTerrain);
    //flatTerrain.SetScale (0.125);
    //flatTerrain.SetBias (-0.75);

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

void cub::Terrain::Update(double timeSec)
{
}

void cub::Terrain::Render(double timeSec)
{
    for (list<Chunk*>::const_iterator it = _chunks.begin(); it != _chunks.end(); ++it)
    {
    	if (_game->GetCamera().GetBoundingFrustum().Contains((*it)->GetBox()) != ContainmentType::Outside)
    	{
	        (*it)->Render(timeSec);
    	}
    }
}

void cub::Terrain::Generate()
{
}