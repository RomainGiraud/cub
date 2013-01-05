#include <iostream>
using namespace std;

#include <engine/game.h>
#include <global/global.h>
#include <global/exception.h>
using namespace cub;

#include <noise/exception.h>

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
    catch (const noise::ExceptionInvalidParam &e)
    {
        cerr << "====> [libnoise] invalid param" << endl;
#ifdef CUB_SYSTEM_WINDOWS
        system("pause");
#endif /*CUB_SFML_WINDOWS*/
    }
    catch (const noise::ExceptionNoModule &e)
    {
        cerr << "====> [libnoise] no module" << endl;
#ifdef CUB_SYSTEM_WINDOWS
        system("pause");
#endif /*CUB_SFML_WINDOWS*/
    }
    catch (const noise::ExceptionOutOfMemory &e)
    {
        cerr << "====> [libnoise] out of memory" << endl;
#ifdef CUB_SYSTEM_WINDOWS
        system("pause");
#endif /*CUB_SFML_WINDOWS*/
    }
    catch (const noise::ExceptionUnknown &e)
    {
        cerr << "====> [libnoise] unknown" << endl;
#ifdef CUB_SYSTEM_WINDOWS
        system("pause");
#endif /*CUB_SFML_WINDOWS*/
    }

    return 0;
}
