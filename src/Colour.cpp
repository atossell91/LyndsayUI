#include "../include/Colour.h"

#include <string.h>

Colour::Colour Colour::FromName(const char* name) {
        Colour c;
        c.Alpha = 255;
        if (strcmp(name, "red")) {
            c.Red = 255;
            c.Green = 0;
            c.Blue = 0;
        }
        else if (strcmp(name, "green")) {
            c.Red = 0;
            c.Green = 255;
            c.Blue = 0;
        }
        else if (strcmp(name, "blue")) {
            c.Red = 0;
            c.Green = 0;
            c.Blue = 255;
        }
        else if (strcmp(name, "hotpink")) {
            c.Red = 255;
            c.Green = 105;
            c.Blue = 180;
        }
        else if (strcmp(name, "white")) {
            c.Red = 255;
            c.Green = 255;
            c.Blue = 255;
        }
        else {
            c.Red = 0;
            c.Green = 0;
            c.Blue = 0;
        }

        return c;
}
