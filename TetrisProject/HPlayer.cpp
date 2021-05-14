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
			shape->move(Shape::LEFT);
		if (playerKeys[1] == keys[i])	// RIGHT
			shape->move(Shape::RIGHT);
		if (playerKeys[2] == keys[i])	// ROTATE LEFT
			shape->turn(Shape::TURN_LEFT);
		if (playerKeys[3] == keys[i])	// ROTATE RIGHT
			shape->turn(Shape::TURN_RIGHT);
		if (playerKeys[4] == keys[i])	// DROP
			shape->move(Shape::DROP);
	}
}