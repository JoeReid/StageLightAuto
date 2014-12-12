//compile with gcc -Wall linux.c -o linux -lX11
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>

int main()
{
    XColor c;
    Display *d = XOpenDisplay((char *) NULL);

    int x=0;  // Pixel x 
    int y=0;  // Pixel y

    XImage *image;
    image = XGetImage (d, RootWindow (d, DefaultScreen (d)), x, y, 1, 1, AllPlanes, XYPixmap);
    c.pixel = XGetPixel (image, 0, 0);
    XFree (image);
    XQueryColor (d, DefaultColormap(d, DefaultScreen (d)), &c);

    printf("#%x%x%x\n", c.red/256, c.green/256, c.blue/256);

    return 0;
}
