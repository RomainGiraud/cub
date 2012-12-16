#include <engine/game.h>

#include <GL/gl_core_3_3.hpp>

#define GLFW_NO_GLU
#include <GL/glfw.h>

#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <cmath>
using namespace std;

#include <json/reader.h>
using namespace json;

#include <global/global.h>
#include <camera/free_camera.h>
#include <camera/rts_camera.h>
#include <global/exception.h>
#include <global/tools.h>
#include <engine/shader.h>
#include <engine/chunk.h>
using namespace cub;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/euler_angles.hpp>

static void WindowSizeCallback(int w, int h)
{
}

cub::Game::Game()
    : _content("D:/Projects/cub/resources/")
{
    glfwInit();
    glfwOpenWindow(800, 600, 8, 8, 8, 8, 24, 8, GLFW_WINDOW);
    glfwSetWindowTitle("cub");
    glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
    //glfwSwapInterval(1); // vertical sync ?
    glfwSetWindowSizeCallback(WindowSizeCallback);

    // Init GLLoader
    gl::sys::LoadFunctions();

    DisplayGLInfo();

    _components = list<Chunk*>();
    
    _camera = new RTSCamera(this);
    _camera->SetPosition(glm::vec3(0, 1, 0));
}

cub::Game::~Game()
{
}

void cub::Game::DisplayGLInfo() const
{
    cout << "OpenGL: " << endl
        << "  - version: " << gl::GetString(gl::VERSION) << endl
        << "  - vendor: " << gl::GetString(gl::VENDOR) << endl
        << "  - renderer: " << gl::GetString(gl::RENDERER) << endl
        << "  - shading version: " << gl::GetString(gl::SHADING_LANGUAGE_VERSION) << endl;
}

void cub::Game::CursorShow()
{
    glfwEnable(GLFW_MOUSE_CURSOR);
}

void cub::Game::CursorHide()
{
    glfwDisable(GLFW_MOUSE_CURSOR);
}

glm::vec2 cub::Game::GetMousePosition()
{
    int x, y;
    glfwGetMousePos(&x, &y);
    return glm::vec2(x, y);
}

void cub::Game::SetMousePosition(glm::vec2 v)
{
    glfwSetMousePos(v.x, v.y);
}

glm::vec2 cub::Game::GetSize()
{
    int w, h;
    glfwGetWindowSize(&w, &h);
    return glm::vec2(w, h);
}

cub::Content& cub::Game::GetContent()
{
    return _content;
}

cub::AbstractCamera& cub::Game::GetCamera()
{
    return *_camera;
}

void cub::Game::Load()
{
    //LoadScene("D:/Projects/cub_cpp/resources/scene.json");

    _components.push_back(new Chunk(this));

    for (list<Chunk*>::const_iterator it = _components.begin(); it != _components.end(); ++it)
    {
        (*it)->Load();
    }
}

void cub::Game::LoadScene(string filename)
{
    ifstream file (filename, ios_base::beg);

    Object elemRootFile;
    Reader::Read(elemRootFile, file);
}

int cub::Game::Run()
{
    InitGL();

    double previousTime = glfwGetTime();
    double time = 0;
    bool running = true;
    while (running)
    {
        running = !glfwGetKey(GLFW_KEY_ESC) &&
                    glfwGetWindowParam(GLFW_OPENED);
        
        bool isMoving = false;
        glm::vec3 move(0.f);
        if (glfwGetKey('Z') == GLFW_PRESS)
        {
            move.z = -1;
            isMoving = true;
        }
        else if (glfwGetKey('S') == GLFW_PRESS)
        {
            move.z = +1;
            isMoving = true;
        }
        if (glfwGetKey('Q') == GLFW_PRESS)
        {
            move.x = -1;
            isMoving = true;
        }
        else if (glfwGetKey('D') == GLFW_PRESS)
        {
            move.x = +1;
            isMoving = true;
        }

        if (isMoving)
        {
            _camera->Translate(glm::normalize(move) * (float)(time * 10));
        }

        
        gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT);

        for (list<Chunk*>::const_iterator it = _components.begin(); it != _components.end(); ++it)
        {
            (*it)->Render(time);
        }

        glfwSwapBuffers();


        time = glfwGetTime() - previousTime;
        previousTime = glfwGetTime();
    }

    glfwTerminate();

    return 0;
}

void cub::Game::InitGL()
{
    gl::ClearColor(0.39f, 0.58f, 0.93f, 1);
    
    gl::Enable(gl::DEPTH_TEST);
    gl::Viewport(0, 0, 800, 600);

/*
    glEnable(glCULL_FACE);
    glCullFace(glBACK);
    glFrontFace(glCCW);

    glEnable(glDEPTH_TEST);
    glDepthFunc(glLESS);

    glEnable(glBLEND);
    glBlendFunc(glSRC_ALPHA, glONE_MINUS_SRC_ALPHA);

    glEnable(glLINE_SMOOTH);
    glHint(glLINE_SMOOTH_HINT, glNICEST);
    glEnable(glPOLYGON_SMOOTH);
    glHint(glPOLYGON_SMOOTH_HINT, glNICEST);
*/
}