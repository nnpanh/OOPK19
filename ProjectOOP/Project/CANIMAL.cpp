#include"CANIMAL.h"

bool CANIMAL::isImpact(vector<Point> p) {
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if (p[i].m_x == a[j].m_x && p[i].m_y == a[j].m_y)
				return true;
		}
	}
	return false;
}

void CANIMAL::draw(char key) {
	for (int i = 0; i < a.size(); i++) {
		gotoXY(a[i].m_x, a[i].m_y);
		cout << key;
	}
}

Point& CANIMAL::getFirstPoint() {
	return a[0];
}

Bird::Bird() {
	a.resize(3);
}

void Bird::move() {
	for (int i = 0; i < a.size(); i++) {
		if (a[i].m_x == WIDTH - 2)
			a[i].m_x = 1;
		else
			a[i].m_x++;
	}
}
void Bird::set(Point p) {
	a.resize(3);
	a[0].m_x = p.m_x;
	a[0].m_y = p.m_y + 1;
	a[1].m_x = p.m_x + 1;
	a[1].m_y = p.m_y;
	a[2].m_x = p.m_x -1;
	a[2].m_y = p.m_y;
}
Dinausor::Dinausor() {
	a.resize(7);
}

void Dinausor::move() {
	for (int i = 0; i < a.size(); i++) {
		if (a[i].m_x == 1)
			a[i].m_x = WIDTH - 2;
		else
			a[i].m_x--;
	}

}
void Dinausor::set(Point p) {
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
	a[5].m_x = p.m_x + 3;
	a[5].m_y = p.m_y - 1;
	a[6].m_x = p.m_x + 3;
	a[6].m_y = p.m_y - 2;
}
