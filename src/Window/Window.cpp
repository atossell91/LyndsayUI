#include "Window/Window.h"

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <exception>

#include <SDL3_image/SDL_image.h>

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glad/glad.h"
#include "../include/ShaderUtilities.h"
#include "../include/Utilities.h"
#include "Drawing/BufferedImage.h"
#include "Event/IEventQueue.h"
#include "Drawing/BufferImageEvent.h"
#include "Drawing/TransformParams.h"

/*
void NSLyndsayUI::Window::init() {
    SDL_GL_MakeCurrent(window, glContext);

    // Seems to require a glContext, otherwise it segfaults
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    //  Register a buffer image event (should do this elesewhere)
    eventProcessor->addEventHandler(
        NSLyndsayUI::EventTypes::BUFFER_IMAGE_EVENT,
        [this](std::unique_ptr<IEvent> event){
            auto ev = std::unique_ptr<BufferImageEvent>(static_cast<BufferImageEvent*>(event.release()));
            BufferedImage img = graphics->BufferImage(ev->getImagePath());//bufferImage(ev->getImagePath());
            ev->getPromise().set(img);
        });


    glViewport(0, 0, width, height);
}

// Only for async windows
void NSLyndsayUI::Window::windowLoop() {
    
    while(windowRunning) {
        SDL_GL_MakeCurrent(window, glContext);

        //while (auto event = eventQueue->getEvent()) {
        //    eventProcessor->processEvent(std::move(event));
        //}

        update();
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
    }
}

// Only for async windows
void NSLyndsayUI::Window::stopLoop() {
    windowRunning = false;
}

void NSLyndsayUI::Window::update() {
    //graphics->Clear();

    SDL_GL_MakeCurrent(window, glContext);
    drawables.DrawAll(graphics.get());

    SDL_GL_SwapWindow(window);
}

NSLyndsayUI::Window::~Window() {
    SDL_DestroyWindow(window);
    //SDL_GL_DestroyContext(glContext);
}

NSLyndsayUI::IEventQueue& NSLyndsayUI::Window::GetEventQueue() {
    if (!eventQueue) {
        throw std::runtime_error("Event Queue is nullptr");
    }

    return *eventQueue;
}

void NSLyndsayUI::Window::AddImageToBuffer(const std::string& path,
    EmilyPromise::Promise<NSLyndsayUI::BufferedImage>& promise) {
    
    //EmilyPromise::Promise<NSLyndsayUI::BufferedImage> promise;
    //auto event = std::make_unique<BufferImageEvent>(promise);
    //event->setImagePath(path);

    //eventQueue->QueueEvent(std::move(event));
}
*/
