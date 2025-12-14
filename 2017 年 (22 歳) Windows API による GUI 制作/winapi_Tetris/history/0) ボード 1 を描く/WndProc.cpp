#include "BoaTet.h"
#include "WndProc.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{	
	static C_BoaTet BoaTet;
	BoaTet.giveWndProcParam(hWnd, lp);
	
	switch (msg)
	{
	case WM_CREATE:
		BoaTet.createDC_Bitmap();
		BoaTet.initializeDC();
		break;
	case WM_PAINT:
		BoaTet.paint();
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
	return 0;
}