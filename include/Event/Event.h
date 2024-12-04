#pragma once

#include <list>
#include <memory>
#include <functional>
#include <algorithm>

namespace NSLyndsayUI {
    template <typename T>
    class Event {
    using HandlerFunc = std::function<void(T)>;
    private:
        //  Private stuff here
        std::list<HandlerFunc> handlers;
        Event& operator=(Event&) = delete;
        Event& operator=(Event&&) = delete;
    public:
        //  Public stuff here
        void Raise(T data) {
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
