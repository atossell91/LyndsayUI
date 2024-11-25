#pragma once

#include "Event/IEvent.h"
#include "Event/IEventData.h"

#include <list>
#include <memory>
#include <algorithm>

namespace LyndsayUI {
    template <class T>
    class EventBase : public IEvent<T> {
    using EventData = std::shared_ptr<T>;
    using HandlerFunc = std::function<void(EventData)>;
    private:
        //  Private stuff here
        std::list<HandlerFunc> handlers;
    public:
        //  Public stuff here
        void Raise(std::shared_ptr<T> data) {
            for (auto handler : handlers) {
                handler(data);
            }
        }

        void AddEventHandler(HandlerFunc handler) {
            handlers.push_back(handler);
        }

        void operator+=(HandlerFunc handler) {
            handlers.push_back(handler);
        }

        void operator-=(HandlerFunc handler) {
            handlers.remove_if([handler](HandlerFunc h){
                return &h == &handler;
            });
        }
    };
} // roo
