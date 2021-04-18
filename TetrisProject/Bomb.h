#pragma once
#include "board.h"
#include "shape.h"

constexpr int explodeRad = 3;

class Bomb : public Shape
{

public:
	Bomb(int _x, int _y, const Board& _board, bool colors);

private:
	bool checkFall(int _y = 1, bool toSet = false) override;
	void explode();
	void initShape();
	void makeShapeBomb();


};