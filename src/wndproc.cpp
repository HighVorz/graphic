#include <windows.h>
#include <stdio.h>
#include "include/painter.h"

void
paint(HWND hWnd) { 
    Painter p(hWnd, 800, 600);
    Color3 red = {0, 0, 255};
    for(int i=0; i<64; i++){
        p.drawDot(i, i, red);
    }
    p.update();
}

// message processor
LRESULT CALLBACK
WndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam) {
    switch (msgID) {
        
        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        case WM_QUIT:
            break;

        case WM_PAINT:
            paint(hWnd);
            break;

        case WM_LBUTTONDOWN:
            printf("x: %d, y= %d\n", LOWORD(lParam), HIWORD(lParam));
    }

    return DefWindowProc(hWnd, msgID, wParam, lParam);
}
