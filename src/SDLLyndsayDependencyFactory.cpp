#include "SDLLyndsayDependencyFactory.h"

#include <memory>

#include "Window/WindowManager.h"
#include "Window/WindowFactory.h"
#include "Window/SDLWindowFactory.h"
#include "Event/EventTent.h"

#include "Event/ThreadEventManager.h"
#include "Event/SDLEventManager.h"
#include "Event/ExecutiveEventProcessor.h"

using namespace LyndsayUI;

//  Declare functions here
std::unique_ptr<IWindowManager> SDLLyndsayDependencyFactory::CreateWindowManager() {

    auto platWinFac = std::make_unique<SDLWindowFactory>();
    auto winFac = std::make_unique<WindowFactory>(std::move(platWinFac));

    auto eventTent = std::unique_ptr<EventTent>();

    auto winMgr = std::make_unique<WindowManager>(
        std::move(winFac),
        std::move(eventTent)
    );

    return std::move(winMgr);
}

std::unique_ptr<IEventProcessor> SDLLyndsayDependencyFactory::CreateEventProcessor() {

    // Need to build an SDL Event Manager and a Thread Event manager for evMgr below
    auto evMgr = std::make_unique<ExecutiveEventProcessor>();

    return std::move(evMgr);
}
