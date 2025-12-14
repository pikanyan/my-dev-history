#pragma once

#include <Windows.h>

class WndRegister
{
protected:
	UINT style = CS_HREDRAW | CS_VREDRAW;
	HICON icon = (HICON)LoadImage(NULL, IDI_APPLICATION, IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	HCURSOR cursor = (HCURSOR)LoadImage(NULL, IDC_ARROW, IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	HBRUSH bg = CreateSolidBrush(RGB(0x33, 0x33, 0x33));
	LPCTSTR menu = nullptr;
	LPCTSTR cls = nullptr;
	HICON iconSm = (HICON)LoadImage(NULL, IDI_APPLICATION, IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
public:
	WndRegister();
	WndRegister(LPCTSTR);
	virtual ~WndRegister();

	virtual void initialize_Param(LPCTSTR) = 0;
	void register_Cls();
};
