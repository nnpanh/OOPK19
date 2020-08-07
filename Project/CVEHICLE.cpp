#include <iostream>
#include <Windows.h>
using namespace std;

class CVEHICLE
{
	int mX, mY;
public:
	virtual void Move(int mX, int mY) = 0;
};
class CTRUCK final :public CVEHICLE
{
	void Move(int mX, int mY) override;
};
class CCAR final :public CVEHICLE
{
	void Move(int mX, int mY) override;
};

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

int main()
{
	int time = 0;
	
	FixConsoleWindow();
	
	//do
	//{
		GotoXY(1,0);
		cout << "Hello world" << endl;
		cout << " Hello world" << endl;
	
	
	//}while (GetAsyncKeyState(VK_ESCAPE) ==0);
	return 0;
}