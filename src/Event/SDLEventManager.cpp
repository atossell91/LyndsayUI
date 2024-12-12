#include "Event/SDLEventManager.h"

#include <SDL3/SDL.h>
#include <functional>
#include <memory>
#include <thread>

#include "Event/IQueuedEventData.h"
#include "Utils.h"

#include <iostream>

#include "Event/EventData/WindowCloseButtonClickedEventData.h"
#include "Event/EventData/MouseMovedEventData.h"
#include "Event/EventData/MouseButtonEventData.h"
#include "Event/EventData/KeyboardEventData.h"
#include "SDLKeys.h"

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
            KeyboardEventData keyDownData;
            keyDownData.windowId = event.window.windowID;
            keyDownData.key = SDLKeys::MapKey(event.key.key);
            KeyDown.Raise(keyDownData);
            break;

        case SDL_EVENT_KEY_UP:
            // Event
            KeyboardEventData keyUpData;
            keyUpData.windowId = event.window.windowID;
            keyUpData.key = SDLKeys::MapKey(event.key.key);
            KeyUp.Raise(keyUpData);
            break;

        case SDL_EVENT_MOUSE_MOTION:
            // Event
            MouseMovedEventData mouseMovedData;
            mouseMovedData.windowId = event.window.windowID;
            mouseMovedData.MouseX = event.motion.x;
            mouseMovedData.MouseY = event.motion.y;
            MouseMoved.Raise(mouseMovedData);
            break;

        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            // Event
            MouseButtonEventData mouseButtonDownData;
            mouseButtonDownData.windowId = event.window.windowID;
            mouseButtonDownData.MouseButtonId = event.button.button;
            mouseButtonDownData.MouseX = event.button.x;
            mouseButtonDownData.MouseY = event.button.y;
            MouseButtonDown.Raise(mouseButtonDownData);
            break;

        case SDL_EVENT_MOUSE_BUTTON_UP:
            // Event
            MouseButtonEventData mouseButtonUpData;
            mouseButtonUpData.windowId = event.window.windowID;
            mouseButtonUpData.MouseButtonId = event.button.button;
            mouseButtonUpData.MouseX = event.button.x;
            mouseButtonUpData.MouseY = event.button.y;
            MouseButtonUp.Raise(mouseButtonUpData);
            break;

        case SDL_EVENT_QUIT:
            // Event
            break;
    }
}
