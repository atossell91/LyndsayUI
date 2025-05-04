#include "Controls/Button.h"

#include "Drawing/IGraphics.h"

using namespace NSLyndsayUI;

//  Declare functions here
void Button::Draw(IGraphics* graphics) {
    graphics->DrawRectangle(fillColour, fillParams);
}
