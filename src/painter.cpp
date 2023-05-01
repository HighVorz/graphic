
#include "painter.h"
#include <stdio.h>

Painter::Painter(HWND hWnd, int x, int y) {
    cnt.hWnd = hWnd;
    this->x = x;
    this->y = y;
    cas = (Canvas*)new Canvas(x, y);
}

Painter::~Painter() {
    delete cas;
}

void
Painter::drawDot(int x, int y, COLORREF c) {
    cas->color[x][y] = c;
}

void
Painter::drawLine() {
}

void
Painter::update() {
    PAINTSTRUCT ps = {0};
    HDC hdc = BeginPaint(cnt.hWnd, &ps);

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            SetPixel(hdc, i, j, cas->color[i][j]);
        }
    }
    
    EndPaint(cnt.hWnd, &ps);
}
