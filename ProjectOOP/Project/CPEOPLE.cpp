#include "CPEOPLE.h"

char* CPEOPLE::getCh()
{
	return s;
}

CPEOPLE::CPEOPLE()
{
	//mX = (consoleWidth - strlen(s)) / 2;
	mX = consoleWidth/ 2;
	mY = consoleHeight;
}

void CPEOPLE::display()
{
	cout << getCh();
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
	GotoXY(mX, mY);
	cout << "  ";
	mY--;
	GotoXY(mX, mY);
	display();
}

void CPEOPLE::Left()
{
	GotoXY(mX, mY);
	cout << "  ";
	mX--;
	GotoXY(mX, mY);
	display();
}

void CPEOPLE::Right()
{
	GotoXY(mX, mY);
	cout << "  ";
	mX++;
	GotoXY(mX, mY);
	display();
}

void CPEOPLE::Down()
{
	GotoXY(mX, mY);
	cout << "  ";
	mY++;
	GotoXY(mX, mY);
	display();
}
 
void CPEOPLE::Control()
{
	ShowConsoleCursor(false);
	GotoXY(mX,mY);
	//display();
	if (_kbhit())
	{
		char key = _getch();
		if (key == 'A' || key == 'a' && mX > 0)
			Left();
		else if (key == 'D' || key == 'd' && mX < consoleWidth)
			Right();
		else if (key == 'W' || key == 'w' && mY > 0)
			Up();
		else if (key == 'S' || key == 's' && mY < consoleHeight)
			Down();
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
bool CPEOPLE::isImpact(CVEHICLE*& a)
{
	if (a->getx() - mX == 0 || a->gety() - mY == 0)
		return true;
	mState = true;
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

void doPeople()
{
	CPEOPLE x;
	while (1)
	{
		x.Control();
		if (x.isFinish())
		{
			GotoXY(x.getX(), x.getY());
			cout << " ";
			cout << "WIN";
			return;
		}
	}
}