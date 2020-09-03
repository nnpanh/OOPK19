#pragma once
#include "CPEOPLE.h"
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include <fstream>
#include <sstream>

class Game
{
private:
	vector <CTRUCK> m_truck;
	vector <CCAR> m_car;
	vector <Dinausor> m_dinausor;
	vector <Bird> m_bird;
	Traffic m_trafficLight;
	CPEOPLE m_people;
public:
	Game();

	//resize the vector
	void resize(int);

	//draw people, animals and vehicles
	void drawGame(char);

	//get the information of people, vehicles and animal
	CPEOPLE& getPeople();
	vector <CTRUCK>& getTruck();
	vector <CCAR>& getCar();
	vector <Dinausor>& getDinausor();
	vector <Bird>& getBird();
	Traffic & getTrafficLight();

	//reset the game to the beginning
	void resetGame();

	//exit the game
	void exitGame(HANDLE);

	//start the game
	void startGame();

	//load the exist data from the *.txt file
	void loadGame(string);

	//save the game to the *.txt file
	void saveGame(string);

	//pause the game
	void pauseGame(HANDLE);

	//resume the game
	void resumeGame(HANDLE);

	//update the new position of object
	void updatePosPeople(char);
	void updatePosVehicle();
	void updatePosAnimal();
};