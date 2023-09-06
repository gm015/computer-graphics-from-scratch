
#include "header.h"

int main() {


  Display *dsp = XOpenDisplay(NULL);
  if (!dsp) return 1;


  int screenNumber = DefaultScreen(dsp);
  unsigned long white = WhitePixel(dsp,screenNumber);
  unsigned long black = BlackPixel(dsp,screenNumber);


  Window win = XCreateSimpleWindow(dsp,
                               DefaultRootWindow(dsp),
                               50, 50,   // origin
                               1200, 1200, // size
                               10, black, // border
                               white);  // backgd

  XMapWindow(dsp, win);

  long eventMask = StructureNotifyMask;
  XSelectInput(dsp, win, eventMask);

  XEvent evt;
  do {
    XNextEvent(dsp, &evt);   // calls XFlush
  } while (evt.type != MapNotify);


  GC gc = XCreateGC(dsp, win,
                     0,        // mask of values
                     NULL);   // array of values
  XSetForeground(dsp, gc, black);


  XDrawLine(dsp, win, gc, 200, 200, 500, 500);
  XDrawLine(dsp, win, gc, 200, 500, 500, 200);
  XDrawString(dsp, win, gc, 600, 600, "click to EXIT", 13);
  XDrawImageString(dsp, win, gc, 600, 700, "click to EXIT", 13);


  eventMask = ButtonPressMask | ButtonReleaseMask;
  XSelectInput(dsp,win,eventMask); // override prev
 
  do {
    XNextEvent(dsp, &evt);   // calls XFlush()
  } while(evt.type != ButtonRelease);


  XDestroyWindow(dsp, win);
  XCloseDisplay(dsp);

  return 0;
}

