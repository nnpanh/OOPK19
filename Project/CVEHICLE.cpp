#include "CVEHICLE.h"
//CAR
CCAR::CCAR() {
	mX = 0; mY = 0;
}
CCAR::CCAR(int x, int y) {
	mX = x; mY = y;
}
CCAR::~CCAR() {
	mX = -1; mY = -1;
}
void CCAR::draw()
{
	GotoXY(mX, mY);
	wcout << L"\u2588\u2588\u2588\u2588";
	GotoXY(mX - 2, mY + 1);
	wcout << L"\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588";
	GotoXY(mX - 1, mY + 2);
	wcout << L"\u25cf";
	GotoXY(mX + 4, mY + 2);
	wcout << L"\u25cf";
}
void CCAR::Move(int X, int Y)
{
	mX = X; mY = Y;
	draw();
}
//TRUCK
CTRUCK::CTRUCK() {
	mX = 0; mY = 0;
}
CTRUCK::CTRUCK(int x, int y) {
	mX = x; mY = y;
}
CTRUCK::~CTRUCK() {
	mX = -1; mY = -1;
}
void CTRUCK::draw()
{

	GotoXY(mX, mY);
	wcout << L"\u2588\u2588\u2588\u2588\u2588";
	GotoXY(mX, mY + 1);
	wcout << L"\u2588\u2588\u2588\u2588\u2588\u2588\u2588";
	GotoXY(mX + 1, mY + 2);
	wcout << L"\u25cf";
	GotoXY(mX + 4, mY + 2);
	wcout << L"\u25cf";

}
void CTRUCK::Move(int X, int Y)
{
	mX = X; mY = Y;
	draw();
}
//SUBFUNC
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void clearScreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void FixConsoleWindow() { //Lock console ratio
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

