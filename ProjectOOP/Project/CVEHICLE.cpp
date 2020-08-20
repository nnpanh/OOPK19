#include "CVEHICLE.h"


//CAR
CCAR::CCAR():CVEHICLE() {
	length = 3; width = 8;
}
CCAR::CCAR(int x, int y): CVEHICLE(x,y) {
	length = 3; width = 8;
}
CCAR::~CCAR() {
	mX = -1; mY = -1;
}
int CCAR::getWidth() {
	return width;
}
int CCAR::getType() {
	return 2;
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
void CCAR::erase()
{
	GotoXY(mX, mY);
	wcout << L"\u2003\u2003\u2003\u2003";
	GotoXY(mX - 2, mY + 1);
	wcout << L"\u2003\u2003\u2003\u2003\u2003\u2003\u2003\u2003";
	GotoXY(mX - 1, mY + 2);
	wcout << L"\u2003";
	GotoXY(mX + 4, mY + 2);
	wcout << L"\u2003";
}

void CCAR::move(int X, int Y)
{
	mX = X; mY = Y;
	draw();
	
}
//TRUCK
CTRUCK::CTRUCK():CVEHICLE() {
	length = 3; width = 7;
}
CTRUCK::CTRUCK(int x, int y) : CVEHICLE(x, y) {
	length = 3; width = 7;
}
CTRUCK::~CTRUCK() {
	mX = -1; mY = -1;
}
int CTRUCK::getWidth() {
	return width;
}
int CTRUCK::getType() {
	return 1;
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
void CTRUCK::erase()
{
	GotoXY(mX, mY);
	wcout << L"\u2003\u2003\u2003\u2003\u2003";
	GotoXY(mX, mY + 1);
	wcout << L"\u2003\u2003\u2003\u2003\u2003\u2003\u2003";
	GotoXY(mX + 1, mY + 2);
	wcout << L"\u2003";
	GotoXY(mX + 4, mY + 2);
	wcout << L"\u2003";
}


void CTRUCK::move(int X, int Y)
{	
	
	mX = X; mY = Y;
	draw();
	
}

//VEHICLE
CVEHICLE::CVEHICLE()
{
	mX = 0; mY = 0;
}
CVEHICLE::CVEHICLE(int x, int y)
{
	mX = x; mY = y;
}
bool CONTROL_VEHICLE::state(bool isDead) {
	if (isDead) crash = 1;
	return isDead;
}
void CVEHICLE::Move_border(int& xVehicle, int yVehicle, int& count)
{
	int width = this->getWidth();
	int new_width = xVehicle + (width + space) * count;
	if (new_width + width > MAXWIDTH)
	{
		if (new_width > MAXWIDTH) count = -2;
	}
	else this->move(new_width, yVehicle);
	count++;
}


CONTROL_VEHICLE::CONTROL_VEHICLE()
{
	crash = 0;
	cur_CAR_NUM = 0;
	cur_TRUCK_NUM = 0;
	cur_level = 0;
	CAR_NUM[0] = 0; //LEVEL 0
	TRUCK_NUM[0] = 0;
	ifstream f;
	f.open("VEHICLE.txt");
	if (!f.is_open()) cout << "Failed to load file";
	else {
		for (int i = 1; i <= MAXLEVEL; i++) 
			f >> CAR_NUM[i] >> TRUCK_NUM[i];
		f.close();
	}
}
CONTROL_VEHICLE::~CONTROL_VEHICLE(){}
void CONTROL_VEHICLE::MoveAll(int xTruck, int yTruck, int xCar, int yCar)
{

	auto count_TRUCK = 0;
	auto count_CAR = 0;
	int number_of_Vehicle = Running_Vehicle.size();
	
	for (int i = 0; i < number_of_Vehicle; i++)
	{
		switch (Running_Vehicle[i]->getType()) 
		{
		case 1: //RUN THIS TRUCK
		{
			
			Running_Vehicle[i]->Move_border(xTruck, yTruck, count_TRUCK);
			if (count_TRUCK == -1)
			{
				if (xTruck > BORDER + Running_Vehicle[i]->getWidth()) xTruck = BORDER;
				count_TRUCK = 0;
			}
			break;
		}
		case 2: //RUN THIS CAR
		{
			Running_Vehicle[i]->Move_border(xCar, yCar, count_CAR);
			if (count_CAR == -1)
			{
				if (xCar > BORDER + Running_Vehicle[i]->getWidth()) xCar = BORDER;
				count_CAR = 0;
			}
			break;
		}
		}
	}
}
void CONTROL_VEHICLE::EraseAll()
{
	system("CLS");
	auto count_TRUCK = 0;
	auto count_CAR = 0;
	int number_of_Vehicle = Running_Vehicle.size();

	for (int i = 0; i < number_of_Vehicle; i++)
	{
		switch (Running_Vehicle[i]->getType())
		{
		case 1: //RUN THIS TRUCK
		{
			Running_Vehicle[i]->erase();
			count_TRUCK++;
			break;
		}
		case 2: //RUN THIS CAR
		{
			Running_Vehicle[i]->erase();
			count_CAR++;
			break;

		}
		}
	}
}
void CONTROL_VEHICLE::update_Vehicle_level(int level)
{
	int add = level - cur_level;
	if (add > 0) //LEVEL UP - ADD MORE VEHICLE
	{
		while (cur_CAR_NUM < CAR_NUM[level])
		{
			Running_Vehicle.push_back(new CCAR);
			cur_CAR_NUM++;
		}
		while (cur_TRUCK_NUM < TRUCK_NUM[level])
		{
	
			Running_Vehicle.push_back(new CTRUCK);
			cur_TRUCK_NUM++;
		}
	}
	else //LEVEL DOWN - ERASE VEHICLE
	{
		auto i = 0;
		bool object_erased = 1;
		while (object_erased&&i<Running_Vehicle.size())
		{
			object_erased = 0;
			switch (Running_Vehicle[i]->getType())
			{
			case 1:
			{
				if (cur_CAR_NUM > CAR_NUM[level])
				{
					Running_Vehicle.erase(Running_Vehicle.cbegin() + i);
					cur_CAR_NUM--;
					object_erased = 1;
				}
				break;
			}
			case 2:
			{
				if (cur_TRUCK_NUM > TRUCK_NUM[level])
				{
					Running_Vehicle.erase(Running_Vehicle.cbegin() + i);
					cur_TRUCK_NUM--;
					object_erased = 1;
				}
				break;
			}
			}
			if (object_erased) i++;
			
		}
		
	}
	cur_level = level;
	
	
}

void CONTROL_VEHICLE::Run(int status,int level,int xTruck,int yTruck, int xCar,int yCar) 
{
	//state: 1.Running casually
	//2. Crash
	//3. Level up
	
	
	switch (status)
	{
	case 1:
	{
		MoveAll(xTruck,yTruck,xCar,yCar);
		Sleep(3);
		break; 
	}
	case 2:
	{
		state(1);
		//Add noise + blink?
		break;
	}
	default:
	{
		
		update_Vehicle_level(level);
		MoveAll(xTruck, yTruck, xCar, yCar);
	}
	}
}
