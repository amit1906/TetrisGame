#pragma once
#include "utils.h"

class Score
{
	string name;
	int score;

public:
	Score(const string& _name);
	void printPlayer(int pos, int height);
	string getName();
	void setName(string _name);
	void increaseScore();

private:
	void printScore(int pos, int height);

};