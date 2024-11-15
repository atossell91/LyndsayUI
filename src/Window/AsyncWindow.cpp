#include "Window/AsyncWindow.h"

#include <thread>
#include <chrono>

#include <iostream>

#include <SDL3/SDL.h>

using namespace LyndsayUI;

//  Declare functions here
void AsyncWindow::windowLoop() {
    while (isRunning) {
        // While events are in the queue (an inner loop)
        //    Add the event to the window's event handling subsystem
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepDelay));
    }
}

AsyncWindow::~AsyncWindow() {
    isRunning = false;
    if (windowThread != nullptr && windowThread->joinable()) {
        windowThread->join();
    }
}
