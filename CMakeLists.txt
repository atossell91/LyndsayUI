cmake_minimum_required(VERSION 3.11.2)

project(RixinSDL)

include(Required_Dirs.cmake)

set(SRC ${CMAKE_SOURCE_DIR}/src)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${SDL_DIR}/include
    ${SDL_IMAGE_DIR}/include
)

#find_package(SDL3 REQUIRED)
#find_package(SDL3_image REQUIRED)

add_library(RixinSDL SHARED
    ${SRC}/glad.c
    ${SRC}/Window.cpp
    ${SRC}/ShaderUtils.cpp
    ${SRC}/Utilities.cpp
    ${SRC}/Image.cpp
    ${SRC}/TextureRepository.cpp
    ${SRC}/EventDispatcher.cpp
    ${SRC}/WindowManager.cpp
    ${SRC}/RixinSDL.cpp
    ${SRC}/mckayla.cpp
    ${SRC}/spiral.cpp
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
