#include "WndMainProcess.h"

#include "CommDef.h"
#include "CommFunc.h"

#include <Windowsx.h>
#include <tchar.h>

WndMainProcess::WndMainProcess()
{
}

WndMainProcess::~WndMainProcess()
{
}

LRESULT CALLBACK WndMainProcess::process_Win(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        HANDLE_MSG(wnd, WM_CREATE, OnCreate);
        HANDLE_MSG(wnd, WM_DESTROY, OnDestroy);
    default:
        return DefWindowProc(wnd, msg, wParam, lParam);
    }
}

BOOL WndMainProcess::OnCreate(HWND, LPCREATESTRUCT)
{
    return TRUE;
}

void WndMainProcess::OnDestroy(HWND wnd)
{
    PostQuitMessage(0);
}
