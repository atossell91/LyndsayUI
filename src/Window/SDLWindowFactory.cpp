#include "Window/SDLWindowFactory.h"

#include <SDL3/SDL.h>
#include <memory>

#include "Window/SDLWindow.h"

using namespace LyndsayUI;

//  Declare functions here
std::unique_ptr<IWindow> SDLWindowFactory::CreateWindow() {
    SDL_Window* sdlWin = SDL_CreateWindow("Big girls are cute!", 1920, 1080, SDL_WINDOW_OPENGL);
    SDL_GLContext glCon = SDL_GL_CreateContext(sdlWin);
    
    auto win = std::unique_ptr<SDLWindow>(new SDLWindow(sdlWin, glCon));

    return win;
    //return std::move(sdlWindow);
}
