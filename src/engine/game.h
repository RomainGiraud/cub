#ifndef CUB_GAME_H
#define CUB_GAME_H

#include <list>
#include <string>
#include <glm/glm.hpp>

#include <engine/content.h>
#include <camera/abstract_camera.h>

namespace cub
{
    
class Chunk;

class Game
{
public:
    Game();
    ~Game();
    void DisplayGLInfo() const;

    void LoadScene(std::string filename);

    void Load();
    int Run();
    
    void CursorShow();
    void CursorHide();
    glm::vec2 GetMousePosition();
    void SetMousePosition(glm::vec2 v);
    glm::vec2 GetSize();

    Content& GetContent();
    AbstractCamera& GetCamera();

private:
    Content _content;
    AbstractCamera *_camera;
    std::list<Chunk*> _components;
    void InitGL();
};

}

#endif /*CUB_GAME_H*/
