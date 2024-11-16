#pragma once

#include <vector>
#include <memory>

#include "Event/IEventManager.h"

namespace LyndsayUI {
    class ExecutiveEventManager : public IEventManager {
    private:
        //  Private stuff here
        std::vector<std::unique_ptr<IEventManager>> subManagers;
    public:
        //  Public stuff here
        void AddManager(std::unique_ptr<IEventManager> mgr) { subManagers.push_back(std::move(mgr)); }
        void ProcessEvents() { for (auto& mgr : subManagers) mgr->ProcessEvents(); }
    };
} // LyndsayUI
