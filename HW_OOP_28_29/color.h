#pragma once
#include <Windows.h>

namespace Color {
    enum Code {
        TEXT_RED = 31,
        TEXT_GREEN = 32,
        TEXT_DEFAULT = 39,

    };
}

//------------------------------------------------------------
inline void SetColor(int ForgC)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}


//--------------------------------------------------------
inline void SetColor(int text, int fon)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (fon << 4) + text);
}