#pragma once

#include "WndProcess.h"

class WndMainProcess : public WndProcess
{
public:
	WndMainProcess();
	virtual ~WndMainProcess();

	LRESULT CALLBACK process_Win(HWND, UINT, WPARAM, LPARAM);

	BOOL OnCreate(HWND, LPCREATESTRUCT);

	void OnDestroy(HWND);
};
