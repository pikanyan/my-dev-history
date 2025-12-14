#pragma once

#include "WndCreator.h"

class WndProcess;

class WndMainCreator : public WndCreator
{
public:
	WndMainCreator();
	WndMainCreator(LPCTSTR, WndProcess*);
	virtual ~WndMainCreator();

	void initialize_Param(LPCTSTR, WndProcess*);
};
