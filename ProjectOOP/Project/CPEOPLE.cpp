#include "CPEOPLE.h"
#include "Console.h"
CPEOPLE::CPEOPLE()
{
	Point p = { WIDTH / 2, HEIGHT - 2 };
	setPoint(p);
	state = true;
	level = 2;
}

void CPEOPLE::draw(char key)
{
	for (int i = 0; i < a.size(); i++) {
		gotoXY(a[i].m_x, a[i].m_y);
		cout << key;
	}

}

void CPEOPLE::Up()
{
	if (a[0].m_y > 5) {
		for (int i = 0; i < a.size(); i++)
			a[i].m_y -= 4;
	}
}

void CPEOPLE::Left()
{
	if (a[0].m_x > 5) {
		for (int i = 0; i < a.size(); i++)
			a[i].m_x -= 4;
	}
}

void CPEOPLE::Right()
{
	if (a[0].m_x < WIDTH - 5) {
		for (int i = 0; i < a.size(); i++)
			a[i].m_x += 4;
	}

}
void CPEOPLE::Down()
{
	if (a[0].m_y < HEIGHT - 5) {
		for (int i = 0; i < a.size(); i++)
			a[i].m_y += 4;
	}

}
 

void CPEOPLE::setPoint(Point p) {
	a.resize(6);
	a[0].m_x = p.m_x;
	a[0].m_y = p.m_y;
	a[1].m_x = p.m_x - 2;
	a[1].m_y = p.m_y;
	a[2].m_x = p.m_x;
	a[2].m_y = p.m_y - 1;
	a[3].m_x = p.m_x - 1;
	a[3].m_y = p.m_y - 1;
	a[4].m_x = p.m_x - 2;
	a[4].m_y = p.m_y - 1;
	a[5].m_x = p.m_x - 1;
	a[5].m_y = p.m_y - 2;
}
void CPEOPLE::setState(bool state) {
	state = state;
}
void CPEOPLE::setLevel(int level) {
	level = level;
}

bool CPEOPLE::isFinish()
{
}
bool CPEOPLE::isDead()
{
}

