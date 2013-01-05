#include <engine/game.h>

#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <cmath>
using namespace std;

#include <json/reader.h>
using namespace json;

#include <camera/free_camera.h>
#include <camera/rts_camera.h>
#include <global/exception.h>
#include <global/tools.h>
#include <engine/shader.h>
#include <engine/chunk.h>
#include <engine/terrain.h>
using namespace cub;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <fi/FreeImage.h>

static void FreeImageErrorHandler(FREE_IMAGE_FORMAT fif, const char *message)
{
    cerr << "FreeImage - error: " << FreeImage_GetFormatFromFIF(fif) << endl
         << "    " << message << endl;
}

cub::Game* cub::Game::MainGame = 0;

cub::Game::Game()
#if defined(CUB_SYSTEM_WINDOWS)
    : _content("D:/Projects/cub/resources")
#elif defined(CUB_SYSTEM_MACOS)
    : _content("/Users/romain/Documents/Projets/cub/resources")
#endif
{
    MainGame = this;

    glfwInit();
    glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
    glfwSetWindowTitle("cub");
    //glfwSwapInterval(1); // vertical sync ?
    glfwOpenWindow(800, 600, 8, 8, 8, 8, 24, 8, GLFW_WINDOW);

    // Init GLLoader
    gl::sys::LoadFunctions();

    // FreeImage loading
	FreeImage_Initialise();
    FreeImage_SetOutputMessage(FreeImageErrorHandler);

    DisplayGLInfo();

    // Initialize engine's parts
    _settings = new Settings(this);

    _input = new Input(this);
    
    _camera = new RTSCamera(this);
    _camera->SetPosition(glm::vec3(0, 10, 10));

    _terrain = new Terrain(this);


    // Set callbacks
    glfwSetWindowSizeCallback(WindowSizeCallback);
}

cub::Game::~Game()
{
    delete _terrain;
    delete _camera;
}

void GLFWCALL cub::Game::WindowSizeCallback(int w, int h)
{
    MainGame->Resize(w, h);
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

cub::Input& cub::Game::GetInput()
{
    return *_input;
}

cub::Settings& cub::Game::GetSettings()
{
    return *_settings;
}

cub::AbstractCamera& cub::Game::GetCamera()
{
    return *_camera;
}

void cub::Game::Load()
{
    //LoadScene("D:/Projects/cub_cpp/resources/scene.json");
    _terrain->Load();
}

void cub::Game::LoadScene(string filename)
{
    ifstream file (filename.c_str());

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
        
        _input->Update();
        if (_input->IsMoving())
        {
            _camera->Translate(_input->GetMovingVector() * (float)(time * 10));
        }

        
        gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT);
        _terrain->Render(time);
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

void cub::Game::Resize(int w, int h)
{
    gl::Viewport(0, 0, w, h);

    glm::vec2 size = GetSize();
    float aspectRatio = size.x / (float)(size.y);
    _camera->SetAspectRatio(aspectRatio);
}