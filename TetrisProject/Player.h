#pragma once
#include "Utils.h"

class Board;
class Shape;
const enum  MOVE { LEFT = 'a', RIGHT = 'd', ROTATEL = 's', ROTATER = 'w', DROP = 'x' };

class Player
{
	string name;
	int score;

protected:
	Shape *shape;

public:
	Player(const string& _name, Shape* const _shape);
	//virtual ~Player();
	void printPlayerStats(int pos, int height);
	string getName()	const;
	int getScore()	const;
	void setShape(Shape* _shape) { shape = _shape; }
	void setName(string _name);
	void increaseScore();

	virtual void makeMove(Board& board, const char keys[]) {};	// = 0

private:
	void printScore(int pos, int height);

};