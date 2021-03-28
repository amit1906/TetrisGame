#include "Player.h"

Player::Player(const string& _name) :name(_name), score(0) {}

void Player::printPlayerStats(int pos, int height)
{
	gotoxy(pos + 2, height + 2);
	cout << name;
	printScore(pos, height);
}

void Player::printScore(int pos, int height)
{
	gotoxy(pos + 2, height + 3);
	cout << "score: " << score;
}

string Player::getName() const
{
	return name;
}

int Player::getScore() const
{
	return score;
}

void Player::setName(string _name)
{
	name = _name;
}

void Player::increaseScore()
{
	score++;
}