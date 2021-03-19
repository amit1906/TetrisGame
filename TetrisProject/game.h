#pragma once
#include "utils.h"
#include "board.h"
#include "shape.h"
#include "score.h"
using namespace std;

const int constexpr ESC = 27;
const enum  PL1 { LEFT1 = 'a', RIGHT1 = 'd', ROTATER1 = 's', ROTATEL1 = 'w', DROP1 = 'x' };
const enum  PL2 { LEFT2='j', RIGHT2='l', ROTATER2 = 'k', ROTATEL2 = 'i', DROP2 = 'm'};

class Game
{
	int speed = 300;
	const int pos = 2, height = 20, width = 37;
	Board board1 = Board(pos, height, width);
	Board board2 = Board(pos + width, height, width);
	Shape* shape1, * shape2;
	int shapeX, shapeY = -1;
	int maxX = 8;
	bool toEnd = false;
	bool colors;

public:
	Game();
	void menu();
	void startGame();

private:
	void gameLoop();
	void checkKeys();
	void drawGame();
	void checkEnd();
	void checkShapes();
	void menuInfo();
	void instructionsInfo();

};