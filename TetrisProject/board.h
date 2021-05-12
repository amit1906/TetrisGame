#pragma once
#include "Utils.h"
#include "Player.h"

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
	Board(const Board& copy, bool toCopy);
	//~Board();
	void setShape(int x, int y, COLOR color, int toSet = 1);
	void unSetShape(int x, int y);
	void SetBoard(const Board& b);
	void printFrame() const;
	void printContent(bool clean = false) const;
	int getHeight() const;
	int getWidth() const;
	int getPos() const;
	bool isNotEmpty(int x, int y) const;
	void checkRows(Player& player);
	int checkRows() const;
	bool isFull(Player player) const;

private:
	void deleteRow(int row);

};