#include "WndCreator.h"

#include "CommDef.h"
#include "CommFunc.h"

#include <tchar.h>

WndCreator::WndCreator()
{
}

WndCreator::WndCreator(LPCTSTR, WndProcess*)
{
}

WndCreator::~WndCreator()
{
}

void WndCreator::create_Wnd()
{
    HWND wnd = CreateWindowEx
    (
        styleEx,
        cls,
        cap,
        style,
        posAX,
        posAY,
        width,
        height,
        wndMain,
        menu,
        inst,
        wP
    );

    if (wnd == nullptr)
        debug(_T("Error : %s\n"), __FUNCTIONT__);
}
