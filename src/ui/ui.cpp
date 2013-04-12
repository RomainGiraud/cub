#include <ui/ui.h>

#include <engine/game.h>
#include <engine/content.h>

#include <iostream>
using namespace std;

cub::UI* cub::UI::MainUI = 0;

cub::UI::UI(Game *game)
	: DrawableComponent(game)
{
    MainUI = this;

	awe_webcore_initialize_default();

	_view = awe_webcore_create_webview(800, 600, false);
}

cub::UI::~UI()
{
	awe_webview_destroy(_view);
	//awe_webcore_shutdown();
}

void cub::UI::SetBaseDirectory(const std::string& baseDirectory)
{
	awe_string* base = awe_string_create_from_ascii(baseDirectory.c_str(), baseDirectory.length());
	awe_webcore_set_base_directory(base);
	awe_string_destroy(base);
}

void cub::UI::Resize(int width, int height)
{
	awe_webview_resize(_view, width, height, false, 0);
}


inline awe_string* StringToAweString(const string& str)
{
	return awe_string_create_from_ascii(str.c_str(), str.length());
}
inline string AweStringToString(const awe_string* aweStr)
{
	int bufSize = awe_string_to_utf8(aweStr, 0, 0);

	if (bufSize > 0)
	{
		char* stringBuffer = new char[bufSize];
		awe_string_to_utf8(aweStr, stringBuffer, bufSize);

		string result;
		result.assign(stringBuffer, bufSize);

		delete[] stringBuffer;

		return result;
	}

	return string();
}

void cub::UI::AwesomiumCallbackFunction(awe_webview* caller,
										const awe_string* object_name,
										const awe_string* callback_name,
										const awe_jsarray* arguments)
{
	if (AweStringToString(object_name) == "UI" && AweStringToString(callback_name) == "Select")
	{
		awe_string* objectName = StringToAweString("UI");

		awe_string* propName = StringToAweString("Name");
		awe_string* val = StringToAweString("Toto");
		awe_jsvalue* propVal = awe_jsvalue_create_string_value(val);
		awe_webview_set_object_property(MainUI->_view, objectName, propName, propVal);
		awe_jsvalue_destroy(propVal);
		awe_string_destroy(val);
		awe_string_destroy(propName);

		awe_string_destroy(objectName);
	}
}

void cub::UI::SetFPS(double fps)
{
	awe_jsvalue* arg1 = awe_jsvalue_create_double_value((int)fps);
	//const awe_jsvalue* argsArray[1] = { arg1 };

	awe_string* functionName = StringToAweString("SetFPS");
	awe_jsarray* args = awe_jsarray_create(
		(const awe_jsvalue**)&arg1,
		1
	);


	awe_webview_call_javascript_function(
		_view,
		awe_string_empty(),
		functionName,
		args,
		awe_string_empty()
	);


	awe_string_destroy(functionName);
	awe_jsarray_destroy(args);
	awe_jsvalue_destroy(arg1);
}

void cub::UI::Load()
{
	SetBaseDirectory(_game->GetContent().GetPath() + "ui");


	awe_string* str = StringToAweString("index.html");
	awe_webview_load_file(_view, str, awe_string_empty());
	awe_string_destroy(str);

	awe_webview_set_transparent(_view, true);


	awe_string* objectName = StringToAweString("UI");
	awe_webview_create_object(_view, objectName);

	awe_string* propName = StringToAweString("Name");
	awe_string* val = StringToAweString("Romain");
	awe_jsvalue* propVal = awe_jsvalue_create_string_value(val);
	awe_webview_set_object_property(_view, objectName, propName, propVal);
	awe_jsvalue_destroy(propVal);
	awe_string_destroy(val);
	awe_string_destroy(propName);

	awe_string* funcName = StringToAweString("Select");
	awe_webview_set_object_callback(_view, objectName, funcName);
	awe_string_destroy(funcName);

	awe_webview_set_callback_js_callback(_view, AwesomiumCallbackFunction);

	awe_string_destroy(objectName);


	_plane = new ScreenAlignedQuad(_game);
	_plane->Load();

	gl::GenTextures(1, &_texture);
}

void cub::UI::Update(double timeSec)
{
	//if (! awe_webview_is_loading_page(_view)) return;

	const awe_renderbuffer* render = awe_webview_render(_view);
	const unsigned char* buffer = awe_renderbuffer_get_buffer(render);
	int width = awe_renderbuffer_get_width(render);
	int height = awe_renderbuffer_get_width(render);
	glm::vec2 p = _game->GetMousePosition();

	if (0 <= p.x && p.x < width && 0 <= p.y && p.y < height &&
		buffer[(int)p.x * 4 + (int)p.y * 4 * width + 3] != 0)
	{
		awe_webview_inject_mouse_move(_view, p.x, p.y);

		if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
			awe_webview_inject_mouse_down(_view, AWE_MB_LEFT);
		else
			awe_webview_inject_mouse_up(_view, AWE_MB_LEFT);
	}

	awe_webcore_update();
}

void cub::UI::Render(double timeSec)
{
	Update(timeSec);

	if (awe_webview_is_dirty(_view))
	{
		const awe_renderbuffer* render = awe_webview_render(_view);

		int width = awe_renderbuffer_get_width(render);
		int height = awe_renderbuffer_get_height(render);
		int rowspan = awe_renderbuffer_get_rowspan(render);

		//const unsigned char* buffer = awe_renderbuffer_get_buffer(render);// = new unsigned char[width * height * 4];
		unsigned char* buffer = new unsigned char[width * height * 4];
		awe_renderbuffer_copy_to(render, buffer, rowspan, 4, true, true);
		//for(int i = 0; i < width * height * 4; i += 4)
		//    buffer[i + 3] = 255;

		gl::BindTexture(gl::TEXTURE_2D, _texture);
		//gl::PixelStorei(gl::UNPACK_ALIGNMENT, 1);
		gl::TexImage2D(gl::TEXTURE_2D, 0, 4, width, height, 0, gl::RGBA, gl::UNSIGNED_BYTE, buffer);
		gl::TexParameterf(gl::TEXTURE_2D, gl::TEXTURE_MIN_FILTER, gl::LINEAR);
		gl::TexParameterf(gl::TEXTURE_2D, gl::TEXTURE_MAG_FILTER, gl::LINEAR);
	    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_S, gl::CLAMP);
	    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_T, gl::CLAMP);
		gl::BindTexture(gl::TEXTURE_2D, 0);

		_plane->SetTexture(_texture);

		delete[] buffer;
	}

	_plane->Render(timeSec);
}