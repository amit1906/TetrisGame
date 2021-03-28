#include "Bomb.h"


Bomb::Bomb(Board& _board, int _x, int _y) : board(_board)
{
	x = rand() % board.getWidth() + board.getPos();
	y = 0;
}