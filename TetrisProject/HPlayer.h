#pragma once
#include "Player.h"

constexpr int NUM_KEYS = 5;

class HPlayer : public Player
{
	// left, right, rotate left, rotate right, drop
	char playerKeys[NUM_KEYS];

public:
	HPlayer(const string& _name, Shape* const _shape, const char playerKeys[]);
	void makeMove(Board& board, const char keys[]) override;

private:


};