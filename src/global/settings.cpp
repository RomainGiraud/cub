#include <global/settings.h>

#include <engine/game.h>

using namespace std;

cub::Settings::Settings(Game *game)
	: _game(game)
{
}

void cub::Settings::Load(string file)
{
}

char cub::Settings::GetForward() const
{
#if defined(CUB_SYSTEM_WINDOWS)
	return 'Z';
#elif defined(CUB_SYSTEM_MACOS)
	return 'W';
#endif
}

char cub::Settings::GetBackward() const
{
#if defined(CUB_SYSTEM_WINDOWS)
	return 'S';
#elif defined(CUB_SYSTEM_MACOS)
	return 'S';
#endif
}

char cub::Settings::GetRightward() const
{
#if defined(CUB_SYSTEM_WINDOWS)
	return 'D';
#elif defined(CUB_SYSTEM_MACOS)
	return 'D';
#endif
}

char cub::Settings::GetLeftward() const
{
#if defined(CUB_SYSTEM_WINDOWS)
	return 'Q';
#elif defined(CUB_SYSTEM_MACOS)
	return 'A';
#endif
}

char cub::Settings::GetToggleWireframe() const
{
#if defined(CUB_SYSTEM_WINDOWS)
	return 'W';
#elif defined(CUB_SYSTEM_MACOS)
	return 'Z';
#endif
}