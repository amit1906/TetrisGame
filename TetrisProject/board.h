#pragma once
#include "utils.h"
using namespace std;

class Board
{
	struct point
	{
		int set = 0;
		COLOR color = COLOR(15);
	};
	const int pos, height, width;
	point** arrBoard;

public:
	Board(const int _pos, const int _height, const int _width);
	void setShape(int x, int y, COLOR color);
	void print();
	int getHeight();
	int getWidth();
	int getPos();
	bool isNotEmpty(int x, int y);
	bool isFull(int pl);


private:

};