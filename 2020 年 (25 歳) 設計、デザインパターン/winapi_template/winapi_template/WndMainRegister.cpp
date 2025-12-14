#include "WndMainRegister.h"

#include <tchar.h>

WndMainRegister::WndMainRegister()
{
}

WndMainRegister::WndMainRegister(LPCTSTR cls)
{
	initialize_Param(cls);
	register_Cls();
}

WndMainRegister::~WndMainRegister()
{
}

void WndMainRegister::initialize_Param(LPCTSTR cls_)
{
	cls = cls_;
}
