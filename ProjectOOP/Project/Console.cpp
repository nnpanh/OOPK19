#include "Console.h"

void fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawBoard(int startPosX, int startPosY, int w, int h, int endPosX, int endPosY)
{
	for (int i = startPosY; i < h + startPosY; i++)
	{
		for (int j = startPosX; j < w + startPosX; j++)
		{
			if (j == startPosX || j == startPosX + w - 1)
			{
				gotoXY(j, i);
				cout << char(219);
			}
			if (i == startPosY)
			{
				gotoXY(j, i);
				cout << char(220);
			}
			if (i == startPosY + h - 1)
			{
				gotoXY(j, i);
				cout << char(223);
			}
			if (i % 4 == 0 && i != startPosY && i != startPosY + h - 1 && j != startPosX && j != startPosX + w - 1)
			{
				gotoXY(j, i);
				cout << char(205);
			}
		}
	}
	gotoXY(endPosX, endPosY);
}

void setColor(WORD color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawBox(int startPosX, int startPosY, int w, int h, int endPosX, int endPosY)
{
	for (int i = startPosY; i < h + startPosY; i++)
	{
		for (int j = startPosX; j < w + startPosX; j++)
		{
			if (j == startPosX || j == startPosX + w - 1)
			{
				gotoXY(j, i);
				cout << char(219);
			}
			if (i == startPosY)
			{
				gotoXY(j, i);
				cout << char(220);
			}
			if (i == startPosY + h - 1)
			{
				gotoXY(j, i);
				cout << char(223);
			}
		}
	}
	gotoXY(endPosX, endPosY);
}

void animation(int startPosX, int startPosY, int w, int h, int endPosX, int endPosY)
{
	for (int i = 70; i > 0; i--)
	{
		gotoXY(i, 10);
		cout << "           ____________________" << " ";
		gotoXY(i, 11);
		cout << "     _    |                    |" << " ";
		gotoXY(i, 12);
		cout << "  __|_|___|                    |" << " ";
		gotoXY(i, 13);
		cout << " /  ___   |      AMBULANCE     |" << " ";
		gotoXY(i, 14);
		cout << "/  /   |  |                    |" << " ";
		gotoXY(i, 15);
		cout << "|  |___|  |                    |" << " ";
		gotoXY(i, 16);
		cout << "|   ___   |            ___     |" << " ";
		gotoXY(i, 17);
		cout << "|__/   \\__|___________/   \\____|" << " ";
		gotoXY(i, 18);
		cout << "   \\___/ ____________ \\___/" << "______" << "---GAMEOVER---" << "_______";
		Sleep(20);
	}
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}