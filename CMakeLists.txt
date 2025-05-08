cmake_minimum_required(VERSION 3.12.0)

project(LyndsayUI)

#include(Required_Dirs.cmake)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC ${CMAKE_SOURCE_DIR}/src)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
find_package(glm REQUIRED CONFIG)
find_package(SDL3_image REQUIRED CONFIG COMPONENTS SDL3_image-shared)
find_package(Freetype REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    /usr/include/SDL3_image/SDL_image.h
    /usr/include/freetype2
)

add_library(LyndsayUI SHARED
    ${SRC}/glad.c
    ${SRC}/ShaderUtils.cpp
    ${SRC}/Utilities.cpp
    ${SRC}/Image.cpp
    ${SRC}/LyndsayUI.cpp
    ${SRC}/Event/EventQueue.cpp
    ${SRC}/GlGraphics.cpp
    ${SRC}/Event/SDLEventManager.cpp
    ${SRC}/Window/SDLWindowFactory.cpp
    ${SRC}/Window/SDLWindow.cpp
    ${SRC}/Window/WindowBase.cpp
    ${SRC}/Event/ThreadEventManager.cpp
    ${SRC}/SDLLyndsayDependencyFactory.cpp
    ${SRC}/Event/SDLWindowEventManagerFactory.cpp
    ${SRC}/Drawing/PathDrawer.cpp
    ${SRC}/LinuxSpecificFunctions.cpp
    ${SRC}/WindowsSpecificFunctions.cpp
    ${SRC}/Drawing/FreetypeTextRenderer.cpp
    ${SRC}/Controls/Button.cpp
    ${SRC}/Controls/Label.cpp
    ${SRC}/Controls/Textbox.cpp
    #ADD_CPP - DO NOT MODIFY THIS LINE
)

target_link_libraries(LyndsayUI
    PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
        Freetype::Freetype
)


add_executable(LyndsayTest
    ${CMAKE_SOURCE_DIR}/test-program/main.cpp
)

target_link_libraries(LyndsayTest
    ${CMAKE_SOURCE_DIR}/build/libLyndsayUI.so
    SDL3::SDL3
    SDL3_image::SDL3_image
    Freetype::Freetype
)
