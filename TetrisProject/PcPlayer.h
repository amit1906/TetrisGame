#pragma once
#include "Player.h"
#include "Board.h"

class PcPlayer : public Player
{

public:
	PcPlayer(const string& _name, Shape* const _shape, int level);
	void makeMove(Board& board, const char keys[]) override;


private:
	int getGoToX(const Board& board) const;
	bool checkAbove(const Board& board, int x, int y) const;


};