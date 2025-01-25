cmake_minimum_required(VERSION 3.11.2)

project(LyndsayUI)

include(Required_Dirs.cmake)

set(SRC ${CMAKE_SOURCE_DIR}/src)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${SDL_DIR}/include
    ${SDL_IMAGE_DIR}/include
    ${EMILY_PROMISE_DIR}/include
)

#find_package(SDL3 REQUIRED)
#find_package(SDL3_image REQUIRED)

add_library(LyndsayUI SHARED
    ${SRC}/glad.c
    ${SRC}/Window/Window.cpp
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
    #ADD_CPP - DO NOT MODIFY THIS LINE
)

target_link_libraries(LyndsayUI
    ${SDL_LIB}
    ${SDL_IMAGE_LIB}
)

add_executable(LyndsayTest
    ${CMAKE_SOURCE_DIR}/test-program/main.cpp
)

target_link_libraries(LyndsayTest
    ${CMAKE_SOURCE_DIR}/build/libLyndsayUI.so
    ${SDL_LIB}
    ${SDL_IMAGE_LIB}
)
