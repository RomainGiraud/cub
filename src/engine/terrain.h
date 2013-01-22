#ifndef CUB_TERRAIN_H
#define CUB_TERRAIN_H

#include <list>
#include <vector>

#include <geometry/ray.h>

namespace cub
{

class Game;
class Chunk;

class Terrain
{
public:
    Terrain(Game *game);
    ~Terrain();

    void Load();
    void Render(double time);

    bool Raycast(const Ray& ray, std::vector<glm::vec3>& result) const;
    
private:
    Game *_game;
    std::list<Chunk*> _chunks;

    void Generate();
};
}

#endif /*CUB_TERRAIN_H*/