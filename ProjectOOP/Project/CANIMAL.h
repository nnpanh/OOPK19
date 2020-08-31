#pragma once
#include "Console.h"

class CANIMAL
{
protected:
	vector<Point> m_p;
public:
	virtual void move() = 0;
	virtual void set(Point) = 0;

	bool isImpact(vector<Point>);

	//draw the point
	void draw(char);
	Point& getFirstPoint();
};

class Bird :public CANIMAL
{
public:
	Bird();
	void move();
	void set(Point);
};

class Dinausor :public CANIMAL
{
public:
	Dinausor();
	void move();
	void set(Point);
};