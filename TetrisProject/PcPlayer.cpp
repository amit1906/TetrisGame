#include "PcPlayer.h"
#include "Shape.h"
#include "Bomb.h"

PcPlayer::PcPlayer(const string& _name, Board& _board, Shape* _shape, int _level)
	: Player(_name, _shape), level((LEVEL)_level), board(_board) {}

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
	int goToX = getGoToXAndT(turns);
	goToX = (currX % 2 == 1) ? goToX : goToX + goToX % 2;

	if (turns > 0)
		shape->turn(1);
	else if (currX < goToX)
		shape->move(2);
	else if (currX > goToX)
		shape->move(-2);

	delete isBomb;
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

int PcPlayer::getGoToXAndT(int& turns) const
{
	int ind = 1, currY = 1;
	int maxDots = 0, maxDels = 0;
	bool alyawsEmptyBelow;

	for (size_t t = 0; t < 4; t++)
	{
		alyawsEmptyBelow = hasAlwaysEmptyBelow(t, currY);
		
		for (int j = 1; j < board.getWidth(); j++)
		{
			Board b(board);
			Shape s(*shape, b);
			SetMove(b, s, t, j, currY);

			checkRowsDeleted(b, maxDels, j, t, currY, ind, turns);			// 1'st priority
			if (maxDels == 0)
			{
				if (alyawsEmptyBelow)
					checkLowestRow(b, maxDots, j, t, currY, ind, turns);	// 2'nd priority
				else if (!checkEmptyBelow(b, s))							// 3'rd priority
					checkLowestRow(b, maxDots, j, t, currY, ind, turns);	
			}
			s.unSetShape();
		}
	}
	return ind;
}

void PcPlayer::checkRowsDeleted(const Board& b, int& maxDels, int j, int t, int currY, int& ind, int& turns) const
{
	int delRows = b.checkRows();
	if (delRows > maxDels)
	{
		maxDels = delRows;
		ind = j;
		turns = t;
	}
}

void PcPlayer::checkLowestRow(const Board& b, int& maxDots, int j, int t, int currY, int& ind, int& turns) const
{
	int rowDots = 0;
	for (int r = 0; r < b.getWidth(); r++)
	{
		if (!b.isEmpty(r, currY))
			rowDots++;
	}
	if (rowDots > maxDots)
	{
		maxDots = rowDots;
		ind = j;
		turns = t;
	}
}

bool PcPlayer::hasAlwaysEmptyBelow(int t, int& currY) const
{
	for (int j = 1; j < board.getWidth(); j++)
	{
		Board b(board);
		Shape s(*shape, b);
		SetMove(b, s, t, j, currY);

		if (!checkEmptyBelow(b, s))
			return false;
	}
	return true;
}

bool PcPlayer::checkEmptyBelow(const Board& b, const Shape& s) const
{
	for (size_t i = s.getY() + 1; i <= b.getHeight() && i <= s.getY() + s.getShapeH(); i++)
	{
		for (int j = s.getX(); j < s.getX() + s.getShapeL(); j++)
		{
			if (b.isEmpty(j, i))
				return true;
		}
	}
	return false;
}

void PcPlayer::SetMove(Board& b, Shape& s, int t, int j, int& currY) const
{
	for (size_t k = 1; k <= t; k++)
		s.turn(1, false);

	s.setX(j);
	currY = s.makeFall();
}

void PcPlayer::printboard(Board b) const
{
	printf("\n");
	for (size_t i = 0; i < b.getHeight(); i++)
	{
		for (size_t j = 1; j < b.getHeight(); j++)
		{
			if (!b.isEmpty(j, i))
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
}