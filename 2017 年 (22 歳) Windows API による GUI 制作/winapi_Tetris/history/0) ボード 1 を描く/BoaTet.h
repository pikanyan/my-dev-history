#ifndef _BOARDTETRIMINO_H_
#define _BOARDTETRIMINO_H_

#include <tchar.h>
#include <Windows.h>

#define SqaSide 31

#define BoaVisibleSqaxNum 10
#define BoaInVisibleSqaxNum 2
#define BoaSqaxNum BoaVisibleSqaxNum + BoaInVisibleSqaxNum

#define BoaVisibleSqayNum 22
#define BoaInVisibleSqayNum 5
#define BoaSqayNum BoaVisibleSqayNum + BoaInVisibleSqayNum

class C_BoaTet
{
private:
	LPARAM lp;
	HBITMAP hBitmap;
	HDC hDC, hBoaTetDC, hTetSqDC;
	HPEN hPen;
	HWND hWnd;
	PAINTSTRUCT paintstruct;

	const COLORREF GridColor = RGB(0, 97, 146);;
	byte Boa[BoaSqaxNum][BoaSqayNum];
public:
	void giveWndProcParam(HWND givenhWnd, LPARAM givenlp);
	void createDC_Bitmap();
	void initializeDC();
	void paint();
private:
	void createBoaTetDC();
	void createTetSqDC();
	void createBitmap();
};

#endif _BOARDTETRIMINO_H_