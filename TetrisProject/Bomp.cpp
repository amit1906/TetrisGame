#include "Bomb.h"

Bomb::Bomb(int _x, int _y, Board& _board, bool colors)
	:Shape(_x, _y, _board, colors)
{
	initShape();
	makeShapeBomb();
}

Bomb::Bomb(const Shape& bomb, Board& _board) 
	:Shape(bomb, _board) 
{
	initShape();
	makeShapeBomb();
}

bool Bomb::checkFall(int _y, bool toSet)
{
	bool fell = Shape::checkFall(_y, false);
	if (fell && toSet)
		explode();
	return fell;
}

int Bomb::explodeDotsCount()
{
	int from, to;
	setArea(from, to);
	return BurnBlocks(from, to, 0, true);
}

void Bomb::explode()
{
	int from, to;
	setTextColor(RED);
	setArea(from, to);
	BurnBlocks(from, to, (char)219, false);
	Sleep(400);
	BurnBlocks(from, to, ' ', true);
	board.fixBoard(from, to);
}

int Bomb::BurnBlocks(int from, int to, char ch, bool toUnSet)
{
	int dotsBurned = 0;
	for (size_t i = from; i < to; i++)
	{
		for (size_t j = max(1, y - EXPLODE_RADIUS); j <= min(board.getHeight(), y + EXPLODE_RADIUS - 1); j++)
		{
			if (ch != 0)
			{
				gotoxy(i + board.getPos(), j);
				cout << ch;
			}
			if (toUnSet && !board.isEmpty(i, j))
			{
				board.unSetShape(i, j);
				dotsBurned++;
			}
		}
	}
	return dotsBurned;
}

void Bomb::setArea(int& from, int& to)
{
	from = max(1, x % board.getWidth() - EXPLODE_RADIUS * 2 + 1);
	to = min(board.getWidth(), x % board.getWidth() + EXPLODE_RADIUS * 2);
	from = (from % 2 == 1) ? from : from + 1;
	to = (to % 2 == 1) ? to : to - 1;
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