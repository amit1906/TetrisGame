#pragma once
#include "utils.h"
#include "board.h"
#include "shape.h"
#include "score.h"
using namespace std;

const int constexpr ESC = 27;
const enum  PL1 { LEFT1 = 'a', RIGHT1 = 'd', ROTATEL1 = 's', ROTATER1 = 'w', DROP1 = 'x' };
const enum  PL2 { LEFT2 = 'j', RIGHT2 = 'l', ROTATEL2 = 'k', ROTATER2 = 'i', DROP2 = 'm' };

class Game
{
	int speed;
	bool colors;
	Score score1, score2;

	const int pos = 2, height = 18, width = 23;
	Board board1 = Board(pos, height, width);
	Board board2 = Board(pos + width, height, width);
	Shape* shape1, * shape2;
	int shapeX, shapeY = -1;
	int maxX = 8;
	bool toEnd = false;

public:
	Game(int _speed, bool _colors, string name1, string name2);
	void changeSettings(int _speed, bool _colors, string name1, string name2);
	void start();

private:
	void gameLoop();
	void checkKeys();
	void drawBoard();
	void drawGame();
	void checkRows();
	void checkEnd();
	void checkShapes();

};