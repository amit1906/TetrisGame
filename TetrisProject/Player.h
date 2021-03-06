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
	Shape* shape;

public:
	Player(const string& _name, Shape* const _shape);
	Player& operator=(const Player& player) = delete;
	Player(const Player& player) = delete;
	virtual ~Player();
	void printPlayerStats(int pos, int height);
	string getName()	const;
	int getScore()	const;
	void setShape(Shape* _shape) { shape = _shape; }
	void setName(string _name);
	void increaseScore(int inc);
	virtual void makeMove(Board& board, const char keys[]) {};

private:
	void printScore(int pos, int height);

};