#include "CVEHICLE.h"
#include "Console.h"

int main()
{
	FixConsoleWindow();
	_setmode(_fileno(stdout), _O_U16TEXT);
	

	CONTROL_VEHICLE myVehicle;
	//thread vehicle(doSth);
	//vehicle.join();
	do
	{
		for (int j = 5; j < 200; j += 5)
		{
			myVehicle.Run(3, 2, j, 5, j, 10);
			Sleep(100);
			myVehicle.EraseAll();
			Sleep(10);
		}
	} while (GetAsyncKeyState(VK_ESCAPE) == 0);
	return 0;
}