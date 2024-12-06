#include "Window/AsyncWindow.h"

#include <thread>
#include <chrono>

#include <iostream>

#include <SDL3/SDL.h>

using namespace NSLyndsayUI;

//  Declare functions here
void AsyncWindow::windowLoop() {
    while (isRunning) {
        // While events are in the queue (an inner loop)
        //    Add the event to the window's event handling subsystem
        eventProcessor->ProcessEvents();
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepDelay));
    }
}

AsyncWindow::~AsyncWindow() {
    isRunning = false;
    if (windowThread != nullptr && windowThread->joinable()) {
        windowThread->join();
    }
}

void AsyncWindow::Close() {
    std::cout << "Close called on thread " << std::this_thread::get_id() << std::endl;
    isRunning = false;
    windowThread->join();
}
