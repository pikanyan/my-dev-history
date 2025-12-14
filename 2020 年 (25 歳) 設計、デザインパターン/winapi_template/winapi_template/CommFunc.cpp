#include "CommFunc.h"

#include "CommDef.h"

#include <Windows.h>
#include <tchar.h>

void debug(LPCTSTR strFormat, ...)
{
    TCHAR strBuf[MAX_PATH];
    va_list argp;

    va_start(argp, strFormat);
    _vstprintf_s(strBuf, MAX_PATH, strFormat, argp);
    va_end(argp);

    OutputDebugString(strBuf);
}

void debug_noFunc()
{
    debug(_T("%02d %s\n"), noFunc++, __FUNCTIONT__);
}
