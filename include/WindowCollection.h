#pragma once

#include <vector>
#include <memory>
#include <type_traits>
#include <iostream>

#include "Window/IWindowCollection.h"
#include "Window/Window.h"

namespace NSLyndsayUI {
    template <typename T, std::enable_if_t<std::is_base_of<Window, T>::value, bool> = true>
    class WindowCollection : public IWindowCollection<T> {
    private:
        //  Private stuff here
        std::vector<std::unique_ptr<T>> windows;
    public:
        //  Public stuff here
        int findWindowIndex(int targetId) {
            for (int n =0; n < windows.size(); ++n) {
                if (windows[n]->GetWindowId() == targetId) {
                    return n;
                }
            }

            return -1;
        }

        typename std::vector<std::unique_ptr<T>>::iterator begin() {
            return windows.begin();
        }

        typename std::vector<std::unique_ptr<T>>::iterator end() {
            return windows.end();
        }

        std::unique_ptr<T>& operator[](int index) {
            return windows[index];
        }

        void AddWindow(std::unique_ptr<T> window) {
            windows.push_back(std::move(window));
        }

        void Klaire() {}

        int GetWindowIndex(int targetWindowId) {
            for (int n =0; n < windows.size(); ++n) {
                int currId = windows[n]->GetWindowId();
                if (targetWindowId == currId) {
                    return n;
                }
            }

            return -1;
        }

        bool RemoveWindowByIndex(int index) {
            if (index < 0 || index > windows.size()) {
                return false;
            }

            auto iter = windows.begin();
            for (int n =0; n < index; ++n) {
                ++iter;
            }

            windows.erase(iter);
            
            return true;
        }

        bool RemoveWindowById(int targetId) {
            auto iter = windows.begin();
            while (iter != windows.end() &&
                (*iter)->GetWindowId() != targetId) {
                    ++iter;
                }

            windows.erase(iter);

            return true;
        }

        bool IsEmpty() {
            return windows.size() < 1;
        }

        int size() {
            return windows.size();
        }
    };
} // NSLyndsayUI
