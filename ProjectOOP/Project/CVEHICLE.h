#ifndef _CVEHICLE_H_
#define _CVEHICLE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include "Console.h"

using namespace std;

#define MAXLEVEL 5
#define MAXWIDTH 100
#define MAXHEIGHT 50
#define BORDER 5
#define LINE1 20
#define LINE2 100
#define space 10

class CVEHICLE //abstract
{
protected:
	int mX, mY;
public:
	CVEHICLE();
	CVEHICLE(int x,int y);
	virtual void move(int X, int Y) = 0;
	virtual void erase() = 0;
	virtual void draw() = 0;
	virtual int getWidth() = 0;
	virtual int getType() = 0;//1=truck 2= car
	void Move_border(int& xVehicle, int yVehicle, int& count);
	
};
class CTRUCK final :public CVEHICLE
{
private:
	int length, width;
public:
	CTRUCK();
	CTRUCK(int x, int y);
	~CTRUCK();
	void move(int X, int Y) override;
	void draw();
	void erase();
	int getWidth();
	int getType();
};
class CCAR final :public CVEHICLE
{
private:
	int length, width;
public:
	CCAR();
	CCAR(int x, int y);
	~CCAR();
	void move(int X, int Y) override;
	void draw();
	void erase();
	int getWidth();
	int getType();
};

class CONTROL_VEHICLE {
private:
	int CAR_NUM[MAXLEVEL+1];
	int TRUCK_NUM[MAXLEVEL+1];
	int cur_level;
	int cur_CAR_NUM;
	int cur_TRUCK_NUM;
	bool crash;
	vector <CVEHICLE*> Running_Vehicle;
public:
	CONTROL_VEHICLE();
	~CONTROL_VEHICLE();	
	bool state(bool isDead); //DEAD OR ALIVE
	void update_Vehicle_level(int level); //UPDATE LEVEL AND NUMBER OF VEHICLE
	void MoveAll(int xTruck, int yTruck, int xCar, int yCar);
	void EraseAll();
	void Run(int state,int level,int xTruck,int yTruck,int xCar,int yCar);
};


#endif