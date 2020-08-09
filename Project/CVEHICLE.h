#ifndef _CVEHICLE_H_
#define _CVEHICLE_H_

#include <iostream>
#include <thread>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
using namespace std;


class CVEHICLE //abstract
{
protected:
	int mX, mY;
public:
	virtual void Move(int X, int Y) = 0;
	virtual void draw() = 0;
};
class CTRUCK final :public CVEHICLE
{
public:
	CTRUCK();
	CTRUCK(int x, int y);
	~CTRUCK();
	void Move(int X, int Y) override;
	void draw();
};
class CCAR final :public CVEHICLE
{
public:
	CCAR();
	CCAR(int x, int y);
	~CCAR();
	void Move(int X, int Y) override;
	void draw();
};

void GotoXY(int x, int y);
void clearScreen();
void FixConsoleWindow(); //Lock console ratio
#endif