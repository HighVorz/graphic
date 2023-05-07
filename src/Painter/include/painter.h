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


class Bitmap{
public:
    int nx;
    int ny;
    int channel;
    BITMAPINFO bmi;
    unsigned char *bitmap;
public:
    Bitmap(int x, int y);  

};


class
Painter {
private:
    int nx;
    int ny;
    Context cnt;
    Bitmap *cas;
    char name[60];
public:
    Painter(){};
    Painter(HWND hWnd, int x, int y, const char* str);
    ~Painter();
    void drawDot(int x, int y, Color3 c);
    void drawLine();
    void update();
};


#endif
