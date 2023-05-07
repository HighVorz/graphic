#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <iostream>


int default_nx = 800;
int default_ny = 600;

LRESULT CALLBACK
WndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam);

void initMain(WNDCLASS &wc, HINSTANCE hIns){
    // window class
    wc = {0};
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
                               100, 100, default_nx, default_ny, NULL, NULL, hIns, addtion);

    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);
}

void eventloop(){
    MSG nMsg = {0};
    
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
}

int CALLBACK
WinMain(HINSTANCE hIns, HINSTANCE hPreIns, LPSTR lpCmdline, int nCmdShow) {

    freopen("out", "w", stdout);
    WNDCLASS wc;
    initMain(wc, hIns);
    eventloop();

    return 0;
}
