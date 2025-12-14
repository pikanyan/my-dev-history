#pragma once

#include <Windows.h>

class WndProcess;

class WndCreator
{
protected:
	DWORD styleEx = NULL;
	LPCTSTR cls = nullptr;
	LPCTSTR cap = nullptr;
	DWORD style = NULL;
	int posAX = NULL;
	int posAY = NULL;
	int width = NULL;
	int height = NULL;
	HWND wndMain = nullptr;
	HMENU menu = nullptr;
	LPVOID wP = nullptr;
public:
	WndCreator();
	WndCreator(LPCTSTR, WndProcess*);
	virtual ~WndCreator();

	virtual void initialize_Param(LPCTSTR, WndProcess*) = 0;
	void create_Wnd();
};
