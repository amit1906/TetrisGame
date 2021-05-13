#pragma once
#include "Player.h"
#include "Board.h"

class PcPlayer : public Player
{
	enum LEVEL { BEST = 1, GOOD, NOVICE };
	LEVEL level;
	Board board;
	Shape *shape;

public:
	PcPlayer(const string& _name, const Board& _board, Shape *_shape, int _level);
	void makeMove(Board& board, const char keys[]) override;

private:
	int getGoToXAndT(int& turns) const;
	void checkRowsDeleted(const Board& b, int& maxDots, int j, int t, int currY, int& ind, int& turns) const;
	void checkLowestRow(const Board& b, int& maxDots, int j, int t, int currY, int& ind, int& turns) const;
	bool checkEmptyBelow(const Board& b, const Shape& s) const;
	bool isCalcMove() const;
	void printboard(Board b) const;

};