#include "SDLLyndsayDependencyFactory.h"

#include <memory>

#include "Window/WindowManager.h"
#include "Window/WindowFactory.h"
#include "Window/SDLWindowFactory.h"
#include "Event/EventTent.h"

#include "Event/EventQueue.h"
#include "Event/ThreadEventManager.h"
#include "Event/SDLEventManager.h"
#include "Event/ExecutiveEventProcessor.h"
#include "Event/EventFactory.h"

using namespace LyndsayUI;

//  Declare functions here
std::unique_ptr<IWindowManager> SDLLyndsayDependencyFactory::CreateWindowManager() {

    // Create a window factory
    auto platWinFac = std::make_unique<SDLWindowFactory>();
    auto winFac = std::make_unique<WindowFactory>(std::move(platWinFac));

    // Create a requisite event tent
    auto eventTent = std::unique_ptr<EventTent>();

    // Assemble
    auto winMgr = std::make_unique<WindowManager>(
        std::move(winFac),
        std::move(eventTent)
    );

    return std::move(winMgr);
}

std::unique_ptr<IEventProcessor> SDLLyndsayDependencyFactory::CreateEventProcessor() {

    // Both components of the Executive processor share an Event Tent
    auto evTent = std::make_shared<EventTent>();

    //  Create the thread event manager
    auto evQueue = std::make_unique<EventQueue>();
    auto trMgr = std::make_unique<ThreadEventManager>(
        std::move(evQueue),
        evTent
    );

    // Create the SDL thread manager
    auto evFac = std::make_shared<EventFactory>();
    auto platMgr = std::make_unique<SDLEventManager>(
        evFac,
        evTent
    );

    // Assemble the executive event processor
    auto evMgr = std::make_unique<ExecutiveEventProcessor>(
        std::move(trMgr),
        std::move(platMgr)
    );

    return std::move(evMgr);
}
