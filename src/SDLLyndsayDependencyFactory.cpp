#include "SDLLyndsayDependencyFactory.h"

#include <memory>

#include "Utils.h"
#include "Window/WindowManager.h"
#include "Window/WindowFactory.h"
#include "Window/SDLWindowFactory.h"
#include "Event/EventTent.h"
#include "Event/EventTypes.h"
#include "Event/EventSpace.h"
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

    registerEvents(winMgr.get());

    return std::move(winMgr);
}

std::unique_ptr<IEventProcessor> SDLLyndsayDependencyFactory::CreateEventProcessor() {

    // Both components of the Executive processor share an Event Tent
    auto evTent = createMainEventTent();

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

std::shared_ptr<IEventTent> SDLLyndsayDependencyFactory::createMainEventTent() {

    if (mainEventTent.expired()) {
        auto evTent = std::make_shared<EventTent>();
        mainEventTent = evTent;
        return evTent;
    }
    else {
        return mainEventTent.lock();
    }

}

void SDLLyndsayDependencyFactory::registerEvents(IWindowManager* windowManager) {
    if (mainEventTent.expired()) {
        return;
    }

    mainEventTent.lock()->AddEventResponse(EventTypes::CLOSE_BUTTON_PRESSED_EVENT, [](std::unique_ptr<IEvent> event){

    });
}
