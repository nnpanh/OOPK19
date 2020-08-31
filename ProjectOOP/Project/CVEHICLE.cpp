#include "CVEHICLE.h"

//VEHICLE
bool CVEHICLE::isImpact(vector<Point>p)
{
	for (int i = 0; i < p.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			if (p[i].m_x == a[j].m_x && p[i].m_y == a[j].m_y)
				return true;
		}
	}
	return false;
}
void CVEHICLE::draw(char key)
{
	for (int i = 0; i < a.size(); i++)
	{
		gotoXY(a[i].m_x, a[i].m_y);
		cout << key;
	}
}
Point CVEHICLE::getFirstPoint()
{
	return a[0];
}

//TRUCK
CTRUCK::CTRUCK() :CVEHICLE() 
{
	a.resize(5);
}
void CTRUCK::move()
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i].m_x == 1)
			a[i].m_x = WIDTH - 2;
		else
			a[i].m_x--;
	}
}
void CTRUCK::set(Point p)
{
	a.resize(5);
	a[0].m_x = p.m_x;
	a[0].m_y = p.m_y;
	a[1].m_x = p.m_x + 1;
	a[1].m_y = p.m_y;
	a[2].m_x = p.m_x + 2;
	a[2].m_y = p.m_y;
	a[3].m_x = p.m_x + 1;
	a[3].m_y = p.m_y - 1;
	a[4].m_x = p.m_x + 2;
	a[4].m_y = p.m_y - 1;
}


//CAR
CCAR::CCAR():CVEHICLE() {
	a.resize(6);
}
void CCAR::move()
{
	for (int i = 0; i < a.size(); i++) {
		if (a[i].m_x == WIDTH - 2)
			a[i].m_x = 1;
		else
			a[i].m_x++;
	}
}
void CCAR::set(Point p) {
	a.resize(6);
	a[0].m_x = p.m_x;
	a[0].m_y = p.m_y;
	a[1].m_x = p.m_x + 1;
	a[1].m_y = p.m_y;
	a[2].m_x = p.m_x + 2;
	a[2].m_y = p.m_y;
	a[3].m_x = p.m_x + 3;
	a[3].m_y = p.m_y;
	a[4].m_x = p.m_x + 1;
	a[4].m_y = p.m_y - 1;
	a[5].m_x = p.m_x + 2;
	a[5].m_y = p.m_y - 1;
}


