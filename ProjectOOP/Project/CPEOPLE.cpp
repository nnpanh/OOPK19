#include "CPEOPLE.h"
#include "Console.h"
CPEOPLE::CPEOPLE()
{
	mX = WIDTH_CONSOLE/2;
	mY = HEIGHT_CONSOLE-3;
	mState = false;
}

void CPEOPLE::draw()
{
	GotoXY(mX, mY);
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
		cout << "  ";
		mY-= 4;
		
	}
}

void CPEOPLE::Left()
{
	if (mX > 3)
	{
		GotoXY(mX, mY);
		cout << "  ";
		mX-=2;
	}
}

void CPEOPLE::Right()
{
	if (mX < WIDTH_CONSOLE-2)
	{
		GotoXY(mX, mY);
		cout << "  ";
		mX+=2;
	}
}
void CPEOPLE::Down()
{
	if (mY < HEIGHT_CONSOLE - 3)
	{
		GotoXY(mX, mY);
		cout << "  ";
		mY+=4;
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