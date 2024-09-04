#pragma once

#include <mutex>
#include <condition_variable>

namespace RixinSDL {
    template<typename T>
    class promise {
    private:
        //  Private stuff here
        std::mutex mutex;
        std::condition_variable cv;
        T data;
        bool isSet = false;
    public:
        //  Public stuff here
        promise() :
        lock{std::unique_lock<std::mutex>(mutex, std::defer_lock)} 
        {}
        void setValue(T value) {
            {
                std::lock_guard<std::mutex> lock;
                data = value;
                isSet = true;
            }
            cv.notify_one();
        }

        T await() {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, [this]{ return isSet; });
            return std::move(data);
        }
    };
} // RixinSDL
