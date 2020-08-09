#include "CVEHICLE.h"

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	FixConsoleWindow();
	CVEHICLE *myVehicle;
	myVehicle = new CTRUCK(10,10);
	//thread vehicle(doSth);
	//vehicle.join();
	do
	{
		int x = 5;
		int y = 8;
	
		myVehicle->draw();
		myVehicle->Move(x+6, y+6);
		Sleep(10);

	} while (GetAsyncKeyState(VK_ESCAPE) == 0);
	return 0;
}