#pragma once

#include <string>

#include "Event/EventBase.h"
#include "Event/EventTypes.h"
#include "Promise.h"
#include "BufferedImage.h"

namespace RixinSDL {
    class BufferImageEvent : public EventBase {
    private:
        //  Private stuff here
        std::string imgPath;
        EmilyPromise::Promise<RixinSDL::BufferedImage>& imgPromise;
    public:
        //  Public stuff here
        BufferImageEvent(EmilyPromise::Promise<RixinSDL::BufferedImage>& promise) : 
        EventBase(RixinSDL::EventTypes::BUFFER_IMAGE_EVENT),
        imgPromise{promise} {}

        void setImagePath(const std::string& path) { imgPath = path; }
        std::string getImagePath() { return imgPath; }
        EmilyPromise::Promise<RixinSDL::BufferedImage>& getPromise() { return imgPromise; }
    };
} // RixinSDL
