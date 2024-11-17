#include "Event/SDLEventManagerFactory.h"

#include <memory>

#include "Event/IEventManagerFactory.h"
#include "Event/IEventManager.h"
#include "Event/SDLEventManager.h"
#include "Event/ThreadEventManager.h"
#include "Event/ExecutiveEventManager.h"

using namespace LyndsayUI;

//  Declare functions here
std::unique_ptr<IEventManagerFactory> SDLEventManagerFactory::CreateEventManager() {
}
