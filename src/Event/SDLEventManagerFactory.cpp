#include "Event/SDLEventManagerFactory.h"

#include <memory>

#include "Event/SDLEventManager.h"

using namespace LyndsayUI;

//  Declare functions here
std::unique_ptr<IEventManager> SDLEventManagerFactory::CreateEventManager() {
    return std::make_unique<SDLEventManager>();
}
