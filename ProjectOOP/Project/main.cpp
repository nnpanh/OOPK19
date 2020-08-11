#include "CVEHICLE.h"

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	FixConsoleWindow();
	CVEHICLE *myVehicle1;
	myVehicle1 = new CTRUCK;
	CVEHICLE* myVehicle2;
	myVehicle2 = new CTRUCK;
	//thread vehicle(doSth);
	//vehicle.join();
	do
	{
		system("CLS");
		Sleep(200);
		myVehicle2->Move(4, 4);
		myVehicle1->Move(18, 4);
		Sleep(200);
		system("CLS");
		myVehicle2->Move(18+14, 4);
		myVehicle1->Move(18+28,4);
		Sleep(200);

	} while (GetAsyncKeyState(VK_ESCAPE) == 0);
	return 0;
}