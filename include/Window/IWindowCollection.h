#pragma once

#include <vector>

namespace NSLyndsayUI {
    template <typename T, std::enable_if_t<std::is_base_of<CustomWindow, T>::value, bool> = true>
    class IWindowCollection {
    public:
        virtual ~IWindowCollection() {}
        //  Public stuff here
        virtual typename std::vector<std::unique_ptr<T>>::iterator begin() = 0;
        virtual typename std::vector<std::unique_ptr<T>>::iterator end() = 0;
        virtual std::unique_ptr<T>& operator[](int index) = 0;
        virtual void AddWindow(std::unique_ptr<T> window) = 0;
        virtual bool RemoveWindowByIndex(int index) = 0;
        virtual bool RemoveWindowById(int targetId) = 0;
        virtual bool IsEmpty() = 0;
        virtual int size() = 0;
    };
} // NSLyndsayUI
