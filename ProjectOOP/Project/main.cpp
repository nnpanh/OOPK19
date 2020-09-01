#include "CVEHICLE.h"
#include "Console.h"
#include "CPEOPLE.h"



int main()
{
	FixConsoleWindow();

	
	CONTROL_VEHICLE myVehicle;

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

	/*thread people(doPeople);
	thread vehicle(doVehicle);


	vehicle.join();
	people.join();*/
	return 0;

}