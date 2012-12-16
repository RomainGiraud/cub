#ifndef CUB_GLOBAL_H
#define CUB_GLOBAL_H

// references: http://sourceforge.net/p/predef/wiki/OperatingSystems/

// Bring in OpenGL
// Windows
#ifdef _WIN32
#define CUB_SYSTEM_WINDOWS
#endif

// Mac OS X
#ifdef __APPLE__
#define CUB_SYSTEM_MACOS
#endif

// Linux
#ifdef __linux__
#define CUB_SYSTEM_LINUX
#endif

#endif /*CUB_GLOBAL_H*/
