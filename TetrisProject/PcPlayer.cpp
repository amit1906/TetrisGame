#include "PcPlayer.h"
#include "Shape.h"

PcPlayer::PcPlayer(const string& _name, Shape* const _shape, int _level)
	: Player(_name, _shape), level((LEVEL)_level) {}

void PcPlayer::makeMove(Board& board, const char keys[])
{
	bool calc = calcMove();
	if (!calc)
		return;

	int currX = shape->getX() % board.getWidth();
	int goToX = getGoToX(board);
	goToX = (currX % 2 == 1) ? goToX : goToX + goToX % 2;

	if (currX < goToX)
		shape->move(2);
	else if (currX > goToX)
		shape->move(-2);
}

bool PcPlayer::calcMove() const
{
	switch (level)
	{
	case BEST:
		return true;
		break;
	case GOOD:
		if (rand() % 40 == 1)
			return false;
		return true;
		break;
	case NOVICE:
		if (rand() % 10 == 1)
			return false;
		return true;
		break;
	}
}

int PcPlayer::getGoToX(const Board& board) const
{
	for (int i = board.getHeight(); i >= 0; i--)
	{
		for (int j = 1; j < board.getWidth() - shape->getShapeL(); j += 2)
		{
			if (!board.isNotEmpty(j, i) && checkAbove(board, j, i))
				return j;
		}
	}
	return 0;
}

bool PcPlayer::checkAbove(const Board& board, int x, int y) const
{
	for (int i = y; i >= 0; i--)
	{
		if (board.isNotEmpty(x, i))
			return false;
	}
	return true;
}