#pragma once

#include <Windows.h>

#ifdef UNICODE
#define __FUNCTIONT__   __FUNCTIONW__
#else
#define __FUNCTIONT__   __FUNCTION__
#endif

extern const HINSTANCE inst;

extern int noFunc;
