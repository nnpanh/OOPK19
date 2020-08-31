#include"CGAME.h"

CGAME::CGAME() {
	m_truck.resize(2);
	m_car.resize(2);
	m_bird.resize(2);
	m_dinausor.resize(2);
}
void CGAME::resize(int newSize) {
	m_truck.resize(newSize);
	m_car.resize(newSize);
	m_bird.resize(newSize);
	m_dinausor.resize(newSize);
}

void CGAME::drawGame(char key) {
	//setColor(1);
	for (int i = 0; i < m_truck.size(); i++) {
		m_truck[i].draw(key);
	}
	//setColor(2);
	for (int i = 0; i < m_car.size(); i++) {
		m_car[i].draw(key);
	}
	//setColor(3);
	for (int i = 0; i < m_dinausor.size(); i++) {
		m_dinausor[i].draw(key);
	}
	//setColor(4);
	for (int i = 0; i < m_bird.size(); i++) {
		m_bird[i].draw(key);
	}
	//setColor(5);
	people.draw(key);
	getTrafficLight().drawLight(1, 17, 219);
	getTrafficLight().drawLight(WIDTH - 2, 13, 219);
	setColor(15);
}
CPEOPLE& CGAME::getPeople() {
	return people;
}
vector <CTRUCK>& CGAME::getTruck() {
	return m_truck;
}
vector <CCAR>& CGAME::getCar() {
	return m_car;
}
vector <Dinausor>& CGAME::getDinausor() {
	return m_dinausor;
}
vector <Bird>& CGAME::getBird() {
	return m_bird;
}
Traffic& CGAME::getTrafficLight() {
	return trafficLight;
}

//reset the game to the beginning
void CGAME::resetGame()
{
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
		p.m_x = 15 * i + 2; p.m_y = 15;
		m_car[i].set(p);
	}
	for (int i = 0; i < m_truck.size(); i++) {
		p.m_x = WIDTH - 5 - 15 * i; p.m_y = 19;
		m_truck[i].set(p);
	}
	p.m_x = WIDTH / 2; p.m_y = 23;
	people.setPoint(p);
}

//exit the game
void CGAME::exitGame(HANDLE t)
{
	TerminateThread(t, 0);

}

//start the game
void CGAME::startGame()
{
	system("cls");
	resetGame();
	drawBoard(0, 0, WIDTH, HEIGHT, 0, 0);
}

//load the exist data from the *.txt file
void CGAME::loadGame(string fileName)
{
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
		trafficLight.setLight(light);

		bool state;
		int level;
		getline(myfile, line);
		ss.clear();
		ss << line;
		ss >> p.m_x >> p.m_y >> state >> level;
		people.setPoint(p);
		people.setState(state);
		people.setLevel(level);
		myfile.close();
	}
	else {
		gotoXY(WIDTH / 2 - 10, HEIGHT / 2 + 1);
		cout << "Khong the tim thay file: " << fileName << endl;
		exit(0);
	}
}

//save the game to the *.txt file
void CGAME::saveGame(string fileName)
{
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
		myfile << trafficLight.getLight() << endl;
		myfile << people.getFirstPoint().m_x << " " << people.getFirstPoint().m_y << " " << people.getState() << " " << people.getLevel() << endl;
		myfile.close();
	}
	else {
		gotoXY(WIDTH / 2 - 10, HEIGHT / 2 + 1);
		cout << "Khong the luu file!" << fileName << endl;
		exit(0);
	}
}

//pause the game
void CGAME::pauseGame(HANDLE t)
{
	SuspendThread(t);
}

//resume the game
void CGAME::resumeGame(HANDLE t)
{
	ResumeThread(t);
}

//update the new position of object
void CGAME::updatePosPeople(char key)
{
	switch (key) {
	case 'A':
		people.Left();
		break;
	case 'D':
		people.Right();
		break;
	case 'W':
		people.Up();
		break;
	case 'S':
		people.Down();
		break;
	}

}
void CGAME::updatePosVehicle()
{
	for (int i = 0; i < m_truck.size(); i++)
		m_truck[i].move();
	for (int i = 0; i < m_car.size(); i++)
		m_car[i].move();
}
void CGAME::updatePosAnimal()
{
	for (int i = 0; i < m_bird.size(); i++)
		m_bird[i].move();
	for (int i = 0; i < m_dinausor.size(); i++)
		m_dinausor[i].move();
}
