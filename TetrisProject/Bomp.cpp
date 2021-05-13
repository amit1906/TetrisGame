#include "Bomb.h"

Bomb::Bomb(int _x, int _y, Board& _board, bool colors)
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
	int from = max(1, x % board.getWidth() - explodeRad * 2 + 1);
	int to = min(board.getWidth(), x % board.getWidth() + explodeRad * 2);
	from = (from % 2 == 1) ? from : from + 1;
	to = (to % 2 == 1) ? to : to - 1;
	BurnBlocks(from, to, (char)219, false);
	Sleep(500);
	BurnBlocks(from, to, ' ', true);
}

void Bomb::BurnBlocks(int from, int to, char ch, bool toUnSet)
{
	for (size_t i = from; i < to; i++)
	{
		for (size_t j = max(1, y - explodeRad); j <= min(board.getHeight(), y + explodeRad - 1); j++)
		{
			gotoxy(i + board.getPos(), j);
			cout << ch;
			if (toUnSet)
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