#include "WndMainCreator.h"

#include "CommDef.h"
#include "CommFunc.h"

#include <tchar.h>
#include "Wnd.h"
#include "main.h"

#include <tchar.h>

WndMainCreator::WndMainCreator()
{
}

WndMainCreator::WndMainCreator(LPCTSTR cls, WndProcess* wP)
{
	initialize_Param(cls, wP);
	create_Wnd();
}

WndMainCreator::~WndMainCreator()
{
}

void WndMainCreator::initialize_Param(LPCTSTR cls_, WndProcess* wP_)
{
	styleEx = NULL;
	cls = cls_;
	cap = _T("Main");
	style = WS_VISIBLE | WS_OVERLAPPEDWINDOW;
	posAX = CW_USEDEFAULT;
	posAY = CW_USEDEFAULT;
	width = 512;
	height = 288;
	wndMain = nullptr;
	menu = nullptr;
	wP = wP_;
}

