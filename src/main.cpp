#include <iostream>
using namespace std;

#include <engine/game.h>
#include <global/global.h>
#include <global/exception.h>
using namespace cub;

int main()
{
    try
    {
        Game game;
        game.Load();
        return game.Run();
    }
    catch (const Exception &e)
    {
        cerr << "====> " << e << endl;
#ifdef CUB_SYSTEM_WINDOWS
        system("pause");
#endif /*CUB_SFML_WINDOWS*/
    }

    return 0;
}
