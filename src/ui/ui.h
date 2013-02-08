#ifndef CUB_MAINUI_H
#define CUB_MAINUI_H

#include <engine/drawable_component.h>

#include <Awesomium/awesomium_capi.h>

#include <object/screen_aligned_quad.h>

#include <string>

namespace cub
{

class Game;

class UI : public DrawableComponent
{
public:
    UI(Game *game);
    ~UI();

    void Load();
    void Update(double timeSec);
    void Render(double timeSec);

    void Resize(int width, int height);
    void SetBaseDirectory(const std::string& baseDirectory);

private:
    static UI *MainUI;

    static void AwesomiumCallbackFunction(awe_webview* caller,
                                          const awe_string* object_name,
                                          const awe_string* callback_name,
                                          const awe_jsarray* arguments);

	awe_webview* _view;
	ScreenAlignedQuad *_plane;
	GLuint _texture;
};

}

#endif /*CUB_SHADER_H*/