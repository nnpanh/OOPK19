#include "CVEHICLE.h"
//#include "Console.h"
#include "CPEOPLE.h"

int main()
{
	FixConsoleWindow();
	_setmode(_fileno(stdout), _O_U16TEXT);
	

	//CONTROL_VEHICLE myVehicle;
	//thread vehicle(doSth);
	//vehicle.join();
	do
	{
		for (int j = BORDER; j < MAXWIDTH; j += space)
		{
			myVehicle.Run(3, 4, j, 5, j, 10);
			Sleep(400);
			myVehicle.EraseAll();
			Sleep(10);
		}
	} while (GetAsyncKeyState(VK_ESCAPE) == 0);
	return 0;
}