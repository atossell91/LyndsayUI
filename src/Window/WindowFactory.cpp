#include "Window/WindowFactory.h"

#include <memory>

#include <SDL3/SDL.h>

#include "Window/IWindow.h"
#include "Window/AsyncWindow.h"
#include "Window/SyncWindow.h"

using namespace RebeccaUI;

//  Declare functions here
std::unique_ptr<IWindow> WindowFactory::CreateSynchronousWindow() {
    auto window = std::unique_ptr<SyncWindow>( new SyncWindow(generateWindowId()) );
}

std::unique_ptr<IWindow> WindowFactory::CreateAsynchronousWindow() {
    auto window = std::unique_ptr<AsyncWindow>( new AsyncWindow(generateWindowId()) );
}
