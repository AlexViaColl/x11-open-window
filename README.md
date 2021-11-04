# xlib-simple-window

A simple skeleton for a GUI application using X11.
Check out this [post](https://www.alexvia.com/post/xlib_opening_window/) for a more in depth explanation.


## Quickstart

The only dependencies are:
- C compiler (I will be using gcc)
- pkg-config
- X11 development package

To compile the program just run:

```
gcc -o x11_window `pkg-config --libs x11` x11_window.c
```
