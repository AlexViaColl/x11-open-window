#include <stdbool.h>
#include <X11/Xlib.h>

int main() {
    Display *display = XOpenDisplay(NULL);
    
    Window window = XCreateSimpleWindow(
        display,
        XDefaultRootWindow(display),    // parent
        0, 0,                           // x, y
        800, 600,                       // width, height
        0,                              // border width
        0x00000000,                     // border color
        0x00000000                      // background color
    );
    
    XStoreName(display, window, "Amazing X11 Window");
    
    XSelectInput(display, window, KeyPressMask|KeyReleaseMask);
    
    XMapWindow(display, window);
    
    bool quit = false;
    while (!quit) {
        while (XPending(display) > 0) {
            XEvent event = {0};
            XNextEvent(display, &event);
            if (event.type == KeyPress) {
                quit = true;
            }
        }
        
        // Do your application work here
    }
    
    XCloseDisplay(display);
}
