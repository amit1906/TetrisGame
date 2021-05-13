#pragma once
#include "Board.h"
#include "Shape.h"

constexpr int explodeRad = 4;

class Bomb : public Shape
{

public:
	Bomb(int _x, int _y, Board& _board, bool colors);

private:
	bool checkFall(int _y = 1, bool toSet = false) override;
	void explode();
	void BurnBlocks(int from, int to, char ch, bool toUnSet);
	void initShape();
	void makeShapeBomb();


};