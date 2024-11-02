cmake_minimum_required(VERSION 3.11.2)

project(RixinSDL)

include(Required_Dirs.cmake)

set(SRC ${CMAKE_SOURCE_DIR}/src)

# Sub directories
set(EVENT_DIR ${SRC}/Event)
set(WINDOW_DIR ${SRC}/Window)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${SDL_DIR}/include
    ${SDL_IMAGE_DIR}/include
    ${EMILY_PROMISE_DIR}/include
)

#find_package(SDL3 REQUIRED)
#find_package(SDL3_image REQUIRED)

add_library(RixinSDL SHARED
    ${SRC}/glad.c
    ${WINDOW_DIR}/Window.cpp
    ${SRC}/ShaderUtils.cpp
    ${SRC}/Utilities.cpp
    ${SRC}/Image.cpp
    ${WINDOW_DIR}/WindowManager.cpp
    ${SRC}/RixinSDL.cpp
    ${EVENT_DIR}/EventQueue.cpp
    ${EVENT_DIR}/EventFactory.cpp
    ${EVENT_DIR}/EventProcessor.cpp
    ${SRC}/GlGraphics.cpp
    ${WINDOW_DIR}/SingleWindow.cpp
    ${EVENT_DIR}/SDLEventManager.cpp
    ${EVENT_DIR}/EventRouter.cpp
    #ADD_CPP - DO NOT MODIFY THIS LINE
)

target_link_libraries(RixinSDL
    ${SDL_LIB}
    ${SDL_IMAGE_LIB}
)

add_executable(RixinTest
    ${CMAKE_SOURCE_DIR}/test-program/main.cpp
)

target_link_libraries(RixinTest
    ${CMAKE_SOURCE_DIR}/build/libRixinSDL.so
    ${SDL_LIB}
    ${SDL_IMAGE_LIB}
)
