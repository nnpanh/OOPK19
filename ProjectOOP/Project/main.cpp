#pragma once
#include"CGame.h"
#include<thread>
#include<conio.h>
#include <cwchar>
#include<mmsystem.h>

bool sound = true;
int sleepTime = 80;
char MOVING;
Game* g;

void subThread() {
	int timeTraffic = 0;
	while (1) {
		int temp = timeTraffic % 200;
		if (!g->getPeople().isDead()) {
			g->drawGame(255);
			gotoXY(WIDTH + 8, HEIGHT / 2);
			cout << "Level: " << g->getPeople().getLevel();
			gotoXY(WIDTH + 8, HEIGHT / 2 + 1);
			if (sound)
				cout << "Sound: On";
			else
				cout << "Sound: Off";
			g->updatePosPeople(MOVING);
			MOVING = ' ';
			if (temp == 60) {
				g->getTrafficLight().changeLight();
			}
			if (temp == 199) {
				g->getTrafficLight().changeLight();
			}
			if (g->getTrafficLight().getLight() != 0) {
				g->updatePosVehicle();
			}
			g->updatePosAnimal();
			g->drawGame(219);
			if (g->getPeople().isImpact(g->getTruck()) ||
				g->getPeople().isImpact(g->getCar()) ||
				g->getPeople().isImpact(g->getBird()) ||
				g->getPeople().isImpact(g->getDinausor())) {
				if (sound) {
					mciSendString(TEXT("stop BACKGROUND.mp3"), NULL, 0, 0);
					mciSendString(TEXT("play Endgame.mp3"), NULL, 0, 0);
				}
				animation(0, 0, WIDTH, HEIGHT, 0, 0);
				gotoXY(0, HEIGHT + 1);
				cout << "Dead, press Y to start a new game!";
				g->getPeople().setState(false);
			}
			else if (g->getPeople().isFinish()) {
				g->drawGame(255);
				g->getPeople().setLevel(2);
				g->resize(2);
				g->resetGame();
			}
			else if (g->getPeople().isLevelUp()) {
				g->drawGame(255);
				g->getPeople().setLevel(g->getPeople().getLevel() + 1);
				g->resize(g->getPeople().getLevel());
				g->resetGame();
			}
			if (timeTraffic == 70) {
				if (sound) {
					mciSendString(TEXT("play BIRD.mp3"), NULL, 0, NULL);
				}
			}
			if (timeTraffic == 120) {
				if (sound) {
					mciSendString(TEXT("play DINAUSOR.mp3"), NULL, 0, NULL);
				}
			}
			if (timeTraffic == 200)
				timeTraffic = 0;
			else
				timeTraffic++;
			Sleep(sleepTime);
		}
	}
}

