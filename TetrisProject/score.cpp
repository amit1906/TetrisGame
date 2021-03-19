#include "score.h"

Score::Score(const string& _name) :name(_name) {}

void Score::printPlayer(int pos, int height)
{
	gotoxy(pos + 2, height + 2);
	cout << name;
	printScore(pos, height);
}

void Score::printScore(int pos, int height)
{
	gotoxy(pos + 2, height + 3);
	cout << "score: " << score;
}

string Score::getName()
{
	return name;
}

void Score::setName(string _name)
{
	name = _name;
}

void Score::increaseScore()
{
	score++;
}