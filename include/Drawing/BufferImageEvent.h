#pragma once

#include <string>

#include "Event/EventBase.h"
#include "Event/EventTypes.h"
#include "Promise.h"
#include "BufferedImage.h"

namespace LyndsayUI {
    class BufferImageEvent : public EventBase {
    private:
        //  Private stuff here
        std::string imgPath;
        EmilyPromise::Promise<LyndsayUI::BufferedImage>& imgPromise;
    public:
        //  Public stuff here
        BufferImageEvent(EmilyPromise::Promise<LyndsayUI::BufferedImage>& promise) : 
        EventBase(LyndsayUI::EventTypes::BUFFER_IMAGE_EVENT),
        imgPromise{promise} {}

        void setImagePath(const std::string& path) { imgPath = path; }
        std::string getImagePath() { return imgPath; }
        EmilyPromise::Promise<LyndsayUI::BufferedImage>& getPromise() { return imgPromise; }
    };
} // LyndsayUI
