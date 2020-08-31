#pragma once
#include "CPEOPLE.h"
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include <fstream>
#include <sstream>

class Game
{
private:
	vector <Truck> m_truck;
	vector <Car> m_car;
	vector <Dinausor> m_dinausor;
	vector <Bird> m_bird;
	/*TrafficLight m_trafficLight;
	People m_people;*/
public:
	Game();

	void resize(int); //resize number of object/vector

	void drawGame(char);//draw people, animals and vehicles

	People& getPeople();
	vector <Truck>& getTruck();
	vector <Car>& getCar();
	vector <Dinausor>& getDinausor();
	vector <Bird>& getBird();
	TrafficLight& getTrafficLight();

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