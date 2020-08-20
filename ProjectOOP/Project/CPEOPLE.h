#pragma once
#ifndef _CPEOPLE_
#define _CPEOPLE_

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <stdlib.h>
#include <windows.h>
#include "CVEHICLE.h"


using namespace std;

#define consoleWidth	85
#define consoleHeight	25

<<<<<<< HEAD
void ShowConsoleCursor(bool showFlag);
=======
>>>>>>> fe8ab54096b41430a933eda794a37edbb704a899

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
<<<<<<< HEAD
	void Control();
	bool isImpact(const CVEHICLE*& a);
=======
	//bool isImpact(const CVEHICLE*&);
>>>>>>> fe8ab54096b41430a933eda794a37edbb704a899
	//bool isImpact(const CANIMAL*&);
	//bool isFinish();
	//bool isDead();
};


#endif