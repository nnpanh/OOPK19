#include "CVEHICLE.h"
//CAR
CCAR::CCAR() {
	length = 3; width = 8;
	mX = 0; mY = 0;
}
CCAR::CCAR(int x, int y) {
	length = 3; width = 8;
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
	length = 3; width = 7;
	mX = 0; mY = 0;
}
CTRUCK::CTRUCK(int x, int y) {
	length = 3; width = 7;
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

CONTROL_VEHICLE::CONTROL_VEHICLE()
{
	cur_CAR_NUM = 0;
	cur_TRUCK_NUM = 0;
	cur_level = 0;
	ifstream f;
	f.open("VEHICLE.txt");
	if (!f.is_open()) cout << "Failed to load file";
	else {
		for (int i = 0; i < MAXLEVEL; i++)
			f >> CAR_NUM[i] >> TRUCK_NUM[i];
		f.close();
	}
}
CONTROL_VEHICLE::~CONTROL_VEHICLE(){}
void CONTROL_VEHICLE::MoveAll()
{
	system("CLS");
	int number_of_Vehicle = Running_Vehicle.size();
	for (int i = 0; i < number_of_Vehicle; i++)
	{
		cout << "Do sth lol";
	}
}
/*
void CONTROL_VEHICLE::update_Vehicle_number(int level)
{
	int add = level - cur_level;
	if (add > 0)
	{
		while (cur_CAR_NUM < CAR_NUM[level])
		{
			CVEHICLE* newCar = new CCAR;
			Running_Vehicle.push_back(*newCar);
			cur_CAR_NUM++;
		}
		while (cur_TRUCK_NUM < TRUCK_NUM[level])
		{
			CVEHICLE* newTruck = new CTRUCK;
			Running_Vehicle.push_back(*newTruck);
			cur_TRUCK_NUM++;
		}
	}
	else 
	{
		auto i = Running_Vehicle.cbegin();
		int loop = 0;
		while (cur_CAR_NUM > CAR_NUM[level])
		{
			if (Running_Vehicle[loop].getType() == 2)
			{
				Running_Vehicle.erase(i);
				cur_CAR_NUM--;
			}
			else if (cur_TRUCK_NUM > TRUCK_NUM[level])
			{
				Running_Vehicle.erase(i);
				cur_TRUCK_NUM--;
			}
			//update i
			loop++;
		}
		i = Running_Vehicle.cend();
		loop = Running_Vehicle.size();
		{
			while (cur_TRUCK_NUM > TRUCK_NUM[level])
			{
				if (Running_Vehicle[loop].getType() == 1)
				{
					Running_Vehicle.erase(i);
					cur_TRUCK_NUM--;
				}
				//update i
				loop--;
			}
		}

		
		
	}
	cur_level = level;
	
	
}

void CONTROL_VEHICLE::Run(int state,int level) 
{
	//state: 1.Running casually
	//2. Crash
	//3. Level up
	
	update_level(level);
	switch (state)
	{
	case 1:
	{
		MoveAll();
		Sleep(3);
		break; 
	}
	case 2:
	{
		//Stop moving
		//Add noise + blink?
		break;
	}
	default:
	{
		update_Vehicle_number(cur_level);
		MoveAll(); 
	}
	}
}
*/