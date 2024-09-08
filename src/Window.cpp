#include "../include/Window.h"

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
#include "../include/ShaderUtils.h"
#include "../include/Utilities.h"
#include "../include/BufferedImage.h"
#include "../include/mckayla.h"
#include "IEventQueue.h"
#include "IEventProcessor.h"
#include "BufferImageEvent.h"
#include "EventTypes.h"
#include "TransformParams.h"

void RixinSDL::Window::init() {
    SDL_GL_MakeCurrent(window, glContext);

    // Seems to require a glContext, otherwise it segfaults
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    eventProcessor->addEventHandler(
        RixinSDL::EventTypes::BUFFER_IMAGE_EVENT,
        [this](std::unique_ptr<IEvent> event){
            auto ev = std::unique_ptr<BufferImageEvent>(static_cast<BufferImageEvent*>(event.release()));
            BufferedImage img = graphics->BufferImage(ev->getImagePath());//bufferImage(ev->getImagePath());
            ev->getPromise().set(img);
        });
    
    glViewport(0, 0, width, height);
}

void RixinSDL::Window::windowLoop() {
    int loopCount = 0;

    TransformParams params;
        auto img = graphics->BufferImage("/home/ant/Downloads/beach.jpg");
        Rectangle source(0, 0, 0.5, 0.5);
        Rectangle dest(0, 0, 0.5, 0.5);
    while(windowRunning) {
        SDL_GL_MakeCurrent(window, glContext);

        while (auto event = eventQueue->getEvent()) {
            eventProcessor->processEvent(std::move(event));
        }
        
        params.rotateDegrees += 2.4f;
        graphics->Clear();
        //graphics->DrawRectangle(params);
        graphics->DrawImage(img, source, dest);
        //graphics->DrawSpiral(params);

        update();
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
    }
}

void RixinSDL::Window::update() {
    //graphics->Clear();

    SDL_GL_MakeCurrent(window, glContext);
    for (auto& drawable : drawables) {
        drawable->draw();
    }

    SDL_GL_SwapWindow(window);
}

RixinSDL::Window::~Window() {
    SDL_DestroyWindow(window);
    //SDL_GL_DestroyContext(glContext);
}

void RixinSDL::Window::stopLoop() {
    windowRunning = false;
}

RixinSDL::IEventQueue& RixinSDL::Window::GetEventQueue() {
    if (!eventQueue) {
        throw std::runtime_error("Event Queue is nullptr");
    }

    return *eventQueue;
}

RixinSDL::IEventProcessor& RixinSDL::Window::GetEventProcessor() {
    if (!eventProcessor) {
        throw std::runtime_error("Event Queue is nullptr");
    }

    return *eventProcessor;
}

void RixinSDL::Window::AddImageToBuffer(const std::string& path,
    EmilyPromise::Promise<RixinSDL::BufferedImage>& promise) {
    
    //EmilyPromise::Promise<RixinSDL::BufferedImage> promise;
    auto event = std::make_unique<BufferImageEvent>(promise);
    event->setImagePath(path);

    eventQueue->queueEvent(std::move(event));
}
