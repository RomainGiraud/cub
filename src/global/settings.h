#ifndef CUB_SETTINGS_H
#define CUB_SETTINGS_H

#include <glm/glm.hpp>

#include <string>

namespace cub
{

class Game;

class Settings
{
public:
    Settings(Game *game);
    void Load(std::string file);

    char GetForward() const;
    char GetBackward() const;
    char GetRightward() const;
    char GetLeftward() const;

    char GetToggleWireframe() const;
    
private:
	Game *_game;
};
}

#endif /*CUB_SETTINGS_H*/