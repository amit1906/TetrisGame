#pragma once
#include "utils.h"

class Player
{
	string name;
	int score;

public:
	Player(const string& _name);
	void printPlayerStats(int pos, int height);
	string getName()	const;
	int getScore()	const;
	void setName(string _name);
	void increaseScore();

private:
	void printScore(int pos, int height);

};