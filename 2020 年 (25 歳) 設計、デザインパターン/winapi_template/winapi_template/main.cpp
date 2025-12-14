#include "main.h"

#include <Windows.h>
#include <tchar.h>

#include "WndProcess.h"



int APIENTRY _tWinMain(_In_ HINSTANCE /*inst*/, _In_opt_ HINSTANCE /*instPrev*/, _In_ PTSTR /*cmdLine*/, _In_ int /*cmdShow*/)
{
	return WndProcess::loop_WinMain();
}
