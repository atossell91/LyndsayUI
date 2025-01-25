#include "SDLLyndsayDependencyFactory.h"

#include <memory>
#include <iostream>

#include "Utilities.h"
#include "Window/SDLWindowFactory.h"
#include "Event/EventQueue.h"
#include "Event/ThreadEventManager.h"
#include "Event/SDLEventManager.h"
#include "Event/WindowEventCoordinator.h"
#include "Event/SDLWindowEventManagerFactory.h"
#include "Window/CustomWindowFactory.h"

using namespace NSLyndsayUI;

void SDLLyndsayDependencyFactory::setupEvents() {

}

void SDLLyndsayDependencyFactory::build() {
    auto evMgrFac = std::make_unique<SDLWindowEventManagerFactory>();

    // Create a window factory
    std::unique_ptr<IPlatformWindowFactory> platWinFac = std::make_unique<SDLWindowFactory>();
    std::unique_ptr<IWindowEventManagerFactory> platEvMgrFac = std::make_unique<SDLWindowEventManagerFactory>();

    //  Create the thread event manager
    auto evQueue = std::make_unique<EventQueue>();
    auto trMgr = std::make_unique<ThreadEventManager>(
        std::move(evQueue)
    );

    // Create the SDL thread manager
    auto tmpEvMgr = evMgrFac->CreateEventManager();
    auto platMgr = Utilities::CastUniquePtr<IEventManager, SDLEventManager>(std::move(tmpEvMgr));

    // Assemble the executive event processor
    auto evMgr1 = std::make_unique<WindowEventCoordinator>(
        std::move(trMgr),
        std::move(platMgr)
    );

    auto evMgr = std::make_unique<WindowEventCoordinator>(
        std::move(trMgr),
        std::move(platMgr)
    );

    eventProcessor = std::move(evMgr);
}

std::unique_ptr<CustomWindowFactory> SDLLyndsayDependencyFactory::GetCustomWindowFactory() {
    auto platWinFac = std::make_unique<SDLWindowFactory>();
    auto custWinFac = std::make_unique<CustomWindowFactory>(std::move(platWinFac));

    return std::move(custWinFac);
}
