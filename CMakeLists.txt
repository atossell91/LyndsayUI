cmake_minimum_required(VERSION 3.11.2)

project(RixinSDL)

set(SRC ${CMAKE_SOURCE_DIR}/src)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/SDL)

include_directories(${CMAKE_SOURCE_DIR}/SDL/include)

add_library(RixinSDL
    ${SRC}/RixinSDL.cpp
    ${SRC}/EventDispatcher.cpp
    ${SRC}/Colour.cpp
)
