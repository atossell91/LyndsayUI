#pragma once

#include <memory>
#include <functional>

namespace LyndsayUI {
    template <class T>
    class IEvent {
    public:
        using EventData = std::shared_ptr<T>;
        using HandlerFunc = std::function<void(EventData)>;

        virtual ~IEvent() {}
        //  Public stuff here
        virtual void Raise(EventData data) = 0;
        virtual void AddEventHandler(HandlerFunc handler) = 0;
        virtual void operator+=(HandlerFunc handler) = 0;
        virtual void operator-=(HandlerFunc handler) = 0;
    };
} // roo
