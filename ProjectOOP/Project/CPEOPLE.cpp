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
<<<<<<< HEAD
}
 
void CPEOPLE::Control()
{
	display();
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

bool CPEOPLE::isImpact(const CVEHICLE*& a)
{

}

bool CPEOPLE::isFinish()
{
	if (mY < 0)
		return true;
	return false;
}
bool CPEOPLE::isDead()
{

}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
=======
}
>>>>>>> fe8ab54096b41430a933eda794a37edbb704a899
