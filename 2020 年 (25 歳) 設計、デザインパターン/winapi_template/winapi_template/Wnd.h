#pragma once

#include <Windows.h>

class WndRegister;
class WndProcess;
class WndCreator;

class Wnd
{
protected:
	LPCTSTR cls = nullptr;

	WndRegister* wR = nullptr;
	WndProcess* wP = nullptr;
	WndCreator* wC = nullptr;
public:
	Wnd();
	virtual ~Wnd();

	virtual void initialize_Param() = 0;
};
