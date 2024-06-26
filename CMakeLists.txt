cmake_minimum_required(VERSION 3.11.2)

project(RixinSDL)

set(SRC ${CMAKE_SOURCE_DIR}/src)

include_directories(${CMAKE_SOURCE_DIR}/include)

#add_subdirectory(${CMAKE_SOURCE_DIR}/SDL)
#add_subdirectory(${CMAKE_SOURCE_DIR}/SDL_image)

#include_directories(${CMAKE_SOURCE_DIR}/SDL/include)
#include_directories(${CMAKE_SOURCE_DIR}/SDL_image/include)

find_package(SDL3)

add_library(RixinSDL
    ${SRC}/RixinSDL.cpp
    ${SRC}/EventDispatcher.cpp
    ${SRC}/Colour.cpp
)
