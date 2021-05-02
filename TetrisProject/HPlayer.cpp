#include "HPlayer.h"
#include "Shape.h"

HPlayer::HPlayer(const string& _name, Shape* const _shape, const char _playerKeys[])
	: Player(_name, _shape)
{
	for (int i = 0; i < NUM_KEYS; i++)
	{
		playerKeys[i] = _playerKeys[i];
	}
}

void HPlayer::makeMove(Board& board, const char keys[])
{
	for (size_t i = 1; i < NUM_KEYS; i++)
	{
		if (playerKeys[0] == keys[i])	// LEFT
			shape->move(-2);
		if (playerKeys[1] == keys[i])	// RIGHT
			shape->move(2);
		if (playerKeys[2] == keys[i])	// ROTATEL
			shape->turn(-1);
		if (playerKeys[3] == keys[i])	// ROTATER
			shape->turn(1);
		if (playerKeys[4] == keys[i])	// DROP
			shape->move(0, 3);
	}
}