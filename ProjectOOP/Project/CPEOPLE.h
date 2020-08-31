#pragma once
#ifndef _CPEOPLE_
#define _CPEOPLE_

#include "Console.h"
const int MAX_LEVEL = 6;

class CPEOPLE {
private:
	vector<Point> a;
	bool state;
	int level;
public:
	CPEOPLE();
	void draw(char key);

	void Up();
	void Left();
	void Right();
	void Down();

	template<class T>
	bool isImpact(vector <T> obj) {
		for (int i = 0; i < ob.size(); i++) {
			if (obj[i].isImpact(a)) {
				return true;
			}
		}
		return false;
	}

	//set the people data
	void setPoint(Point);
	void setState(bool);
	void setLevel(int);

	bool isFinish();
	bool isDead();

	//check the level of people
	bool isLevelUp();
	//get level of people
	int& getLevel();
	Point& getFirstPoint();
	bool& getState();

};


#endif