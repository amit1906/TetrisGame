#include "PcPlayer.h"
#include "Shape.h"
#include "Bomb.h"

PcPlayer::PcPlayer(const string& _name, const Board& _board, Shape* _shape, int _level)
	: Player(_name, _shape), level((LEVEL)_level), board(_board), shape(_shape) {}

void PcPlayer::makeMove(Board& board, const char keys[])
{
	Bomb* isBomb = dynamic_cast<Bomb*>(shape);
	bool calc = isCalcMove();
	if (!calc || isBomb)
	{
		return;
	}

	int turns = 0;
	int currX = shape->getX() % board.getWidth();
	int goToX = getGoToX(&turns);
	goToX = (currX % 2 == 1) ? goToX : goToX + goToX % 2;

	if (turns > 0)
		shape->turn(1);
	else if (currX < goToX)
		shape->move(2);
	else if (currX > goToX)
		shape->move(-2);
}

bool PcPlayer::isCalcMove() const
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

int PcPlayer::getGoToX(int* turns) const
{
	int toX;
	//toX = checkRowsDeleted(turns);
	//if (toX != -1) return toX;
	toX = checkLowestRow(turns);
	return toX;
}

int PcPlayer::checkRowsDeleted(int* turns) const
{
	int ind = -1, maxDelRows = 0, delRows = 0;
	for (size_t t = 0; t < 3; t++)
	{
		Board b = board;
		Shape s = Shape(shape->getX(), shape->getY(), b, false);

		for (int j = 1; j < board.getWidth() - shape->getShapeL(); j += 2)
		{
			for (int i = 0; i < board.getHeight(); i++)
			{
				if (checkAbove(board, j, i) && shape->checkFall(i, 1))
				{
					delRows = board.checkRows();
					if (delRows > maxDelRows)
					{
						ind = j;
						*turns = t;
					}
					shape->unSetShape();
				}
			}
		}
		shape->turn(1);
	}
	return ind;
}

int PcPlayer::checkLowestRow(int* turns) const
{
	int ind = 1, currY;
	int rowDots, maxDots = 0;
	int delRows, maxDels = 0;
	for (size_t t = 0; t < 4; t++)
	{
		for (int j = 1; j < board.getWidth(); j++)
		{
			Board b = Board(board, true);
			Shape s = Shape(*shape, b);
			rowDots = 0;
			delRows = 0;

			for (size_t k = 1; k <= t; k++)
				s.turn(1, false);

			s.setX(j);
			currY = s.makeFall();
			//printboard(b);

			/*delRows = b.checkRows();
			if (delRows > maxDels)
			{
				maxDels = delRows;
				ind = j;
				*turns = t;
			}*/
			if (maxDels == 0)
			{
				for (int r = 0; r < b.getWidth(); r++)
				{
					if (b.isNotEmpty(r, currY))
						rowDots++;
				}
				if (rowDots > maxDots)
				{
					maxDots = rowDots;
					ind = j;
					*turns = t;
				}
			}
			s.unSetShape();
		}
	}
	return ind;
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

void PcPlayer::printboard(Board b) const
{
	printf("\n");
	for (size_t i = 0; i < b.getHeight(); i++)
	{
		for (size_t j = 1; j < b.getHeight(); j++)
		{
			if (b.isNotEmpty(j, i))
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
}