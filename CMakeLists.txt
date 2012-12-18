cmake_minimum_required(VERSION 2.6)

# Configuration
project("cub")
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# Ouput directories
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# Compilation flags
if (MSVC)
    set(CMAKE_CXX_FLAGS "-WX -EHsc")
    #set(CMAKE_SHARED_LINKER_FLAGS ${CMAKE_SHARED_LINKER_FLAGS} "/NODEFAULTLIBS:MSVCRT")
    #set(CMAKE_CXX_FLAGS "-W 2 -WX -EHsc")
else()
    set(CMAKE_CXX_FLAGS "-Wall")
    #set(CMAKE_CXX_FLAGS "-Wall -Werror")
endif()

# Include and headers
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/dep/include)
if (WIN32)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/glfw/lib-msvc100)
elseif (APPLE)
    link_directories(${CMAKE_SOURCE_DIR}/dep/libs/glfw/lib-cocoa)
endif()

# Source files
file(GLOB_RECURSE src ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/*.c ${CMAKE_SOURCE_DIR}/src/*.h ${CMAKE_SOURCE_DIR}/src/*.hpp)

# Executable
if (WIN32)
    add_executable(${PROJECT_NAME} ${src})
    #add_executable(${PROJECT_NAME} WIN32 ${src})
    #set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS /ENTRY:"mainCRTStartup")
elseif (APPLE)
    add_executable(${PROJECT_NAME} ${src})
    set(CMAKE_OSX_ARCHITECTURES "x86_64")
endif()

# Librairies
if (WIN32)
    target_link_libraries(${PROJECT_NAME} "OpenGL32")
    target_link_libraries(${PROJECT_NAME} "GLFW")
elseif (APPLE)
    find_library(OPENGL OpenGL)
    target_link_libraries(${PROJECT_NAME} "${OPENGL}")
    find_library(COCOA Cocoa)
    target_link_libraries(${PROJECT_NAME} "${COCOA}")
    find_library(IOKIT IOKit)
    target_link_libraries(${PROJECT_NAME} "${IOKIT}")
    target_link_libraries(${PROJECT_NAME} "GLFW")
endif()


# Custom commands
#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD        # Adds a post-build event to MyTest
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
#        "${CMAKE_SOURCE_DIR}/ext/assimp/bin/assimp_release-dll_win32/Assimp32.dll"      # <--this is in-file
#        $<TARGET_FILE_DIR:${PROJECT_NAME}>)                 # <--this is out-file path