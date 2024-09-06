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
            BufferedImage img = bufferImage(ev->getImagePath());
            ev->getPromise().set(img);
        });
    
    glViewport(0, 0, width, height);
}

void RixinSDL::Window::windowLoop() {
    int loopCount = 0;

    TransformParams params;
    while(windowRunning) {
        SDL_GL_MakeCurrent(window, glContext);

        while (auto event = eventQueue->getEvent()) {
            eventProcessor->processEvent(std::move(event));
        }
        
        params.rotateDegrees += 0.0f;//1.2f;
        graphics->Clear();
        //graphics->DrawRectangle(params);
        graphics->DrawSpiral(params);

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

RixinSDL::BufferedImage RixinSDL::Window::bufferImage(const std::string& imgPath) {
    SDL_GL_MakeCurrent(window, glContext);
    
    SDL_Surface* sfc = IMG_Load(imgPath.c_str());

    if (!sfc) {
        std::cout << "Failed to load image" << std::endl;
    }

    SDL_assert(sfc);

    RixinSDL::Utilities::FlipImageSurface(sfc);
    
    GLuint tex;
    glGenTextures(1, &tex);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    auto deets = SDL_GetPixelFormatDetails(sfc->format);
    
    int bytesPerPixel = SDL_BYTESPERPIXEL(sfc->format);

    int type = bytesPerPixel > 3 ? GL_RGBA : GL_RGB;

    glTexImage2D(GL_TEXTURE_2D, 0, type, sfc->w, sfc->h, 0, type, GL_UNSIGNED_BYTE, sfc->pixels);

    RixinSDL::BufferedImage ref(tex, sfc->w, sfc->h);
    SDL_DestroySurface(sfc);
    return ref;
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
