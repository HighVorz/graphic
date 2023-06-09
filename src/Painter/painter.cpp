#include "include/painter.h"
#include <stdio.h>
#include <omp.h>


Painter::Painter(HWND hWnd, int x, int y, const char* str) {
    cnt.hWnd = hWnd;
    nx = x;
    ny = y;
    strcpy(name, str);
    // cas = new Bitmap((int)(dpi * x), (int)(dpi * y));
    cas = new Bitmap(x, y);
}

Painter::~Painter() {
    delete cas;
}


//get specific message, and process it 


void
Painter::drawDot(int x, int y, Color3 c) {
    Color3* bitmap = (Color3*)cas->bitmap;
    bitmap[x + y * cas->nx] = c;
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
		cas->bmi.bmiHeader.biHeight, cas->bitmap, (BITMAPINFO*)&cas->bmi.bmiHeader,
		DIB_RGB_COLORS, SRCCOPY);
}

Bitmap::Bitmap(int x, int y) {
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

        bitmap = new unsigned char[nx * ny * channel];
        memset(bitmap, 255, nx * ny * channel);

}
