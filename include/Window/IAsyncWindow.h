#pragma once

#include <mutex>
#include <condition_variable>

namespace LyndsayUI {
    class IAsyncWindow {
    public:
        virtual ~IAsyncWindow() {}
        //  Public stuff here
        virtual std::mutex& GetMutex() = 0;
        virtual std::condition_variable& GetConditionVariable() = 0;
    };
} // LyndsayUI
