#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <iostream>
#include "painter.h"


void
paint(HWND hWnd) { 
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
    }

    return DefWindowProc(hWnd, msgID, wParam, lParam);
}

int CALLBACK
WinMain(HINSTANCE hIns, HINSTANCE hPreIns, LPSTR lpCmdline, int nCmdShow) {
    freopen("out", "w", stdout);
    // window class
    WNDCLASS wc = {0};
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = NULL;
    wc.hIcon = NULL;
    wc.hInstance = hIns;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = _T("Main");  // must match the parameter when call CreateWindow()
    wc.lpszMenuName = NULL;
    wc.style = CS_HREDRAW | CS_VREDRAW;

    // register wc in system
    RegisterClass(&wc);

    char addtion[] = "addtional information";
    // write window in memory
    HWND hWnd = CreateWindowEx(0, _T("Main"), _T("window"), WS_OVERLAPPEDWINDOW,
                               100, 100, 500, 500, NULL, NULL, hIns, addtion);

    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    // message loop
    // GetMessage is a Blocking function
    //
    MSG nMsg = {0};
    /*
    while (GetMessage(&nMsg, NULL, 0, 0)) {
        TranslateMessage(&nMsg);
        DispatchMessage(&nMsg);  // patch message to wndprocx
    }
    */
    while (true) {
        if (PeekMessage(&nMsg, NULL, 0, 0, PM_NOREMOVE)) {
            if (GetMessage(&nMsg, NULL, 0, 0)) {
                TranslateMessage(&nMsg);
                DispatchMessage(&nMsg);
            } else {
                // WM_QUIT
                break;
            }
        } else {
            // no Message
        }
    }

    return 0;
}
