#include "SDLLyndsayDependencyFactory.h"

#include <memory>

#include "Utils.h"
#include "Window/WindowManager.h"
#include "Window/WindowFactory.h"
#include "Window/SDLWindowFactory.h"
#include "Event/EventQueue.h"
#include "Event/ThreadEventManager.h"
#include "Event/SDLEventManager.h"
#include "Event/ExecutiveEventProcessor.h"

using namespace LyndsayUI;

//  Declare functions here
std::unique_ptr<IWindowManager> SDLLyndsayDependencyFactory::CreateWindowManager() {

    // Create a window factory
    auto platWinFac = std::make_unique<SDLWindowFactory>();
    auto winFac = std::make_unique<WindowFactory>(std::move(platWinFac));

    // Assemble
    auto winMgr = std::make_unique<WindowManager>(
        std::move(winFac)
    );

    return std::move(winMgr);
}

std::unique_ptr<IEventProcessor> SDLLyndsayDependencyFactory::CreateEventProcessor() {

    //  Create the thread event manager
    auto evQueue = std::make_unique<EventQueue>();
    auto trMgr = std::make_unique<ThreadEventManager>(
        std::move(evQueue)
    );

    // Create the SDL thread manager
    auto platMgr = std::make_unique<SDLEventManager>();
    platMgr->WindowClosed += [](std::shared_ptr<WindowCloseButtonClickedData> d){
        
    };

    // Assemble the executive event processor
    auto evMgr = std::make_unique<ExecutiveEventProcessor>(
        std::move(trMgr),
        std::move(platMgr)
    );

    return std::move(evMgr);
}