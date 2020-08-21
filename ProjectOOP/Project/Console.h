#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <Windows.h>
const int HEIGHT_CONSOLE = 25;
const int WIDTH_CONSOLE = 70;

struct point {
	int x, y;
};
void GotoXY(int x, int y);
void FixConsoleWindow();//xoa nut maximize va co dinh man hinh
void ShowConsoleCursor(bool showFlag);
#endif