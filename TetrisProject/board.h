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
	int pos, height, width;
	point** arrBoard;

public:
	Board(const int _pos, const int _height, const int _width);
	Board& operator=(const Board& board) = delete;
	Board(const Board& copy);
	~Board();
	void setShape(int x, int y, COLOR color, int toSet = 1);
	void unSetShape(int x, int y);
	void SetBoard(const Board& b);
	void printFrame() const;
	void printContent(bool clean = false) const;
	int getHeight() const;
	int getWidth() const;
	int getPos() const;
	bool isEmpty(int x, int y) const;
	bool isFull(Player& player) const;
	int checkRows() const;
	void checkRows(Player& player);
	void fixBoard(int from, int to);

private:
	void deleteRow(int row);
	void SetShape(int x, int y, int set, COLOR color);

};