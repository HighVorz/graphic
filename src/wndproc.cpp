#include <stdio.h>
#include "Painter/include/painter.h"
#include "include/wndbase.h"

#define rgb(b, g, r) {r, g, b}

void
paint(HWND hWnd) {
    // Painter p(hWnd, 800, 600);
    // Color3 red = {0, 0, 255};
    // for(int i=0; i<64; i++){
    //     p.drawDot(i, i, red);
    // }
    // p.update();
}

Painter* p;
Color3 red = rgb(255, 0, 0);

void
test1(int x, int y) {
    p->drawDot(1200 - y, x, red);
    p->update();
}

void
test2(int x, int y) {
    printf("x=%d, y=%d\n", x, y);
    p->drawDot(x, 600-y, red);
    p->update();
}

void
test3(int x, int y) {
    for (int i = 0; i < 600; i++) {
        p->drawDot(2, i, red);
        p->drawDot(i, 50, red);
    }
    p->update();
}

// message processor
LRESULT CALLBACK
WndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam) {
    switch (msgID) {
        case WM_CREATE:
            p = new Painter(hWnd, 800, 600);
            // test3(LOWORD(lParam), HIWORD(lParam));
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        case WM_QUIT:
            break;

        // case WM_PAINT:
        //     paint(hWnd);
        //     break;

            // case WM_MOUSEMOVE:
            //     test2(LOWORD(lParam), HIWORD(lParam));
            //     break;

        case WM_LBUTTONDOWN:
            test2(LOWORD(lParam), HIWORD(lParam));
            break;
            /*
            define a message RECIVE_MOUSE, to store mouse message

            if(receive_flag){
                queue.push(message);
            }

            */
    }
    return DefWindowProc(hWnd, msgID, wParam, lParam);
}
