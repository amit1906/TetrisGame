#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

enum COLOR
{
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHTGREY = 7,
	DARKGREY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};

void gotoxy(int x, int y);
void clearScreen();
void setTextColor(COLOR colorToSet);
void hideCursor();