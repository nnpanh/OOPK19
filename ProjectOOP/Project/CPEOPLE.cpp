#include "CPEOPLE.h"
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

char* CPEOPLE::getCh()
{
	return s;
}
CPEOPLE::CPEOPLE()
{
	mX = (consoleWidth - strlen(s)) / 2;
	mY = 0;
}

void CPEOPLE::display()
{
	cout << s;
}
int CPEOPLE::getX()
{
	return mX;
}
int CPEOPLE::getY()
{
	return mY;
}
void CPEOPLE::Up()
{
	mY--;
}

void CPEOPLE::Left()
{
	mX--;
}

void CPEOPLE::Right()
{
	mX++;
}

void CPEOPLE::Down()
{
	mY++;
}