#include <list>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "Window/IWindowManager.h"
#include "Window/IWindow.h"
#include "Window/ILyndsayWindow.h"
#include "Window/IWindowFactory.h"

#include "Event/IEvent.h"
#include "Event/IEventTent.h"
#include "Event/IEventReceiver.h"

namespace LyndsayUI
{
    class WindowManager : public IWindowManager {
     private:
        std::list<std::unique_ptr<ILyndsayWindow>> windows;
        std::unique_ptr<IWindow> singleWindow;
        std::mutex mutex;
        std::condition_variable cv;

        std::unique_ptr<IWindowFactory> factory;
        std::unique_ptr<IEventTent> eventTent;

        int currentWindowId = 1;

        void registerEvents();
     public:
        WindowManager(
            std::unique_ptr<IWindowFactory> winFactory,
            std::unique_ptr<IEventTent> evTent) : factory{std::move(winFactory)}, eventTent{std::move(evTent)} {
                registerEvents();
            }
            
        void AddSingleWindow(); 
        void AddWindow(const std::string& name, int width, int height);
        IEventReceiver* GetEventReceiver() { return eventTent.get(); }
        void CloseWindow(int windowId);
        IWindow* GetWindow();
        IWindow* GetWindow(int windowId);
        int GetNumWindows() const { return windows.size(); }
        bool IsNoWindows() const;
        void UpdateAll();
        void RecieveEvent(std::unique_ptr<IEvent> event);
    };
} // namespace LyndsayUI
