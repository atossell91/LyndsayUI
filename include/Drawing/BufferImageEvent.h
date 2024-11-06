#pragma once

#include <string>

#include "Event/EventBase.h"
#include "Event/EventTypes.h"
#include "Promise.h"
#include "BufferedImage.h"

namespace RebeccaUI {
    class BufferImageEvent : public EventBase {
    private:
        //  Private stuff here
        std::string imgPath;
        EmilyPromise::Promise<RebeccaUI::BufferedImage>& imgPromise;
    public:
        //  Public stuff here
        BufferImageEvent(EmilyPromise::Promise<RebeccaUI::BufferedImage>& promise) : 
        EventBase(RebeccaUI::EventTypes::BUFFER_IMAGE_EVENT),
        imgPromise{promise} {}

        void setImagePath(const std::string& path) { imgPath = path; }
        std::string getImagePath() { return imgPath; }
        EmilyPromise::Promise<RebeccaUI::BufferedImage>& getPromise() { return imgPromise; }
    };
} // RebeccaUI
