cmake_minimum_required(VERSION 2.6)

# Configuration
project("cub")
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# Ouput directories
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# Custom commands
macro(copy_dll DLL_PATH)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/dep/libs/${DLL_PATH}"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endmacro(copy_dll)

# Check C++11 compiler
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=c++11" IS_STDCXX11)
if (NOT IS_STDCXX11)
    #message(FATAL_ERROR "Need a C++11 compiler")
endif()

# Compilation flags
set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -Werror")

# Include and headers
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/dep/include)
if (MINGW)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/glfw/lib-mingw)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/fi/lib-mingw)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/noise/lib-mingw)
elseif (APPLE)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/glfw/lib-osx)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/fi/lib-osx)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/noise/lib-osx)
endif()

# Source files
file(GLOB_RECURSE src ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/*.c ${CMAKE_SOURCE_DIR}/src/*.h ${CMAKE_SOURCE_DIR}/src/*.hpp)

# Executable
if (WIN32)
    add_executable(${PROJECT_NAME} ${src})
elseif (APPLE)
    add_executable(${PROJECT_NAME} ${src})
    set(CMAKE_OSX_ARCHITECTURES "x86_64")
endif()

# Librairies
if (MINGW)
    target_link_libraries(${PROJECT_NAME} "GLFW")
    target_link_libraries(${PROJECT_NAME} "OpenGL32")
    target_link_libraries(${PROJECT_NAME} "noise")
    target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/dep/libs/fi/lib-mingw/FreeImage.lib")
elseif (APPLE)
    find_library(OPENGL OpenGL)
    target_link_libraries(${PROJECT_NAME} "${OPENGL}")
    find_library(COCOA Cocoa)
    target_link_libraries(${PROJECT_NAME} "${COCOA}")
    find_library(IOKIT IOKit)
    target_link_libraries(${PROJECT_NAME} "${IOKIT}")
    target_link_libraries(${PROJECT_NAME} "GLFW")
    target_link_libraries(${PROJECT_NAME} "freeimage")
    target_link_libraries(${PROJECT_NAME} "noise")
endif()

# Copy dll to output directory
if (MINGW)
    copy_dll("fi/lib-mingw/FreeImage.dll")
endif()