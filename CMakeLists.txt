cmake_minimum_required(VERSION 3.11.2)

project(RebeccaUI)

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

add_library(RebeccaUI SHARED
    ${SRC}/glad.c
    ${SRC}/Event/EventTent.cpp
    ${SRC}/Window/Window.cpp
    ${SRC}/ShaderUtils.cpp
    ${SRC}/Utilities.cpp
    ${SRC}/Image.cpp
    ${SRC}/Window/WindowManager.cpp
    ${SRC}/RebeccaUI.cpp
    ${SRC}/Event/EventQueue.cpp
    ${SRC}/Event/EventFactory.cpp
    ${SRC}/GlGraphics.cpp
    ${SRC}/Event/SDLEventManager.cpp
    ${SRC}/Utils.cpp
    ${SRC}/Window/AsyncWindow.cpp
    ${SRC}/Window/WindowFactory.cpp
    ${SRC}/Window/SyncWindow.cpp
    ${SRC}/Window/SDLWindowFactory.cpp
    ${SRC}/Window/SDLWindow.cpp
    ${SRC}/Window/WindowBase.cpp
    ${SRC}/Event/EventPoller.cpp
    #ADD_CPP - DO NOT MODIFY THIS LINE
)

target_link_libraries(RebeccaUI
    ${SDL_LIB}
    ${SDL_IMAGE_LIB}
)

add_executable(RebeccaTest
    ${CMAKE_SOURCE_DIR}/test-program/main.cpp
)

target_link_libraries(RebeccaTest
    ${CMAKE_SOURCE_DIR}/build/libRebeccaUI.so
    ${SDL_LIB}
    ${SDL_IMAGE_LIB}
)
