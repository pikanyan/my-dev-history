#include "WndRegister.h"

#include "CommDef.h"
#include "CommFunc.h"

#include "WndProcess.h"

#include <tchar.h>

WndRegister::WndRegister()
{
}

WndRegister::WndRegister(LPCTSTR)
{
}

WndRegister::~WndRegister()
{
}

void WndRegister::register_Cls()
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof WNDCLASSEX;
	wc.style = style;
	wc.lpfnWndProc = WndProcess::process_WinS;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetModuleHandle(nullptr);
	wc.hIcon = icon;
	wc.hCursor = cursor;
	wc.hbrBackground = bg;
	wc.lpszMenuName = menu;
	wc.lpszClassName = cls;
	wc.hIconSm = iconSm;

	if (RegisterClassEx(&wc) == false)
		debug(_T("Error : %s\n"), __FUNCTIONT__);
}
