#include <tchar.h>
#include <Windows.h>
#include "BoaTet.h"
#include "WndProc.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	TCHAR lpszClassName[] = _T(" ");
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = lpszClassName;
	wc.hIconSm = NULL;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, _T(""), _T(""), MB_OK);
		return FALSE;
	}

	RECT rect = { 0, 0, SqaSide * BoaVisibleSqaxNum, SqaSide * BoaVisibleSqayNum + 1 };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, NULL);

	HWND hWnd = CreateWindow(lpszClassName, _T(""), WS_OVERLAPPEDWINDOW, 0, 0, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		MessageBox(NULL, _T(""), _T(""), MB_OK);
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (int bRet = GetMessage(&msg, NULL, 0, 0))
	{
		if (bRet == -1)
			break;
		else
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;
}