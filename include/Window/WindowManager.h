#include <list>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "Window/Window.h"
#include "Window/WindowThread.h"

namespace RixinSDL
{
    class WindowManager {
     private:
        std::list<WindowThread> windows;
        std::unique_ptr<Window> singleWindow;
        std::mutex mutex;
        std::condition_variable cv;
        std::unique_ptr<Window> windowFactory();
     public:
        void AddSingleWindow(); 
        void AddWindow(const std::string& name, int width, int height);
        void CloseWindow(int sdlWinId);
        Window* GetWindow();
        Window* GetWindow(int sdlWinId);
        int GetNumWindows() const { return windows.size(); }
        bool IsNoWindows() const;
        void UpdateAll();
    };
} // namespace RixinSDL