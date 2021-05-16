#pragma once
#include "Board.h"
#include "Shape.h"

constexpr int EXPLODE_RADIUS = 4;

class Bomb : public Shape
{

public:
	Bomb(int _x, int _y, Board& _board, bool colors);
	Bomb(const Shape& bomb, Board& _board);
	bool checkFall(int _y = 1, bool toSet = true) override;
	int explodeDotsCount();

private:
	void explode();
	int BurnBlocks(int from, int to, char ch, bool toUnSet);
	void initShape();
	void makeShapeBomb();
	void setArea(int& from, int& to);


};