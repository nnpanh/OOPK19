#pragma once
#ifndef _CGAME_H_
#define _CGAME_H_

#include <iostream>
#include <conio.h>
#include <Windows.h> // Main of the board
#include <time.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include <fstream>
#include <malloc.h>
#include "CVEHICLE.h"
#include "Console.h"
#include "CPEOPLE.h"

int HEIGHT_CONSOLE = 25, WIDTH_CONSOLE = 70;
using namespace std;

HANDLE consolehandle = GetStdHandle(STD_OUTPUT_HANDLE);


class CGAME {
	vector<CTRUCK> truck;
	vector<CCAR> car;
	/*vector<CDINAUSOR> dinausor;*/
	/*vector<CBIRD> bird;*/
	CPEOPLE people;
public:
	CGAME(); //Chuẩn bị dữ liệu cho tất cả các đối tượng
	void DrawBoardGame(int x, int y, int width, int height); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	void drawGame(char); //ve nguoi xe thu
	//~CGAME(); // Hủy tài nguyên đã cấp phát
	CPEOPLE& getPeople();
	vector <CTRUCK>& getTruck();
	vector <CCAR>& getCar();
	//vector <CDinausor>& getDinausor();
	//vector <CBird>& getBird();

	//void resetGame(); // havent done 

	void exitGame(HANDLE); // Thực hiện thoát Thread
	void startGame(); // Thực hiện bắt đầu vào trò chơi
	////void loadGame(istream); // Thực hiện tải lại trò chơi đã lưu
	////void saveGame(istream); // Thực hiện lưu lại dữ liệu trò chơi

	void pauseGame(HANDLE); // Tạm dừng Thread
	void resumeGame(HANDLE); //Quay lai Thread
	//void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
	//void updatePosVehicle(); //Thực hiện cho CTRUCK & CCAR di chuyển
	//void updatePosAnimal();//Thực hiện cho CDINAUSOR & CBIRD di chuyển
};
#endif