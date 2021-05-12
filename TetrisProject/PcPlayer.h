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
	int getGoToX(int* turns) const;
	int checkRowsDeleted(int* turns) const;
	int checkLowestRow(int* turns) const;
	bool checkAbove(const Board& board, int x, int y) const;
	bool isCalcMove() const;
	void printboard(Board b) const;

};