#ifndef CUB_TERRAIN_H
#define CUB_TERRAIN_H

#include <list>

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
    
private:
    Game *_game;
    std::list<Chunk*> _chunks;

    void Generate();
};
}

#endif /*CUB_TERRAIN_H*/