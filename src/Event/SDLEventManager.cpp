#include "Event/SDLEventManager.h"

#include <SDL3/SDL.h>
#include <functional>
#include <memory>
#include <thread>

#include "Event/IQueuedEventData.h"
#include "Utils.h"

#include <iostream>

#include "Event/EventData/WindowCloseButtonClickedEventData.h"

using namespace NSLyndsayUI;

//  Declare functions here
void NSLyndsayUI::SDLEventManager::ProcessEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        handleEvent(event);
    }
}

void SDLEventManager::PushEvent(std::unique_ptr<IQueuedEventData> event) {

}

void SDLEventManager::handleEvent(SDL_Event& event) {
    switch (event.type)
    {
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED: {
            // Event
            //auto data = std::make_shared<WindowCloseButtonClickedData>();
            //WindowClosed.Raise(data);
            WindowCloseButtonClickedEventData data;
            data.windowId = event.window.windowID;
            WindowCloseButtonClicked.Raise(data);
            break;
        }
        case SDL_EVENT_KEY_DOWN:
            // Event
            break;

        case SDL_EVENT_KEY_UP:
            // Event
            break;

        case SDL_EVENT_MOUSE_MOTION:
            // Event
            break;

        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            // Event
            break;

        case SDL_EVENT_MOUSE_BUTTON_UP:
            // Event
            break;

        case SDL_EVENT_QUIT:
            // Event
            break;
    }
}
