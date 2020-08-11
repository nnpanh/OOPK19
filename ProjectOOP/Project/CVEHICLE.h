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

class CVEHICLE //abstract
{
protected:
	int mX, mY;
	int length, width;
public:
	virtual void Move(int X, int Y) = 0;
	virtual void draw() = 0;
	virtual int getType() { return 0; }//1=truck 2= car
};
class CTRUCK final :public CVEHICLE
{
public:
	CTRUCK();
	CTRUCK(int x, int y);
	~CTRUCK();
	void Move(int X, int Y) override;
	void draw();
	int getType() { return 1; }
};
class CCAR final :public CVEHICLE
{
public:
	CCAR();
	CCAR(int x, int y);
	~CCAR();
	void Move(int X, int Y) override;
	void draw();
	int getType() { return 2; }
};

class CONTROL_VEHICLE {
private:
	int CAR_NUM[MAXLEVEL];
	int TRUCK_NUM[MAXLEVEL];
	int cur_level;
	int cur_CAR_NUM;
	int cur_TRUCK_NUM;
	vector<CVEHICLE> Running_Vehicle;
public:
	CONTROL_VEHICLE();
	~CONTROL_VEHICLE();
	void update_level(int level) { cur_level = level; }
	void update_Vehicle_number(int level);
	void MoveAll();
	void Run(int state,int level);
};

void GotoXY(int x, int y);
void clearScreen();
void FixConsoleWindow(); //Lock console ratio
#endif