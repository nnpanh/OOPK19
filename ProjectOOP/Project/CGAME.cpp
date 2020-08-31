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
	setColor(1);
	for (int i = 0; i < m_truck.size(); i++) {
		m_truck[i].draw(key);
	}
	setColor(2);
	for (int i = 0; i < m_car.size(); i++) {
		m_car[i].draw(key);
	}
	setColor(3);
	for (int i = 0; i < m_dinausor.size(); i++) {
		m_dinausor[i].draw(key);
	}
	setColor(4);
	for (int i = 0; i < m_bird.size(); i++) {
		m_bird[i].draw(key);
	}
	setColor(5);
	m_people.draw(key);
	getTrafficLight().drawLight(1, 17, 219);
	getTrafficLight().drawLight(WIDTH - 2, 13, 219);
	setColor(15);
}
People& Game::getPeople() {
	return m_people;
}
vector <Truck>& Game::getTruck() {
	return m_truck;
}
vector <Car>& Game::getCar() {
	return m_car;
}
vector <Dinausor>& Game::getDinausor() {
	return m_dinausor;
}
vector <Bird>& Game::getBird() {
	return m_bird;
}
TrafficLight& Game::getTrafficLight() {
	return m_trafficLight;
}