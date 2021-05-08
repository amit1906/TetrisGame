#pragma once
#include "Player.h"
#include "Board.h"

class PcPlayer : public Player
{
	enum LEVEL { BEST = 1, GOOD, NOVICE };
	LEVEL level;

public:
	PcPlayer(const string& _name, Shape* const _shape, int _level);
	void makeMove(Board& board, const char keys[]) override;

private:
	int getGoToX(const Board& board) const;
	bool checkAbove(const Board& board, int x, int y) const;
	bool calcMove() const;

};