#pragma once
#include "Game.h"
#include <time.h>

class Menu
{
	Game* game = nullptr;
	int speed = 200;
	bool colors = true;
	string name1 = "player1";
	string name2 = "player2";

public:
	Menu() = default;
	~Menu();
	void Start();

private:
	void menuInfo();
	int levelInfo();
	void initGame();
	void continueGame();
	void changeColors();
	void changeSpeed();
	void changeNames();
	void instructionsInfo();

};
