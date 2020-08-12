#ifndef _CVEHICLE_H_
#define _CVEHICLE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
using namespace std;

#define MAXLEVEL 5
#define MAXWIDTH 100
#define MAXHEIGHT 100
#define LINE1 10
#define LINE2 30
#define space 5

class CVEHICLE //abstract
{
protected:
	int mX, mY;
public:
	CVEHICLE();
	CVEHICLE(int x,int y);
	virtual void Move(int X, int Y) = 0;
	virtual void erase() = 0;
	virtual void draw() = 0;
	virtual int getWidth() { return 0; };
	virtual int getType() { return 0; }//1=truck 2= car
};
class CTRUCK final :public CVEHICLE
{
private:
	int length, width;
public:
	CTRUCK();
	CTRUCK(int x, int y);
	~CTRUCK();
	void Move(int X, int Y) override;
	void draw();
	void erase();
	int getWidth() { return width; };
	int getType() { return 1; }
};
class CCAR final :public CVEHICLE
{
private:
	int length, width;
public:
	CCAR();
	CCAR(int x, int y);
	~CCAR();
	void Move(int X, int Y) override;
	void draw();
	void erase();
	int getWidth() { return width; };
	int getType() { return 2; }
};

class CONTROL_VEHICLE {
private:
	int CAR_NUM[MAXLEVEL+1];
	int TRUCK_NUM[MAXLEVEL+1];
	int cur_level;
	int cur_CAR_NUM;
	int cur_TRUCK_NUM;
	bool crash;
	vector<CVEHICLE*> Running_Vehicle;
public:
	CONTROL_VEHICLE();
	~CONTROL_VEHICLE();	
	bool state(bool isDead); //DEAD OR ALIVE
	void update_Vehicle_level(int level); //UPDATE LEVEL AND NUMBER OF VEHICLE
	void MoveAll(int xTruck, int yTruck, int xCar, int yCar);
	void EraseAll(int xTruck, int yTruck, int xCar, int yCar);
	void Run(int state,int level,int xTruck,int yTruck,int xCar,int yCar);
};

void GotoXY(int x, int y);
void clearScreen();
void FixConsoleWindow(); //Lock console ratio
#endif