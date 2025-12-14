#include "WndProcess.h"

#include "CommDef.h"
#include "CommFunc.h"

#include <Windowsx.h>
#include <tchar.h>

WndProcess::WndProcess()
{
}

WndProcess::~WndProcess()
{
}

int WndProcess::loop_WinMain()
{
    BOOL ret;
    MSG msg;

    while (ret = GetMessage(&msg, NULL, 0, 0) != 0)
    {
        if (ret == -1)
            break;
        else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProcess::process_WinS(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    WndProcess* wP = (WndProcess*)GetWindowLongPtr(wnd, GWLP_USERDATA);

    switch (msg)
    {
        HANDLE_MSG(wnd, WM_CREATE, OnCreateS);
    default:
        if (wP == nullptr)
            return DefWindowProc(wnd, msg, wParam, lParam);
        else
            return wP->process_Win(wnd, msg, wParam, lParam);
    }
}

BOOL WndProcess::OnCreateS(HWND wnd, LPCREATESTRUCT pCreateStruct)
{
    WndProcess* wP = (WndProcess*)pCreateStruct->lpCreateParams;
    SetWindowLongPtr(wnd, GWLP_USERDATA, (LONG_PTR)wP);

    return wP->OnCreate(wnd, pCreateStruct);
}
