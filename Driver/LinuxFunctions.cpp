#include "LinuxFunctions.h"

void X11::openDisplay()
{
    display = XOpenDisplay(nullptr);
}

void X11::closeDisplay()
{
    XCloseDisplay(display);
}

void X11::mouseSetButtonState(int button, int state)
{
    XEvent event;

    memset(&event, 0x00, sizeof(event));

    event.type = state;
    event.xbutton.button = button;
    event.xbutton.same_screen = True;

    XQueryPointer(display, RootWindow(display, DefaultScreen(display)),
                  &event.xbutton.root, &event.xbutton.window,
                  &event.xbutton.x_root, &event.xbutton.y_root,
                  &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);

    event.xbutton.subwindow = event.xbutton.window;

    while (event.xbutton.subwindow)
    {
        event.xbutton.window = event.xbutton.subwindow;

        XQueryPointer(display, event.xbutton.window,
                      &event.xbutton.root, &event.xbutton.subwindow,
                      &event.xbutton.x_root, &event.xbutton.y_root,
                      &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);
    }

    XSendEvent(display, PointerWindow, True, 0xfff, &event);

    XFlush(display);
}

void X11::mouseDownLeft()
{
    mouseSetButtonState(Button1, ButtonPress);
}

void X11::mouseUpLeft()
{
    mouseSetButtonState(Button1, ButtonRelease);
}

void X11::mouseDownRight()
{
    mouseSetButtonState(Button3, ButtonPress);
}

void X11::mouseUpRight()
{
    mouseSetButtonState(Button3, ButtonRelease);
}

void X11::downKey(int button)
{
    unsigned int keycode;

    keycode = XKeysymToKeycode(display, button);
    XTestFakeKeyEvent(display, keycode, True, 0);
    XFlush(display);
}

void X11::upKey(int button)
{
    unsigned int keycode;

    keycode = XKeysymToKeycode(display, button);
    XTestFakeKeyEvent(display, keycode, False, 0);
    XFlush(display);
}

void X11::moveCursor(int dx, int dy)
{
    Window root = XDefaultRootWindow(display);
    Window ret_root;
    Window ret_child;
    int root_x;
    int root_y;
    int win_x;
    int win_y;
    unsigned int mask;

    XQueryPointer(display, root, &ret_root, &ret_child, &root_x, &root_y,
                  &win_x, &win_y, &mask);

    XSelectInput(display, root, KeyReleaseMask);
    XWarpPointer(display, None, root, 0, 0, 0, 0, root_x + dx, root_y + dy);
    XFlush(display);
}
