#ifndef CUB_GAME_H
#define CUB_GAME_H

#include <list>
#include <string>

#include <glm/glm.hpp>

#include <GL/gl_core.hpp>

#define GLFW_NO_GLU
#include <GL/glfw.h>

#include <global/global.h>
#include <engine/content.h>
#include <camera/abstract_camera.h>
#include <global/settings.h>
#include <global/input.h>

namespace cub
{
    
class Terrain;

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
    Input& GetInput();
    Settings& GetSettings();
    AbstractCamera& GetCamera();

private:
    static Game *MainGame;

    Content _content;
    Settings *_settings;
    Input *_input;
    AbstractCamera *_camera;
    Terrain *_terrain;

    void InitGL();
    void Resize(int w, int h);

    // Callbacks
    static void GLFWCALL WindowSizeCallback(int w, int h);
    static void GLFWCALL KeyCallback(int key, int action);
};

}

#endif /*CUB_GAME_H*/
