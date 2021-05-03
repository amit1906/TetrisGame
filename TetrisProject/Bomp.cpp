#include "Bomb.h"

Bomb::Bomb(int _x, int _y, const Board& _board, bool colors) 
	:Shape(_x, _y, _board, colors)
{
	initShape();
	makeShapeBomb();
}

bool Bomb::checkFall(int _y, bool toSet)
{
	bool fell = Shape::checkFall(_y, false);
	if (fell)
		explode();
	return fell;
}

void Bomb::explode()
{
	setTextColor(RED);
	for (size_t i = max(1, x % board.getWidth() - explodeRad * 2 +1); i < min(board.getWidth(), x % board.getWidth() + (explodeRad + 1) * 2 ); i++)
	{
		for (size_t j = max(1, y - explodeRad); j <= min(board.getHeight(), y + explodeRad); j++)
		{
			gotoxy(i + board.getPos(), j);
			cout << (char)219;
		}
	}
	Sleep(500);
	for (size_t i = max(1, x % board.getWidth() - explodeRad * 2 + 1); i < min(board.getWidth(), x % board.getWidth() + (explodeRad + 1) * 2); i++)
	{
		for (size_t j = max(1, y - explodeRad); j <= min(board.getHeight(), y + explodeRad); j++)
		{
			gotoxy(i + board.getPos(), j);
			cout << ' ';
			board.unSetShape(i % board.getWidth(), j);
		}
	}
}

void Bomb::makeShapeBomb()
{
	arrShape[0][0] = 1;
	arrShape[1][0] = 1;
	shapeL = 2;
	shapeH = 1;
}

void Bomb::initShape()
{
	for (size_t i = 0; i < maxBlock; i++)
		for (size_t j = 0; j < maxBlock; j++)
			arrShape[i][j] = 0;
}