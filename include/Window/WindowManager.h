#include <list>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "Window/Window.h"
#include "Window/IWindow.h"
#include "Window/WindowThread.h"
#include "IMappableIndexResolver.h" 

#include "Event/IEvent.h"
#include "Event/IEventTent.h"
#include "Event/IEventReceiver.h"

namespace RebeccaUI
{
    class WindowManager {
     private:
        std::list<std::unique_ptr<IWindow>> windows;
        std::unique_ptr<Window> singleWindow;
        std::mutex mutex;
        std::condition_variable cv;
        std::unique_ptr<Window> windowFactory();
        std::unique_ptr<IEventTent> eventTent;
        std::shared_ptr<IMappableIndexResolver> windowIndexResolver;

        int currentWindowId = 1;

        void registerEvents();
     public:
        WindowManager(
            std::shared_ptr<IMappableIndexResolver> resolver,
            std::unique_ptr<IEventTent> evTent) : windowIndexResolver {resolver}, eventTent{std::move(evTent)} {
                registerEvents();
            }
            
        void AddSingleWindow(); 
        void AddWindow(const std::string& name, int width, int height);
        IEventReceiver* GetEventReceiver() { return eventTent.get(); }
        void CloseWindow(int windowId);
        Window* GetWindow();
        Window* GetWindow(int windowId);
        int GetNumWindows() const { return windows.size(); }
        bool IsNoWindows() const;
        void UpdateAll();
    };
} // namespace RebeccaUI
