#ifndef PAINTER_H
#define PAINTER_H

#include <windows.h>

struct Color3 {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct Context {
    HWND hWnd;
};


class Canvas{
public:
    int nx;
    int ny;
    int channel;
    BITMAPINFO bmi;
    unsigned char *bitmap;
public:
    Canvas(int x, int y);  

};


class
Painter {
private:
    int nx;
    int ny;
    Context cnt;
    Canvas *cas;
public:
    Painter(HWND hWnd, int x, int y);
    ~Painter();
    void drawDot(int x, int y, Color3 c);
    void drawLine();
    void update();
};


#endif
