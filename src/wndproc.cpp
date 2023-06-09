#include <stdio.h>

#include "Painter/include/painter.h"
#include "include/wndbase.h"

#define rgb(b, g, r) {r, g, b}

enum {
    ID_FILE_NEW = 101,
    ID_FILE_OPEN,
    ID_FILE_EXIT,

    ID_COLOR_RED,
    ID_COLOR_BLUE,
    ID_COLOR_GREEN,
};

int painter_num = 0;
const int painter_maxnum = 10;

Painter painter_mannager[painter_maxnum];
Painter *cur_canvas;

Color3 red = rgb(255, 0, 0);
Color3 green = rgb(0, 255, 0);
Color3 blue = rgb(0, 0, 255);

Color3 *color = &red;

void refresh(){
    cur_canvas->update();
}

void
test1(int x, int y) {
    
}


void
test2(int x, int y) {
    cur_canvas->drawDot(x, y, *color);
    cur_canvas->update();
}

void
test3(int x, int y) {
    for (int i = 0; i < 600; i++) {
        cur_canvas->drawDot(2, i, *color);
        cur_canvas->drawDot(i, 50, *color);
    }
    cur_canvas->update();
}

// message processor
LRESULT CALLBACK
WndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam) {
    switch (msgID) {
        case WM_CREATE:
            cur_canvas = new Painter(hWnd, 800, 600, "default");
            // painter_mannager[0] = Painter(hWnd, 800, 600, "default");
            // cur_canvas = &painter_mannager[0];
            // painter_num++;
            
            
            //set menu
            HMENU hMenu, FileMenu, ColorMenu;
            hMenu = CreateMenu();

            FileMenu = CreatePopupMenu();
            AppendMenu(FileMenu, MF_STRING, ID_FILE_NEW, "&New");
            AppendMenu(FileMenu, MF_STRING, ID_FILE_OPEN, "&Open");
            AppendMenu(FileMenu, MF_SEPARATOR, 0, NULL);
            AppendMenu(FileMenu, MF_STRING, ID_FILE_EXIT, "E&xit");

            ColorMenu = CreatePopupMenu();
            AppendMenu(ColorMenu, MF_STRING, ID_COLOR_RED, "&Red");
            AppendMenu(ColorMenu, MF_STRING, ID_COLOR_BLUE, "&Blue");
            AppendMenu(ColorMenu, MF_STRING, ID_COLOR_GREEN, "&Green");

            
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)FileMenu, "&File");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)ColorMenu, "&Color");

            SetMenu(hWnd, hMenu);
            break;

        case WM_PAINT:
            refresh();
            break;

        case WM_COMMAND:
            switch (LOWORD(wParam)){
                case ID_COLOR_GREEN:
                    color = &green;
                    break;
                
                case ID_COLOR_BLUE:
                    color = &blue;
                    break;
                
                case ID_COLOR_RED:
                    color = &red;
                    break;
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        case WM_QUIT:
            break;


        case WM_LBUTTONDOWN:
            test2(LOWORD(lParam), 600-HIWORD(lParam));
            break;
           
    }
    return DefWindowProc(hWnd, msgID, wParam, lParam);
}
