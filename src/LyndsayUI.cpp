#include "../include/LyndsayUI.h"

#include <thread>
#include <chrono>
#include <list>
#include <iostream>
#include <memory>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "LyndsayUIContext.h"
#include "IUpdateable.h"

#include "Event/SDLEventManager.h"
#include "Event/ThreadEventManager.h"
#include "Event/WindowEventCoordinator.h"
#include "Event/IEventProcessor.h"

#include "MappedIndexResolver.h"

#include "Window/SDLWindowFactory.h"
#include "Window/IWindowFactory.h"

void NSLyndsayUI::LyndsayUI::initSDL() {
    if (!SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO)) {
        std::cout << "SDL Init failed." << std::endl;
    }

    //IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
}

void NSLyndsayUI::LyndsayUI::init() {
    if (!eventManager->GetPlatformEventManager()) {
        std::cout << "ERROR!!" << std::endl;
    }

    eventManager->GetPlatformEventManager()->WindowCloseButtonClicked.AddEventHandler([this](auto d){
        immediateWindows->RemoveWindowById(d.windowId);
    });
    std::cout << "Everybody" << std::endl;

    eventManager->GetPlatformEventManager()->MouseButtonDown.AddEventHandler([this](auto d){
        int index = immediateWindows->GetWindowIndex(d.windowId);
        if (index >= 0) {
            (*immediateWindows)[index]->MouseButtonDown.Raise(d);
        }
    });
    std::cout << "Wants" << std::endl;

    eventManager->GetPlatformEventManager()->MouseButtonUp.AddEventHandler([this](auto d){
        int index = immediateWindows->GetWindowIndex(d.windowId);
        if (index >= 0) {
            (*immediateWindows)[index]->MouseButtonUp.Raise(d);
        }
    });
    std::cout << "To" << std::endl;

    eventManager->GetPlatformEventManager()->MouseMoved.AddEventHandler([this](auto d){
        int index = immediateWindows->GetWindowIndex(d.windowId);
        if (index >= 0) {
            (*immediateWindows)[index]->MouseMoved.Raise(d);
        }
    });
    std::cout << "Rule" << std::endl;

    eventManager->GetPlatformEventManager()->KeyDown.AddEventHandler([this](auto d){
        int index = immediateWindows->GetWindowIndex(d.windowId);
        if (index >= 0) {
            (*immediateWindows)[index]->KeyDown.Raise(d);
        }
    });
    std::cout << "The" << std::endl;

    eventManager->GetPlatformEventManager()->KeyUp.AddEventHandler([this](auto d){
        int index = immediateWindows->GetWindowIndex(d.windowId);
        if (index >= 0) {
            (*immediateWindows)[index]->KeyUp.Raise(d);
        }
    });
    std::cout << "World" << std::endl;

}

void NSLyndsayUI::LyndsayUI::mainLoop() {
    while (!gameContext.ShouldClose &&
            (retainedWindows->size() > 0 ||
            immediateWindows->size() > 0)) {

        //// Process events
        eventManager->ProcessEvents();

        for (auto& win : *immediateWindows) {
            win->Update();
            win->Draw();
        }

        std::this_thread::sleep_for(
            std::chrono::milliseconds(kMainLoopDelay));
    }
}

void NSLyndsayUI::LyndsayUI::Run() {
    mainLoop();
    cleanup();
}

void NSLyndsayUI::LyndsayUI::cleanup() {
    SDL_Quit();
}
