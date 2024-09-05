set(DEPS_DIR ${CMAKE_SOURCE_DIR}/deps)

set(SDL_DIR ${DEPS_DIR}/SDL)
set(SDL_IMAGE_DIR ${DEPS_DIR}/SDL_image)

set(GLM_INCLUDE_DIR ${DEPS_DIR}/glm/glm)

set(EMILY_PROMISE_DIR ${DEPS_DIR}/EmilyPromise)

set(SDL_BUILD_CONFIG Debug)

if (WIN32)
    set(SDL_LIB_DIR ${SDL_DIR}/build/${SDL_BUILD_CONFIG})
    set(SDL_IMAGE_LIB_DIR ${SDL_IMAGE_DIR}/build/${SDL_BUILD_CONFIG})
    set(SDL_LIB ${SDL_LIB_DIR}/SDL3.dll)
    set(SDL_IMAGE_LIB ${SDL_IMAGE_LIB_DIR}/SDL3_image.dll)
else()
    set(SDL_LIB_DIR ${SDL_DIR}/build)
    set(SDL_IMAGE_LIB_DIR ${SDL_IMAGE_DIR}/build)
    set(SDL_LIB ${SDL_LIB_DIR}/libSDL3.so)
    set(SDL_IMAGE_LIB ${SDL_IMAGE_LIB_DIR}/libSDL3_image.so)
endif()

message(SDL Directory: ${SDL_DIR})
message(SDL Libary Directory: ${SDL_LIB_DIR})
message(SDL_image Directory: ${SDL_IMAGE_DIR})
message(SDL_image Libary Directory: ${SDL_IMAGE_LIB_DIR})
