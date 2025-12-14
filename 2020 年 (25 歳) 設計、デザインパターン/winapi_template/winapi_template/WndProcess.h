#pragma once

#include <Windows.h>

class WndProcess
{
public:
	WndProcess();
	virtual ~WndProcess();

	static int loop_WinMain();

	static LRESULT CALLBACK process_WinS(HWND, UINT, WPARAM, LPARAM);
	static BOOL OnCreateS(HWND, LPCREATESTRUCT);

	virtual LRESULT CALLBACK process_Win(HWND, UINT, WPARAM, LPARAM) = 0;
	virtual BOOL OnCreate(HWND, LPCREATESTRUCT) = 0;
};
