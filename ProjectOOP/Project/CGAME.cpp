#include "CGame.h"
#include "CVEHICLE.h"

void FixConsoleWindow()//xoa nut maximize va co dinh man hinh
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void CGAME::drawGame(int x, int y, int width, int height)
{
	char k = 205, a = 186, b = 187, c = 188, d = 201, e = 200;
	/*doimau(241);*/
	for (int i = 0; i <= width + 2; i++) //Ngang
	{
		Sleep(5);
		GotoXY(x + i, y);
		cout << (char)219;
		GotoXY(x + i, height + y);
		cout << (char)219;
	}
	for (int i = y + 1; i < height + y; i++) //Doc
	{
		Sleep(20);
		GotoXY(x, i);
		cout << (char)219 << (char)219;
		GotoXY(x + width + 1, i);
		cout << (char)219 << (char)219;
	}

	for (int i = 2; i <= (width - 2) / 2; i++) // Chia Lan Duong
	{
		GotoXY(x + i * 2, y + 4);
		cout << (char)196; // or 95
	}
	for (int i = 2; i <= (width - 2) / 2; i++) // Chia Lan Duong
	{
		GotoXY(x + i * 2, y + 8);
		cout << (char)196; // or 95
	}
	for (int i = 2; i <= (width - 2) / 2; i++) // Chia Lan Duong
	{
		GotoXY(x + i * 2, y + 12);
		cout << (char)196; // or 95
	}
	for (int i = 2; i <= (width - 2) / 2; i++) // Chia Lan Duong
	{
		GotoXY(x + i * 2, y + 16);
		cout << (char)196; //or 95
	}
	for (int i = 2; i <= (width - 2) / 2; i++) // Chia Lan Duong
	{
		GotoXY(x + i * 2, y + 20);
		cout << (char)196; //or 95
	}


	GotoXY(x + width + 20, y + 1);
	cout << "HOW TO PLAY";
	GotoXY(x + width + 5, y + 2);
	cout << "'W': Up";
	GotoXY(x + width + 5, y + 4);
	cout << "'A': Left";
	GotoXY(x + width + 5, y + 6);
	cout << "'S': Down";
	GotoXY(x + width + 5, y + 8);
	cout << "'D': Right";
	GotoXY(x + width + 5, y + 10);
	cout << "(P): Pause";
	GotoXY(x + width + 5, y + 12);
	cout << "'Bam nut bat ki de tiep tuc'";
	GotoXY(x + width + 5, y + 14);
	cout << "(O): Save Game";
	GotoXY(x + width + 5, y + 16);
	cout << "(L): Load game";
	GotoXY(x + width + 5, y + 18);
	cout << "(E): Exit";
	GotoXY(WIDTH_CONSOLE + 4, 0);  //corner of table Huong Dan
	cout << d;
	GotoXY(WIDTH_CONSOLE + 45, 0); //corner of table Huong Dan
	cout << b;
	GotoXY(WIDTH_CONSOLE + 4, 20); //corner of table Huong Dan
	cout << e;
	GotoXY(WIDTH_CONSOLE + 45, 20); //corner of table Huong Dan
	cout << c;
	for (int i = 0; i < 40; i++)
	{
		GotoXY(WIDTH_CONSOLE + 5 + i, 0);  // Hang Tren cua Table Huong Dan
		cout << k;
		GotoXY(WIDTH_CONSOLE + 5 + i, 20); // Hang Duoi Cua Table Huond Dan
		cout << k;
	}
	for (int i = 0; i < 19; i++)
	{
		GotoXY(WIDTH_CONSOLE + 4, 1 + i); // Trai Table Huong Dan
		cout << a;
		GotoXY(WIDTH_CONSOLE + 45, 1 + i); // Phai Table Huong Dan
		cout << a;
	}


	GotoXY(WIDTH_CONSOLE + 4, 21);  //corner of Score
	cout << d;
	GotoXY(WIDTH_CONSOLE + 45, 21); //corner of Score
	cout << b;
	GotoXY(WIDTH_CONSOLE + 4, 25); //corner of Score
	cout << e;
	GotoXY(WIDTH_CONSOLE + 45, 25); //corner of Score
	cout << c;
	for (int i = 0; i < 40; i++)
	{
		GotoXY(WIDTH_CONSOLE + 5 + i, 21);  // Hang Tren cua Score
		cout << k;
		GotoXY(WIDTH_CONSOLE + 5 + i, 25); // Hang Duoi Cua Score
		cout << k;
	}
	for (int i = 0; i < 3; i++)
	{
		GotoXY(WIDTH_CONSOLE + 4, 22 + i); // Trai Table Huong Dan
		cout << a;
		GotoXY(WIDTH_CONSOLE + 45, 22 + i); // Phai Table Huong Dan
		cout << a;
	}
	GotoXY(x + width + 5, y + 22);
	cout << "Score: ";
	GotoXY(x + width + 5, y + 24);
	cout << "Level: ";

	GotoXY(26, 26);
}

void CGAME::pauseGame(HANDLE t)
{
	SuspendThread(t);
}