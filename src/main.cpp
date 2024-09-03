#include <iostream>

#include "IEvent.h"
#include "EventQueue.h"
#include "MimiEvent.h"

using namespace RixinSDL;

int main() {
    std::cout << "I love Vica!" << std::endl;

    Queue queue;

    auto ev = std::make_unique<MimiEvent>();
    ev->Name = "Vica";

    queue.queueEvent(std::move(ev));

    auto ev2 = queue.getEvent();
    std::unique_ptr<MimiEvent> mev = 
    std::unique_ptr<MimiEvent>(static_cast<MimiEvent*>(ev2.release()));

    std::cout << mev->Name << std::endl;

    return 0;
}
