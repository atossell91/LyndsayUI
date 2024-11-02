# Events

## Adding an event (compile time)
1. Add a new class in `include/Event/EventSpace.h`
2. Add a new event ID in `include/Event/EventTypes.h`
3. Register the event
    1. Open `src/RixinSDL.cpp`
    2. Find the `registerEvents()` function
    3. Register the event ID and a new event factory (function)
4. Add event routing logic in `src/Event/EventRouter.cpp`

