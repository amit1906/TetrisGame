#pragma once
#include "Player.h"
#include "Board.h"

class PcPlayer : public Player
{

public:
	PcPlayer(const string& _name, Shape* const _shape);
	void makeMove(Board& board, const char keys[]) override;


private:
	int getGoToX();


};