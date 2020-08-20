#include "CPEOPLE.h"

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