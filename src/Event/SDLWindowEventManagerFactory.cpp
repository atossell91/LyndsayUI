#include "Event/SDLWindowEventManagerFactory.h"

#include <memory>

#include "Event/SDLEventManager.h"

using namespace NSLyndsayUI;

//  Declare functions here
std::unique_ptr<AbstractWindowEventManager> SDLWindowEventManagerFactory::CreateEventManager() {
    return std::make_unique<SDLEventManager>();
}
