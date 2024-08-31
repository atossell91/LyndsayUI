#include <list>
#include <string>
#include <memory>

#include "../include/Window.h"

namespace RixinSDL
{
    class WindowManager {
     private:
        std::list<std::unique_ptr<Window>> windows;
     public:
        void AddWindow(const std::string& name, int width, int height);
        void CloseWindow(int sdlWinId);
        int GetNumWindows() const { return windows.size(); }
        void UpdateAll();
    };
} // namespace RixinSDL