int main() {
	int temp;
	g = new Game();
	fixConsoleWindow();
	ShowConsoleCursor(false);
	setColor(15);
	drawBox(0, 0, WIDTH, HEIGHT, 0, 0);
	setColor(2);
	if (sound) {
		mciSendString(TEXT("play BACKGROUND.mp3 repeat"), NULL, 0, NULL);
	}
	setColor(15);
	system("cls");
	drawBox(0, 0, WIDTH, HEIGHT, 0, 0);
	gotoXY(WIDTH / 2 - 5, HEIGHT / 2 - 3);
	setColor(9);
	gotoXY(10, 2);
	gotoXY(WIDTH / 2 - 5, HEIGHT / 2 - 1);
	setColor(128);
	cout << "Start Game";
	setColor(15);
	gotoXY(WIDTH / 2 - 5, HEIGHT / 2);
	cout << "Load Game";
	gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 1);
	cout << "Setting";
	int curChosen = 0;
	thread t1(subThread);
	HANDLE handle_t1 = t1.native_handle();
	g->pauseGame(handle_t1);
	while (1) {
		temp = toupper(getch());
		if (temp == 'W') {
			if (curChosen == 0) {
				gotoXY(WIDTH / 2 - 5, HEIGHT / 2 - 1);
				setColor(15);
				cout << "Start Game";

				curChosen = 2;

				gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 1);
				setColor(128);
				cout << "Setting";
			}
			else if (curChosen == 1) {
				gotoXY(WIDTH / 2 - 5, HEIGHT / 2);
				setColor(15);
				cout << "Load Game";

				curChosen = 0;

				gotoXY(WIDTH / 2 - 5, HEIGHT / 2 - 1);
				setColor(128);
				cout << "Start Game";
			}
			else {
				gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 1);
				setColor(15);
				cout << "Setting";

				curChosen = 1;

				gotoXY(WIDTH / 2 - 5, HEIGHT / 2);
				setColor(128);
				cout << "Load Game";
			}
		}
		else if (temp == 'S') {
			if (curChosen == 2) {
				gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 1);
				setColor(15);
				cout << "Setting";

				curChosen = 0;

				gotoXY(WIDTH / 2 - 5, HEIGHT / 2 - 1);
				setColor(128);
				cout << "Start Game";
			}
			else if (curChosen == 1) {
				gotoXY(WIDTH / 2 - 5, HEIGHT / 2);
				setColor(15);
				cout << "Load Game";

				curChosen = 2;

				gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 1);
				setColor(128);
				cout << "Setting";
			}
			else {
				gotoXY(WIDTH / 2 - 5, HEIGHT / 2 - 1);
				setColor(15);
				cout << "Start Game";

				curChosen = 1;

				gotoXY(WIDTH / 2 - 5, HEIGHT / 2);
				setColor(128);
				cout << "Load Game";
			}
		}
		else if (temp == 13) {
			if (curChosen == 0) {
				setColor(15);
				g->startGame();
				break;
			}
			else if (curChosen == 1) {
				setColor(15);
				system("cls");
				drawBox(0, 0, WIDTH, HEIGHT, WIDTH / 2 - 10, HEIGHT / 2);
				string fileName;
				cout << "Nhap ten file: ";
				cin >> fileName;
				g->loadGame(fileName);
				system("cls");
				drawBoard(0, 0, WIDTH, HEIGHT, 0, 0);
				break;
			}
			else {
				setColor(128);
				gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 2);
				cout << "Sound";
				setColor(15);
				gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 3);
				cout << "Dificulty";
				int curSetting = 0;
				while (1) {
					temp = toupper(getch());
					if (temp == 'W') {
						if (curSetting == 0) {
							setColor(15);
							gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 2);
							cout << "Sound";
							setColor(128);
							gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 3);
							cout << "Difficulty";
							curSetting = 1;
						}
						else {
							setColor(15);
							gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 3);
							cout << "Difficult";
							setColor(128);
							gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 2);
							cout << "Sound";
							curSetting = 0;
						}
					}
					else if (temp == 'S') {
						if (curSetting == 0) {
							setColor(15);
							gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 2);
							cout << "Sound";
							setColor(128);
							gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 3);
							cout << "Difficult";
							curSetting = 1;
						}
						else {
							setColor(15);
							gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 3);
							cout << "Difficult";
							setColor(128);
							gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 2);
							cout << "Sound";
							curSetting = 0;
						}
					}
					else if (temp == 13) {
						if (curSetting == 0) {
							setColor(128);
							gotoXY(WIDTH / 2 + 1, HEIGHT / 2 + 2);
							cout << "On";
							setColor(15);
							gotoXY(WIDTH / 2 + 5, HEIGHT / 2 + 2);
							cout << "Off";
							int curSound = 0;
							while (1) {
								temp = toupper(getch());
								if (temp == 'A') {
									if (curSound == 0) {
										setColor(15);
										gotoXY(WIDTH / 2 + 1, HEIGHT / 2 + 2);
										cout << "On";
										setColor(128);
										gotoXY(WIDTH / 2 + 5, HEIGHT / 2 + 2);
										cout << "Off";
										curSound = 1;
									}
									else {
										setColor(15);
										gotoXY(WIDTH / 2 + 5, HEIGHT / 2 + 2);
										cout << "Off";
										setColor(128);
										gotoXY(WIDTH / 2 + 1, HEIGHT / 2 + 2);
										cout << "On";
										curSound = 0;
									}
								}
								else if (temp == 'D') {
									if (curSound == 0) {
										setColor(15);
										gotoXY(WIDTH / 2 + 1, HEIGHT / 2 + 2);
										cout << "On";
										setColor(128);
										gotoXY(WIDTH / 2 + 5, HEIGHT / 2 + 2);
										cout << "Off";
										curSound = 1;
									}
									else {
										setColor(15);
										gotoXY(WIDTH / 2 + 5, HEIGHT / 2 + 2);
										cout << "Off";
										setColor(128);
										gotoXY(WIDTH / 2 + 1, HEIGHT / 2 + 2);
										cout << "On";
										curSound = 0;
									}
								}
								else if (temp == 13) {
									if (curSound == 0) {
										sound = true;
										mciSendString(TEXT("play BACKGROUND.mp3 repeat"), NULL, 0, NULL);
									}
									else {
										sound = false;
										mciSendString(TEXT("stop BACKGROUND.mp3"), NULL, 0, NULL);
									}
								}
								else if (temp == 27) {
									setColor(0);
									gotoXY(WIDTH / 2 + 5, HEIGHT / 2 + 2);
									cout << "   ";
									gotoXY(WIDTH / 2 + 1, HEIGHT / 2 + 2);
									cout << "  ";
									setColor(15);
									break;
								}
							}
						}
						else {
							setColor(128);
							gotoXY(WIDTH / 2 + 5, HEIGHT / 2 + 3);
							cout << "Easy";
							setColor(15);
							gotoXY(WIDTH / 2 + 11, HEIGHT / 2 + 3);
							cout << "Difficult";
							int curDifficulty = 0;
							while (1) {
								temp = toupper(getch());
								if (temp == 'A') {
									if (curDifficulty == 0) {
										setColor(15);
										gotoXY(WIDTH / 2 + 5, HEIGHT / 2 + 3);
										cout << "Easy";
										setColor(128);
										gotoXY(WIDTH / 2 + 11, HEIGHT / 2 + 3);
										cout << "Difficult";
										curDifficulty = 1;
									}
									else {
										setColor(15);
										gotoXY(WIDTH / 2 + 11, HEIGHT / 2 + 3);
										cout << "Difficult";
										setColor(128);
										gotoXY(WIDTH / 2 + 5, HEIGHT / 2 + 3);
										cout << "Easy";
										curDifficulty = 0;
									}
								}
								else if (temp == 'D') {
									if (curDifficulty == 0) {
										setColor(15);
										gotoXY(WIDTH / 2 + 5, HEIGHT / 2 + 3);
										cout << "Easy";
										setColor(128);
										gotoXY(WIDTH / 2 + 11, HEIGHT / 2 + 3);
										cout << "Difficult";
										curDifficulty = 1;
									}
									else {
										setColor(15);
										gotoXY(WIDTH / 2 + 11, HEIGHT / 2 + 3);
										cout << "Difficult";
										setColor(128);
										gotoXY(WIDTH / 2 + 5, HEIGHT / 2 + 3);
										cout << "Easy";
										curDifficulty = 0;
									}
								}
								else if (temp == 13) {
									if (curDifficulty == 0) {
										sleepTime = 80;
									}
									else {
										sleepTime = 60;
									}
								}
								else if (temp == 27) {
									setColor(0);
									gotoXY(WIDTH / 2 + 11, HEIGHT / 2 + 3);
									cout << "         ";
									gotoXY(WIDTH / 2 + 5, HEIGHT / 2 + 3);
									cout << "    ";
									setColor(15);
									break;
								}
							}
						}
					}
					else if (temp == 27) {
						setColor(0);
						gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 2);
						cout << "     ";
						gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 3);
						cout << "          ";
						setColor(15);
						break;
					}
				}
			}
		}
	}
	g->resumeGame(handle_t1);
	while (1) {
		temp = toupper(getch());
		if (!g->getPeople().isDead()) {
			if (temp == 27) {
				g->exitGame(handle_t1);
				break;
			}
			else if (temp == 'P') {
				g->pauseGame(handle_t1);
			}
			else if (temp == 'L' || temp == 'T') {
				g->pauseGame(handle_t1);
				setColor(15);
				system("cls");
				drawBox(0, 0, WIDTH, HEIGHT, WIDTH / 2 - 10, HEIGHT / 2);
				string fileName;
				cout << "Nhap ten file: ";
				cin >> fileName;
				if (temp == 'L')
					g->saveGame(fileName);
				else
					g->loadGame(fileName);
				system("cls");
				drawBoard(0, 0, WIDTH, HEIGHT, 0, 0);
				g->drawGame(219);
				g->resumeGame(handle_t1);
			}
			else {
				g->resumeGame(handle_t1);
				MOVING = temp;
			}
		}
		else {
			g->pauseGame(handle_t1);
			if (temp == 'Y') {
				g->getPeople().setState(true);
				g->getPeople().setLevel(2);
				g->resize(2);
				g->startGame();
				g->resumeGame(handle_t1);
				if (sound) {
					mciSendString(TEXT("play BACKGROUND.mp3 repeat"), NULL, 0, NULL);
				}
			}
			else {
				g->exitGame(handle_t1);
				break;
			}
		}
	}
	t1.join();
}