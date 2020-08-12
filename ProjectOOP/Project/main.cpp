#include "CVEHICLE.h"

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	FixConsoleWindow();
	CVEHICLE *myVehicle1;
	myVehicle1 = new CTRUCK;
	CVEHICLE* myVehicle2;
	myVehicle2 = new CCAR;
	CONTROL_VEHICLE myVehicle;
	//thread vehicle(doSth);
	//vehicle.join();
	do
	{
		/*
		system("CLS");
		myVehicle1->Move(4, 4);
		myVehicle2->Move(18, 4);
		wcout << endl << endl;
		system("pause");
		myVehicle1->erase();
		myVehicle2->erase();
		wcout << endl << endl;
		system("pause");
		*/
		myVehicle.Run(3, 2,5,5,5,10);
		Sleep(200);
		myVehicle.EraseAll(5,5,5,10);
		Sleep(200);
		myVehicle.Run(3, 2,10,5,10,10);
		Sleep(200);
		myVehicle.EraseAll(10,5,10,10);
		Sleep(200);

		

	} while (GetAsyncKeyState(VK_ESCAPE) == 0);
	return 0;
}