#pragma once
#include "Game.h"
#include <time.h>

class Menu
{
	const int MIN_SPEED = 1, MAX_SPEED = 1000;
	Game* game = nullptr;
	bool colors = true;
	int speed = 300;
	string names[NUM_PLAYERS]{ "player1" ,"player2" };

public:
	Menu() = default;
	Menu& operator=(const Menu& menu) = delete;
	Menu(const Menu& menu) = delete;
	~Menu();
	void Start();

private:
	void menuInfo();
	int levelInfo();
	void initGame();
	void freeGame();
	void continueGame();
	void changeColors();
	void changeSpeed();
	void changeNames();
	void instructionsInfo();

};
