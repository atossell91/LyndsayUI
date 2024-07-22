cmake_minimum_required(VERSION 3.11.2)

project(RixinSDL)

include(SDLDirs.cmake)

set(SRC ${CMAKE_SOURCE_DIR}/src)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${SDL_DIR}/include
    ${SDL_IMAGE_DIR}/include
)

#find_package(SDL3 REQUIRED)
#find_package(SDL3_image REQUIRED)

add_library(RixinSDL
    ${SRC}/glad.c
    ${SRC}/Window.cpp
    ${SRC}/ShaderUtils.cpp
    ${SRC}/Utilities.cpp
    ${SRC}/Image.cpp
    ${SRC}/TextureRepository.cpp
    ${SRC}/EventDispatcher.cpp
    ${SRC}/WindowManager.cpp
    ${SRC}/RixinSDL.cpp
)

target_link_libraries(RixinSDL
    ${SDL_LIB}
    ${SDL_IMAGE_LIB}
)
