#include "CPEOPLE.h"
#include "Console.h"
CPEOPLE::CPEOPLE()
{
	mX = WIDTH_CONSOLE/2;
	mY = HEIGHT_CONSOLE-1;
}

void CPEOPLE::draw()
{
	cout << "Y";
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
	if(mY > 1)
	{
		GotoXY(mX, mY);
		cout << " ";
		mY--;
		GotoXY(mX, mY);
	}
}

void CPEOPLE::Left()
{
	if (mX > 2)
	{
		GotoXY(mX, mY);
		cout << " ";
		mX--;
		GotoXY(mX, mY);
	}
}

void CPEOPLE::Right()
{
	if (mX < WIDTH_CONSOLE)
	{
		GotoXY(mX, mY);
		cout << " ";
		mX++;
		GotoXY(mX, mY);
	}
}
void CPEOPLE::Down()
{
	if (mY < HEIGHT_CONSOLE - 1)
	{
		GotoXY(mX, mY);
		cout << " ";
		mY++;
		GotoXY(mX, mY);
	}
}
 
bool CPEOPLE::isFinish()
{
	if (mY == 0)
		return true;
	return false;
}
bool CPEOPLE::isDead()
{
	if (mState == true)
		return true;
	return false;
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}