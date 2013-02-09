cmake_minimum_required(VERSION 2.6)

# Configuration
project("cub")
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# Ouput directories
if (APPLE)
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/exe)
else()
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
endif()

# Check C++11 compiler
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=c++11" IS_STDCXX11)
if (NOT IS_STDCXX11)
    #message(FATAL_ERROR "Need a C++11 compiler")
endif()

# Compilation flags
set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -Werror -ggdb")
#set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -Werror")

# Include and headers
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/dep/include)
if (MINGW)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/glfw/lib-mingw)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/freeimage/lib-mingw)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/noise/lib-mingw)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/Awesomium/lib-mingw)
elseif (APPLE)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/glfw/lib-osx)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/freeimage/lib-osx)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/noise/lib-osx)
endif()

# Source files
file(GLOB_RECURSE src ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/*.c ${CMAKE_SOURCE_DIR}/src/*.h ${CMAKE_SOURCE_DIR}/src/*.hpp)

# Executable
if (WIN32)
    add_executable(${PROJECT_NAME} ${src})
elseif (APPLE)
    set(CMAKE_OSX_ARCHITECTURES "i386")
    add_executable(${PROJECT_NAME} ${src})
endif()

# Librairies
if (MINGW)
    target_link_libraries(${PROJECT_NAME} "GLFW")
    target_link_libraries(${PROJECT_NAME} "OpenGL32")
    target_link_libraries(${PROJECT_NAME} "noise")
    target_link_libraries(${PROJECT_NAME} "freeimage")
    target_link_libraries(${PROJECT_NAME} "Awesomium")
elseif (APPLE)
    find_library(OPENGL OpenGL)
    target_link_libraries(${PROJECT_NAME} "${OPENGL}")
    find_library(COCOA Cocoa)
    target_link_libraries(${PROJECT_NAME} "${COCOA}")
    find_library(IOKIT IOKit)
    target_link_libraries(${PROJECT_NAME} "${IOKIT}")
    target_link_libraries(${PROJECT_NAME} "GLFW")
    target_link_libraries(${PROJECT_NAME} "noise")
    target_link_libraries(${PROJECT_NAME} "freeimage")
    target_link_libraries(${PROJECT_NAME} "-F ${CMAKE_SOURCE_DIR}/dep/libs/Awesomium/lib-osx -framework Awesomium")
endif()

# Copy dll to output directory
if (MINGW)
    file(COPY "${CMAKE_SOURCE_DIR}/dep/libs/freeimage/lib-mingw/FreeImage.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin")
    file(COPY "${CMAKE_SOURCE_DIR}/dep/libs/Awesomium/lib-mingw/locales" DESTINATION "${CMAKE_SOURCE_DIR}/bin")
    file(COPY "${CMAKE_SOURCE_DIR}/dep/libs/Awesomium/lib-mingw/avcodec-52.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin")
    file(COPY "${CMAKE_SOURCE_DIR}/dep/libs/Awesomium/lib-mingw/avformat-52.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin")
    file(COPY "${CMAKE_SOURCE_DIR}/dep/libs/Awesomium/lib-mingw/avutil-50.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin")
    file(COPY "${CMAKE_SOURCE_DIR}/dep/libs/Awesomium/lib-mingw/Awesomium.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin")
    file(COPY "${CMAKE_SOURCE_DIR}/dep/libs/Awesomium/lib-mingw/AwesomiumProcess.exe" DESTINATION "${CMAKE_SOURCE_DIR}/bin")
    file(COPY "${CMAKE_SOURCE_DIR}/dep/libs/Awesomium/lib-mingw/icudt42.dll" DESTINATION "${CMAKE_SOURCE_DIR}/bin")
elseif (APPLE)
    file(COPY "${CMAKE_SOURCE_DIR}/dep/libs/Awesomium/lib-osx/Awesomium.framework" DESTINATION "${CMAKE_SOURCE_DIR}/bin/Frameworks")
    file(WRITE "${CMAKE_SOURCE_DIR}/bin/cub" "cd exe && ./cub")
    execute_process(COMMAND chmod "u+x" "${CMAKE_SOURCE_DIR}/bin/cub")
endif()