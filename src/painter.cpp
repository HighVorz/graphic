#include "painter.h"
#include <stdio.h>
#include <omp.h>


Painter::Painter(HWND hWnd, int x, int y) {
    cnt.hWnd = hWnd;
    nx = x;
    ny = y;
    // cas = new Canvas((int)(dpi * x), (int)(dpi * y));
    cas = new Canvas(x, y);
}

Painter::~Painter() {
    delete cas;
}

void
Painter::drawDot(int x, int y, Color3 c) {
    Color3* bitmap = (Color3*)cas->data;
    bitmap[x * cas->nx + y] = c;
}

void
Painter::drawLine() {
}

void
Painter::update() {
    PAINTSTRUCT ps = {0};

    HDC hdc = GetDC(cnt.hWnd);

    StretchDIBits(hdc, 0, 0, cas->bmi.bmiHeader.biWidth,
		cas->bmi.bmiHeader.biHeight, 0, 0, cas->bmi.bmiHeader.biWidth,
		cas->bmi.bmiHeader.biHeight, cas->data, (BITMAPINFO*)&cas->bmi.bmiHeader,
		DIB_RGB_COLORS, SRCCOPY);
}

Canvas::Canvas(int x, int y) {
        nx = x;
        ny = y;
        channel = 3;
        
        bmi = {0};
        bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bmi.bmiHeader.biWidth = nx;
        bmi.bmiHeader.biHeight = ny;
        bmi.bmiHeader.biPlanes = 1;

        bmi.bmiHeader.biBitCount = 24;
        bmi.bmiHeader.biCompression = BI_RGB;
        bmi.bmiHeader.biSizeImage = nx * ny * channel;

        data = new unsigned char[nx * ny * channel];
        memset(data, 255, nx * ny * channel);

}
