#include "BoaTet.h"

void C_BoaTet::giveWndProcParam(HWND givenhWnd, LPARAM givenlp)
{
	hWnd = givenhWnd;
	lp = givenlp;
}

void C_BoaTet::createDC_Bitmap()
{
	createBoaTetDC();
	createTetSqDC();
	createBitmap();
}

void C_BoaTet::initializeDC()
{
	SelectObject(hBoaTetDC, hBitmap);

	hBitmap = LoadBitmap(((LPCREATESTRUCT)(lp))->hInstance, _T("TetSq"));
	SelectObject(hTetSqDC, hBitmap);

	hPen = (HPEN)SelectObject(hBoaTetDC, CreatePen(PS_SOLID, 1, GridColor));
}

void C_BoaTet::paint()
{
	for (int BoardSqxPos = 1; BoardSqxPos <= BoaVisibleSqaxNum; BoardSqxPos++)
	{
		for (int BoardSqyPos = 1; BoardSqyPos <= BoaVisibleSqayNum; BoardSqyPos++)
		{
			BitBlt(hBoaTetDC, SqaSide * (BoardSqxPos - 1), SqaSide * (BoaVisibleSqayNum - BoardSqyPos) + 1, SqaSide, SqaSide, hTetSqDC, 0, SqaSide * Boa[BoardSqxPos][BoardSqyPos], SRCCOPY);
		}
	}

	MoveToEx(hBoaTetDC, 0, 0, NULL);
	LineTo(hBoaTetDC, SqaSide * BoaVisibleSqaxNum, 0);

	hDC = BeginPaint(hWnd, &paintstruct);
	BitBlt(hDC, 0, 0, SqaSide * BoaVisibleSqaxNum, SqaSide * BoaVisibleSqayNum + 1, hBoaTetDC, 0, 0, SRCCOPY);
	EndPaint(hWnd, &paintstruct);
}

void C_BoaTet::createBoaTetDC()
{
	hBoaTetDC = CreateCompatibleDC(NULL);
}

void C_BoaTet::createTetSqDC()
{
	hTetSqDC = CreateCompatibleDC(NULL);
}

void C_BoaTet::createBitmap()
{
	hDC = GetDC(hWnd);
	hBitmap = CreateCompatibleBitmap(hDC, SqaSide * BoaVisibleSqaxNum, SqaSide * BoaVisibleSqayNum + 1);
	ReleaseDC(hWnd, hDC);
}