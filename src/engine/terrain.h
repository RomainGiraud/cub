#ifndef CUB_TERRAIN_H
#define CUB_TERRAIN_H

#include <list>
#include <vector>

#include <geometry/ray.h>

#include <engine/drawable_component.h>

namespace cub
{

class Game;
class Chunk;

class Terrain : public DrawableComponent
{
public:
    Terrain(Game *game);
    ~Terrain();

    void Load();
    void Update(double timeSec);
    void Render(double timeSec);

    bool Raycast(const Ray& ray, std::vector<glm::vec3>& result) const;
    
private:
    std::list<Chunk*> _chunks;

    void Generate();
};
}

#endif /*CUB_TERRAIN_H*/