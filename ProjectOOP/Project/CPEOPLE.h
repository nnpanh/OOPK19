#pragma once
#ifndef _CPEOPLE_
#define _CPEOPLE_

#include <iostream>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include <vector>
#include "CVEHICLE.h"
#include "Console.h"
using namespace std;


void doPeople();
class CPEOPLE {
private:
	int mX, mY;
	bool mState;
public:
	int getX();
	int getY();
	void draw();
	CPEOPLE();
	void Up();
	void Left();
	void Right();
	void Down();
	//template<class T>
	/*bool isImpact(vector <T> ob) {
		for (int i = 0; i < ob.size(); i++) {
			if (ob[i].isImpact(m_p)) {
				return true;
			}
		}
		return false;
	}*/
	bool isFinish();
	bool isDead();
};


#endif