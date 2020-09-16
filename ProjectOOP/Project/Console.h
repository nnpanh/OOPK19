#pragma onces
#pragma warning(disable : 4996)
#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <random>
#include <conio.h>
using namespace std;

const int WIDTH = 90;
const int HEIGHT = 25;

struct Point
{
	int m_x, m_y;
	char data;
};

//void clrscr();

//void draw_ambulance();

//lock ratio
void fixConsoleWindow();

//go to the coordinate (x,y) on the screen
void gotoXY(int, int);

//draw the playground
void drawBoard(int, int, int, int, int, int);

//set color
void setColor(WORD);

//draw the box
void drawBox(int, int, int, int, int, int);

//Animation when dead
void animation(int, int, int, int, int, int);

//load animation
void loading(int, int, int, int, int, int);

//Make the cursor disappear
void ShowConsoleCursor(bool showFlag);
#endif