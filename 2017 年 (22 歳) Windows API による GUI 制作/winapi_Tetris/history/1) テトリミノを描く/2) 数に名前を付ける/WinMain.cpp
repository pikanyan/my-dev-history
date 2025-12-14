#include <tchar.h>
#include <Windows.h>

#define SqSide 31

#define BoardVisibleSqxNum 10
#define BoardInVisibleSqxNum 2
#define BoardSqxNum BoardVisibleSqxNum + BoardInVisibleSqxNum

#define BoardVisibleSqyNum 22
#define BoardInVisibleSqyNum 5
#define BoardSqyNum BoardVisibleSqyNum + BoardInVisibleSqyNum

const COLORREF GridColor = RGB(0, 97, 146);
HBITMAP hBmp;
HDC hDC, hMemDC, hBlockDC;
HINSTANCE hInstance;
HPEN hPen;
HWND hWnd;
PAINTSTRUCT ps;
RECT rc = { 0, 0, SqSide * BoardVisibleSqxNum, SqSide * BoardVisibleSqyNum + 1 };

int Board[BoardSqxNum][BoardSqyNum];

struct SSqRPos
{
	int x;
	int y;
};

struct STrn
{
	int RRotTypeNum;
	SSqRPos SqRPos[4];
};

const STrn Trn[8] =
{
	{ 1,{ {  0, 0 },{ 0, 0 },{  0,  0 },{  0,  0 } } },	// NULL
	{ 2,{ { -1, 0 },{ 0, 0 },{  1,  0 },{  2,  0 } } },	// I
	{ 4,{ { -1, 0 },{ 0, 0 },{  1,  0 },{ -1, -1 } } },	// L
	{ 4,{ { -1, 0 },{ 0, 0 },{  1,  0 },{  0, -1 } } },	// T
	{ 4,{ { -1, 0 },{ 0, 0 },{  1,  0 },{  1, -1 } } },	// J
	{ 2,{ {  0, 0 },{ 1, 0 },{ -1, -1 },{  0, -1 } } },	// S
	{ 1,{ {  0, 0 },{ 1, 0 },{  0, -1 },{  1, -1 } } },	// O
	{ 2,{ { -1, 0 },{ 0, 0 },{  0, -1 },{  1, -1 } } },	// Z
};

enum ETrnType
{
	N,
	I,
	L,
	T,
	J,
	S,
	O,
	Z
};

struct STrnStatus
{
	ETrnType Type;
	int RotNum;
	int BoardSqxPos;
	int BoardSqyPos;
};

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void paintTrn(STrnStatus TrnStatus);

void paintBoard();

int WINAPI WinMain(HINSTANCE hCurInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	hInstance = hCurInstance;

	TCHAR lpszClassName[] = _T(" ");
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hCurInstance;
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

	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, NULL);

	HWND hWnd = CreateWindow(lpszClassName, _T(""), WS_OVERLAPPEDWINDOW, 0, 0, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		MessageBox(NULL, _T(""), _T(""), MB_OK);
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	int bRet;
	MSG msg;
	while (bRet = GetMessage(&msg, NULL, 0, 0))
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		hMemDC = CreateCompatibleDC(NULL);
		hBlockDC = CreateCompatibleDC(NULL);

		hDC = GetDC(hWnd);
		hBmp = CreateCompatibleBitmap(hDC, SqSide * BoardVisibleSqxNum, SqSide * BoardVisibleSqyNum + 1);
		ReleaseDC(hWnd, hDC);

		SelectObject(hMemDC, hBmp);

		hBmp = LoadBitmap(hInstance, _T("TRN"));
		SelectObject(hBlockDC, hBmp);

		hPen = (HPEN)SelectObject(hMemDC, CreatePen(PS_SOLID, 1, GridColor));

		STrnStatus TrnStatus;
		TrnStatus.Type = Z;
		TrnStatus.RotNum = 0 % Trn[TrnStatus.Type].RRotTypeNum;
		TrnStatus.BoardSqxPos = 3;
		TrnStatus.BoardSqyPos = 3;

		paintTrn(TrnStatus);
		
		break;
	}
	case WM_PAINT:
		paintBoard();

		hDC = BeginPaint(hWnd, &ps);
		BitBlt(hDC, 0, 0, SqSide * BoardVisibleSqxNum, SqSide * BoardVisibleSqyNum + 1, hMemDC, 0, 0, SRCCOPY);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		DeleteDC(hMemDC);
		DeleteDC(hBlockDC);
		DeleteObject(hBmp);
		DeleteObject(hPen);

		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

void paintTrn(STrnStatus TrnStatus)
{
	for (int i = 0; i < 4; i++)
	{
		int SqxRPos = Trn[TrnStatus.Type].SqRPos[i].x;
		int SqyRPos = Trn[TrnStatus.Type].SqRPos[i].y;

		for (int j = 0; j < TrnStatus.RotNum; j++)
		{
			int dSqxRPos = SqxRPos;
			int dSqyRPos = SqyRPos;

			SqxRPos = -dSqyRPos;
			SqyRPos = dSqxRPos;
		}
		Board[SqxRPos + TrnStatus.BoardSqxPos][SqyRPos + TrnStatus.BoardSqyPos] = TrnStatus.Type;
	}
}

void paintBoard()
{
	for (int BoardSqxPos = 1; BoardSqxPos <= BoardVisibleSqxNum; BoardSqxPos++)
	{
		for (int BoardSqyPos = 1; BoardSqyPos <= BoardVisibleSqyNum; BoardSqyPos++)
		{
			BitBlt(hMemDC, SqSide * (BoardSqxPos - 1), SqSide * (BoardVisibleSqyNum - BoardSqyPos) + 1, SqSide, SqSide, hBlockDC, 0, SqSide * Board[BoardSqxPos][BoardSqyPos], SRCCOPY);
		}
	}

	MoveToEx(hMemDC, 0, 0, NULL);
	LineTo(hMemDC, SqSide * BoardVisibleSqxNum, 0);
}