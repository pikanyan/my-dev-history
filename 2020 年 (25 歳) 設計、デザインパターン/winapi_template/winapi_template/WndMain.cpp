#include "WndMain.h"

#include "WndMainRegister.h"
#include "WndMainCreator.h"
#include "WndMainProcess.h"

#include <tchar.h>

WndMain wMain;

WndMain::WndMain()
{
	initialize_Param();
}

WndMain::~WndMain()
{
	delete wP;
}

void WndMain::initialize_Param()
{
	cls = _T("Main");
	
	wR = new WndMainRegister(cls);
	delete wR;

	wP = new WndMainProcess;

	wC = new WndMainCreator(cls, wP);
	delete wC;
}
