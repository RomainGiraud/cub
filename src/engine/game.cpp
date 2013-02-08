#include <engine/game.h>

#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <vector>
#include <cmath>
using namespace std;

#include <json/reader.h>
using namespace json;

#include <camera/rts_camera.h>
#include <global/exception.h>
#include <global/tools.h>
#include <engine/shader.h>
#include <engine/chunk.h>
#include <engine/terrain.h>
#include <engine/content.h>
#include <object/cube.h>
#include <object/line.h>
#include <ui/ui.h>
using namespace cub;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <freeimage/FreeImage.h>

static void FreeImageErrorHandler(FREE_IMAGE_FORMAT fif, const char *message)
{
    cerr << "FreeImage - error: " << FreeImage_GetFormatFromFIF(fif) << endl
         << "    " << message << endl;
}

cub::Game* cub::Game::MainGame = 0;

cub::Game::Game()
{
    MainGame = this;

    glfwInit();
    glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, true);
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
#if defined(CUB_SYSTEM_WINDOWS)
    _content = new Content("D:/Projects/cub/resources");
#elif defined(CUB_SYSTEM_MACOS)
    _content = new Content("/Users/romain/Documents/Projets/cub/resources");
#endif

    _settings = new Settings(this);

    _input = new Input(this);
    
    _camera = new RTSCamera(this);
    _camera->SetPosition(glm::vec3(0, 20, 10));
    _camera->SetTargetPosition(glm::vec3(0, 20, 10));

    _terrain = new Terrain(this);

    _ui = new UI(this);

    _raycasting = false;
    _cube = new Cube(this);
    _cube->SetScale(glm::vec3(1.005f));
    _line = new Line(this);

    // Set callbacks
    glfwSetWindowSizeCallback(WindowSizeCallback);
    glfwSetKeyCallback(KeyCallback);
}

cub::Game::~Game()
{
    delete _line;
    delete _cube;
    delete _ui;
    delete _terrain;
    delete _camera;
    delete _content;
}

void GLFWCALL cub::Game::WindowSizeCallback(int w, int h)
{
    MainGame->Resize(w, h);
}

void GLFWCALL cub::Game::KeyCallback(int key, int action)
{
    MainGame->_input->KeyChanged(key, action);

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        MainGame->_raycasting = true;
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
    return *_content;
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
    _cube->Load();
    _line->Load();
    _ui->Load();
}

void cub::Game::LoadScene(string filename)
{
    //ifstream file (filename.c_str());

    //Object elemRootFile;
    //Reader::Read(elemRootFile, file);
}

vector<glm::vec3> res; // TODO
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
        glm::vec3 pos = _camera->GetTargetPosition();
        pos.y = 20 - glfwGetMouseWheel();
        _camera->SetTargetPosition(pos);


        if (_input->RenderWireframe())
        {
            gl::PolygonMode(gl::FRONT_AND_BACK, gl::LINE);
        }
        else
        {
            gl::PolygonMode(gl::FRONT_AND_BACK, gl::FILL);
        }

        if (_raycasting)
        {
            /*
            glm::vec2 size = GetSize();

            glm::vec2 mouse = GetMousePosition();
            mouse.y = size.y - mouse.y;

            glm::vec4 viewport = glm::vec4(0, 0, size.x, size.y);

            glm::vec3 v1 = glm::unProject(glm::vec3(mouse, 0.0),
                                         _camera->GetViewMatrix(),
                                         _camera->GetProjectionMatrix(),
                                         viewport);

            glm::vec3 v2 = glm::unProject(glm::vec3(mouse, 1.0),
                                         _camera->GetViewMatrix(),
                                         _camera->GetProjectionMatrix(),
                                         viewport);
            */
            //Ray ray(v1, v2 - v1);
            Ray ray(_camera->GetPosition(), _camera->GetDirection());
            //_line->SetPosition(v1);
            //_line->SetEnd(v2);
            _line->SetPosition(_camera->GetPosition());
            _line->SetDirection(_camera->GetDirection());

            res.clear();
            if (_terrain->Raycast(ray, res))
            {
                //_cube->SetPosition(res);
            }

            _raycasting = false;
        }

        _camera->Update(time);
        

        gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT);

        _terrain->Render(time);

        for (vector<glm::vec3>::const_iterator it = res.begin(); it != res.end(); ++it)
        {
            _cube->SetPosition(*it);
            _cube->Render(time);
        }

        _line->Render(time);

        // HUD
        _ui->Render(time);

        glfwSwapBuffers();


        time = glfwGetTime() - previousTime; // seconds
        previousTime = glfwGetTime();
    }

    glfwTerminate();

    return 0;
}

void cub::Game::InitGL()
{
    gl::ClearColor(0.39f, 0.58f, 0.93f, 1);
    
    gl::Enable(gl::DEPTH_TEST);

    gl::Enable(gl::BLEND);
    gl::BlendFunc(gl::SRC_ALPHA, gl::ONE_MINUS_SRC_ALPHA);

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

    _ui->Resize(w, h);
}