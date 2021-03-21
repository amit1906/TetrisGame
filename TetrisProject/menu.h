#pragma once
#include "game.h"
using namespace std;

class Menu
{
	Game* game = NULL;
	int speed = 300;
	bool colors = true;
	string name1 = "player1";
	string name2 = "player2";

public:
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
