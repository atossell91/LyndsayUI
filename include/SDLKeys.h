#pragma once

#include <SDL3/SDL.h>
#include "KeyValues.h"

namespace NSLyndsayUI {
    namespace SDLKeys {

    // Populate the namespace here
        KeyValues::KeyValue MapKey(SDL_Keycode SDLKey) {
            switch (SDLKey)
            {
            case SDLK_A:
                return KeyValues::Keyboard_A;
            case SDLK_B:
                return KeyValues::Keyboard_B;
            case SDLK_C:
                return KeyValues::Keyboard_C;
            case SDLK_D:
                return KeyValues::Keyboard_D;
            case SDLK_E:
                return KeyValues::Keyboard_E;
            case SDLK_F:
                return KeyValues::Keyboard_F;
            case SDLK_G:
                return KeyValues::Keyboard_G;
            case SDLK_H:
                return KeyValues::Keyboard_H;
            case SDLK_I:
                return KeyValues::Keyboard_I;
            case SDLK_J:
                return KeyValues::Keyboard_J;
            case SDLK_K:
                return KeyValues::Keyboard_K;
            case SDLK_L:
                return KeyValues::Keyboard_L;
            case SDLK_M:
                return KeyValues::Keyboard_M;
            case SDLK_N:
                return KeyValues::Keyboard_N;
            case SDLK_O:
                return KeyValues::Keyboard_O;
            case SDLK_P:
                return KeyValues::Keyboard_P;
            case SDLK_Q:
                return KeyValues::Keyboard_Q;
            case SDLK_R:
                return KeyValues::Keyboard_R;
            case SDLK_S:
                return KeyValues::Keyboard_S;
            case SDLK_T:
                return KeyValues::Keyboard_T;
            case SDLK_U:
                return KeyValues::Keyboard_U;
            case SDLK_V:
                return KeyValues::Keyboard_V;
            case SDLK_W:
                return KeyValues::Keyboard_W;
            case SDLK_X:
                return KeyValues::Keyboard_X;
            case SDLK_Y:
                return KeyValues::Keyboard_Y;
            case SDLK_Z:
                return KeyValues::Keyboard_Z;
            case SDLK_0:
                return KeyValues::Keyboard_0;
            case SDLK_1:
                return KeyValues::Keyboard_1;
            case SDLK_2:
                return KeyValues::Keyboard_2;
            case SDLK_3:
                return KeyValues::Keyboard_3;
            case SDLK_4:
                return KeyValues::Keyboard_4;
            case SDLK_5:
                return KeyValues::Keyboard_5;
            case SDLK_6:
                return KeyValues::Keyboard_6;
            case SDLK_7:
                return KeyValues::Keyboard_7;
            case SDLK_8:
                return KeyValues::Keyboard_8;
            case SDLK_9:
                return KeyValues::Keyboard_9;
            default:
                return KeyValues::BAD_KEY;
            }
        }
    } // SDLKeys
}
