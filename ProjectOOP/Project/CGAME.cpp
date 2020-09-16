#include"CGAME.h"

Game::Game() {
	m_truck.resize(2);
	m_car.resize(2);
	m_bird.resize(2);
	m_dinausor.resize(2);
}
void Game::resize(int newSize) {
	m_truck.resize(newSize);
	m_car.resize(newSize);
	m_bird.resize(newSize);
	m_dinausor.resize(newSize);
}

void Game::drawGame(char key) {
	for (int i = 0; i < m_truck.size(); i++) {
		m_truck[i].draw(key);
	}
	for (int i = 0; i < m_car.size(); i++) {
		m_car[i].draw(key);
	}
	for (int i = 0; i < m_dinausor.size(); i++) {
		m_dinausor[i].draw(key);
	}
	for (int i = 0; i < m_bird.size(); i++) {
		m_bird[i].draw(key);
	}
	m_people.draw(key);
	getTrafficLight().drawLight(1, 17, 219);
	getTrafficLight().drawLight(WIDTH - 2, 13, 219);
	setColor(15);
}
CPEOPLE& Game::getPeople() {
	return m_people;
}
vector <CTRUCK>& Game::getTruck() {
	return m_truck;
}
vector <CCAR>& Game::getCar() {
	return m_car;
}
vector <Dinausor>& Game::getDinausor() {
	return m_dinausor;
}
vector <Bird>& Game::getBird() {
	return m_bird;
}
Traffic& Game::getTrafficLight() {
	return m_trafficLight;
}
void Game::resetGame() {
	Point p;
	for (int i = 0; i < m_bird.size(); i++) {
		p.m_x = 15 * i + 2; p.m_y = 5;
		m_bird[i].set(p);
	}
	for (int i = 0; i < m_dinausor.size(); i++) {
		p.m_x = WIDTH - 5 - 15 * i; p.m_y = 11;
		m_dinausor[i].set(p);
	}
	for (int i = 0; i < m_car.size(); i++) {
		p.m_x = 15 * i + 2; p.m_y = 14;
		m_car[i].set(p);
	}
	for (int i = 0; i < m_truck.size(); i++) {
		p.m_x = WIDTH - 5 - 15 * i; p.m_y = 18;
		m_truck[i].set(p);
	}
	p.m_x = WIDTH / 2; p.m_y = 23;
	m_people.setPoint(p);
}
void Game::exitGame(HANDLE t)
{
	TerminateThread(t, 0);
}

void Game::startGame() {
	system("cls");
	resetGame();
	drawBoard(0, 0, WIDTH, HEIGHT, 0, 0);
}

void Game::loadGame(string fileName) {
	fileName = fileName + ".dat";
	ifstream myfile;
	myfile.open(fileName, ios::binary);
	if (myfile.is_open()) {
		string line;
		stringstream ss;
		Point p;
		resize(0);
		getline(myfile, line);
		ss.clear();
		ss << line;
		while (!ss.eof()) {
			CTRUCK t;
			ss >> p.m_x >> p.m_y;
			t.set(p);
			m_truck.push_back(t);
		}
		getline(myfile, line);
		ss.clear();
		ss << line;
		while (!ss.eof()) {
			CCAR c;
			ss >> p.m_x >> p.m_y;
			c.set(p);
			m_car.push_back(c);
		}
		getline(myfile, line);
		ss.clear();
		ss << line;
		while (!ss.eof()) {
			Dinausor d;
			ss >> p.m_x >> p.m_y;
			d.set(p);
			m_dinausor.push_back(d);
		}
		getline(myfile, line);
		ss.clear();
		ss << line;
		while (!ss.eof()) {
			Bird b;
			ss >> p.m_x >> p.m_y;
			b.set(p);
			m_bird.push_back(b);
		}
		getline(myfile, line);
		ss.clear();
		ss << line;
		int light;
		ss >> light;
		m_trafficLight.setLight(light);

		bool state;
		int level;
		getline(myfile, line);
		ss.clear();
		ss << line;
		ss >> p.m_x >> p.m_y >> state >> level;
		m_people.setPoint(p);
		m_people.setState(state);
		m_people.setLevel(level);
		myfile.close();
	}
	else {
		gotoXY(WIDTH / 2 - 10, HEIGHT / 2 + 1);
		cout << "Khong the tim thay file: " << fileName << endl;
		exit(0);
	}
}

void Game::saveGame(string fileName) {
	ofstream myfile;
	fileName = fileName + ".dat";
	myfile.open(fileName, ios::binary);
	if (myfile.is_open()) {
		for (int i = 0; i < m_truck.size(); i++) {
			myfile << m_truck[i].getFirstPoint().m_x << " " << m_truck[i].getFirstPoint().m_y << " ";
		}
		myfile << endl;
		for (int i = 0; i < m_car.size(); i++) {
			myfile << m_car[i].getFirstPoint().m_x << " " << m_car[i].getFirstPoint().m_y << " ";
		}
		myfile << endl;
		for (int i = 0; i < m_dinausor.size(); i++) {
			myfile << m_dinausor[i].getFirstPoint().m_x << " " << m_dinausor[i].getFirstPoint().m_y << " ";
		}
		myfile << endl;
		for (int i = 0; i < m_bird.size(); i++) {
			myfile << m_bird[i].getFirstPoint().m_x << " " << m_bird[i].getFirstPoint().m_y << " ";
		}
		myfile << endl;
		myfile << m_trafficLight.getLight() << endl;
		myfile << m_people.getFirstPoint().m_x << " " << m_people.getFirstPoint().m_y << " " << m_people.getState() << " " << m_people.getLevel() << endl;
		myfile.close();
	}
	else {
		gotoXY(WIDTH / 2 - 10, HEIGHT / 2 + 1);
		cout << "Khong the luu file!" << fileName << endl;
		exit(0);
	}
}

void Game::pauseGame(HANDLE t)
{
	SuspendThread(t);
}

//resume the game
void Game::resumeGame(HANDLE t)
{
	ResumeThread(t);
}

void Game::updatePosPeople(char key) {
	switch (key) {
	case 'A':
		m_people.Left();
		break;
	case 'D':
		m_people.Right();
		break;
	case 'W':
		m_people.Up();
		break;
	case 'S':
		m_people.Down();
		break;
	}
}
void Game::updatePosVehicle() {
	for (int i = 0; i < m_truck.size(); i++)
		m_truck[i].move();
	for (int i = 0; i < m_car.size(); i++)
		m_car[i].move();
}
void Game::updatePosAnimal() {
	for (int i = 0; i < m_bird.size(); i++)
		m_bird[i].move();
	for (int i = 0; i < m_dinausor.size(); i++)
		m_dinausor[i].move();
}
