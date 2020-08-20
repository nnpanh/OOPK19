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
int HEIGHT_CONSOLE = 25, WIDTH_CONSOLE = 70;
using namespace std;

HANDLE consolehandle = GetStdHandle(STD_OUTPUT_HANDLE);


class CGAME {
	//CTRUCK* axt;
	//CCAR* axh;
	//CDINAUSOR* akl;
	//CBIRD* ac;
	//CPEOPLE cn;
public:
	//CGAME(); //Chuẩn bị dữ liệu cho tất cả các đối tượng
	void drawGame(int x, int y, int width, int height); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	//~CGAME(); // Hủy tài nguyên đã cấp phát
	//CPEOPLE getPeople();//Lấy thông tin người
	//CVEHICLE* getVehicle();//Lấy danh sách các xe
	//CANIMAL* getAnimal(); //Lấy danh sách các thú
	//void resetGame(); // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	//void exitGame(HANDLE); // Thực hiện thoát Thread
	////void startGame(); // Thực hiện bắt đầu vào trò chơi
	////void loadGame(istream); // Thực hiện tải lại trò chơi đã lưu
	////void saveGame(istream); // Thực hiện lưu lại dữ liệu trò chơi

	void pauseGame(HANDLE t); // Tạm dừng Thread
	//void resumeGame(HANDLE); //Quay lai Thread
	//void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
	//void updatePosVehicle(); //Thực hiện cho CTRUCK & CCAR di chuyển
	//void updatePosAnimal();//Thực hiện cho CDINAUSOR & CBIRD di chuyển
};
#endif