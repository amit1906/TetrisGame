#pragma once
#include "utils.h"
#include "score.h"

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
	void printFrame();
	void printContent(bool clean = false);
	int getHeight();
	int getWidth();
	int getPos();
	bool isNotEmpty(int x, int y);
	void checkRows(Score& score);
	bool isFull(Score pl, Score score1, Score score2);

private:
	void deleteRow(int row);

};