#pragma once
#include "game.h"

class Menu
{
	Game* game = nullptr;
	int speed = 300;
	bool colors = true;
	string name1 = "player1";
	string name2 = "player2";

public:
	Menu() = default;
	~Menu();
	void Start();

private:
	void menuInfo();
	void initGame();
	void continueGame();
	void changeColors();
	void changeSpeed();
	void changeNames();
	void instructionsInfo();

};
