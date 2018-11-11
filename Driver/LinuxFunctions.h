#ifndef LINUXFUNCTIONS_H
#define LINUXFUNCTIONS_H

#ifdef linux

#include "memory.h"
#include <iostream>
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>

namespace X11 {
    static Display* display;

    void openDisplay();
    void closeDisplay();

    void mouseSetButtonState(int button, int state);

    void mouseDownLeft();
    void mouseUpLeft();

    void mouseDownRight();
    void mouseUpRight();

    void moveCursor(int dx, int dy);

    void downKey(int button);
    void upKey(int button);
}

#endif // linux

#endif // LINUXFUNCTIONS_H
