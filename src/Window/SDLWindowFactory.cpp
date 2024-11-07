#include "Window/SDLWindowFactory.h"

#include <memory>

#include <SDL3/SDL.h>

#include "Window/IWindow.h"

using namespace RebeccaUI;

//  Declare functions here
std::unique_ptr<IWindow> SDLWindowFactory::CreateSynchronousWindow() {
}

std::unique_ptr<IWindow> SDLWindowFactory::CreateAsynchronousWindow() {

}
