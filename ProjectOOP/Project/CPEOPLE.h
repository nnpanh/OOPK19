#pragma once
#ifndef _CPEOPLE_
#define _CPEOPLE_

#include <iostream>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include "CVEHICLE.h"
using namespace std;

#define consoleWidth	85
#define consoleHeight	25

void ShowConsoleCursor(bool showFlag);
void doPeople();
class CPEOPLE {
private:
	int mX, mY;
	char* s = _strdup("Y");
public:
	char* getCh();
	int getX();
	int getY();
	void display();
	CPEOPLE();
	void Up();
	void Left();
	void Right();
	void Down();
	void Control();
	bool isImpact(CVEHICLE*& a);
	//bool isImpact(const CVEHICLE*&);
	//bool isImpact(const CANIMAL*&);
	bool isFinish();
	bool isDead();
};
void doPeople();


#endif