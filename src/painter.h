#ifndef PAINTER_H
#define PAINTER_H

#include <windows.h>

struct Context {
    HWND hWnd;
};



class Canvas{
public:
    int x;
    int y;
    COLORREF **color;
public:
    Canvas(int x, int y){
        this->x = x;
        this->y = y;
        color = (COLORREF**)new COLORREF*[x];
        for(int i=0; i<y; i++){
            color[i] = (COLORREF*)new COLORREF[y];
        }

        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                color[i][j] = RGB(255, 255, 255);
            }
        }
    }  

    ~Canvas(){
        for(int i=0; i<y; i++){
            delete [] color[i];
        }
        delete [] color;
    }
};


class
Painter {
private:
    int x;
    int y;
    Context cnt;
    Canvas *cas;
public:
    Painter(HWND hWnd, int x, int y);
    ~Painter();
    void drawDot(int x, int y, COLORREF c);
    void drawLine();
    void update();
};


#endif
