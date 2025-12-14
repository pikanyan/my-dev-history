#pragma once

#include "WndRegister.h"

class WndMainRegister : public WndRegister
{
public:
	WndMainRegister();
	WndMainRegister(LPCTSTR);
	~WndMainRegister();

	void initialize_Param(LPCTSTR);
};
