#ifndef _CVEHICLE_H_
#define _CVEHICLE_H_

#include "Console.h"

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
	vector<Point> a;
public:
	virtual void move() = 0;
	virtual void set(Point) = 0;
	bool isImpact(vector <Point>);
	void draw(char);
	Point getFirstPoint();
	
};

class CTRUCK final :public CVEHICLE
{
public:
	CTRUCK();
	void move();
	void set(Point);
};

class CCAR final :public CVEHICLE
{
public:
	CCAR();
		void move();
	void set(Point);
};

class Traffic
{
protected:
	int trafficLight; //0 is red and other is green
public:
	Traffic();
	void changeLight();
	int& getLight();
	void drawLight(int, int, int);
	void setLight(int);
};


#endif