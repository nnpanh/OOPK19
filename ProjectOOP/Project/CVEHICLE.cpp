#include "CVEHICLE.h"

//VEHICLE
bool CVEHICLE::isImpact(vector<Point>p)
{
	for (auto i = 0; i < p.size(); i++)
	{
		for (auto j = 0; j < a.size(); j++)
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
		if (key != (char)255)
			cout << a[i].data;
		else
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
	for (auto i = 0; i < a.size(); i++)
	{
		if (a[i].m_x == 1)
			a[i].m_x = WIDTH - 2;
		else
			a[i].m_x--;
	}
}
void CTRUCK::set(Point p)
{
	a.resize(7);
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

	a[5].m_x = p.m_x;
	a[5].m_y = p.m_y + 1;
	a[6].m_x = p.m_x + 2;
	a[6].m_y = p.m_y + 1;

	a[0].data = a[1].data = a[2].data = a[3].data = a[4].data = (char)219;

	a[5].data = a[6].data = 'O';

}


//CAR
CCAR::CCAR():CVEHICLE() 
{
	a.resize(6);
}
void CCAR::move()
{
	for (auto i = 0; i < a.size(); i++) {
		if (a[i].m_x == WIDTH - 2)
			a[i].m_x = 1;
		else
			a[i].m_x++;
	}
}
void CCAR::set(Point p) 
{
	a.resize(10);
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

	a[6].m_x = p.m_x;
	a[6].m_y = p.m_y + 1;
	a[7].m_x = p.m_x + 3;
	a[7].m_y = p.m_y + 1;

	a[0].data = a[1].data = a[2].data = a[3].data = a[4].data = a[5].data = (char)219;
	a[6].data = a[7].data = 'O';
}


//TRAFFIC LIGHT
void Traffic::drawLight(int x, int y, int key) 
{
	gotoXY(x, y);
	if (trafficLight != 0) 
	{
		setColor(2);
		cout << char(key);
	}
	else 
	{
		setColor(4);
		cout << char(key);
	}
}
Traffic::Traffic() {
	trafficLight = 0;
}
void Traffic::changeLight() {
	if (trafficLight == 0) {
		trafficLight = 1;
	}
	else {
		trafficLight = 0;
	}
}
int& Traffic::getLight() {
	return trafficLight;
}
void Traffic::setLight(int light) {
	trafficLight = light;
}
