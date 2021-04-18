#pragma once
#include "board.h"




class Bomb
{
	int x, y=0;
	Board board;
public:
	Bomb(Board& _board,int _x=0,int _y=0);
	void move();
	void checkFall();
private:
	void explode();
};


