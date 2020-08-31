#include"CANIMAL.h"

bool CANIMAL::isImpact(vector<Point> p) {
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < m_p.size(); j++) {
			if (p[i].m_x == m_p[j].m_x && p[i].m_y == m_p[j].m_y)
				return true;
		}
	}
	return false;
}

void CANIMAL::draw(char key) {
	for (int i = 0; i < m_p.size(); i++) {
		gotoXY(m_p[i].m_x, m_p[i].m_y);
		cout << key;
	}
}

Point& CANIMAL::getFirstPoint() {
	return m_p[0];
}

Bird::Bird() {
	m_p.resize(3);
}

void Bird::move() {
	for (int i = 0; i < m_p.size(); i++) {
		if (m_p[i].m_x == WIDTH - 2)
			m_p[i].m_x = 1;
		else
			m_p[i].m_x++;
	}
}
void Bird::set(Point p) {
	m_p.resize(3);
	m_p[0].m_x = p.m_x;
	m_p[0].m_y = p.m_y;
	m_p[1].m_x = p.m_x + 1;
	m_p[1].m_y = p.m_y + 1;
	m_p[2].m_x = p.m_x - 1;
	m_p[2].m_y = p.m_y + 1;
}
Dinausor::Dinausor() {
	m_p.resize(7);
}

void Dinausor::move() {
	for (int i = 0; i < m_p.size(); i++) {
		if (m_p[i].m_x == 1)
			m_p[i].m_x = WIDTH - 2;
		else
			m_p[i].m_x--;
	}

}
void Dinausor::set(Point p) {
	m_p.resize(7);
	m_p[0].m_x = p.m_x;
	m_p[0].m_y = p.m_y;
	m_p[1].m_x = p.m_x + 1;
	m_p[1].m_y = p.m_y;
	m_p[2].m_x = p.m_x + 2;
	m_p[2].m_y = p.m_y;
	m_p[3].m_x = p.m_x + 1;
	m_p[3].m_y = p.m_y - 1;
	m_p[4].m_x = p.m_x + 2;
	m_p[4].m_y = p.m_y - 1;
	m_p[5].m_x = p.m_x + 3;
	m_p[5].m_y = p.m_y - 1;
	m_p[6].m_x = p.m_x + 3;
	m_p[6].m_y = p.m_y - 2;
}
