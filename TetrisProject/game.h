#pragma once
#include <memory>

#include "Utils.h"
#include "Board.h"
#include "Shape.h"
#include "Bomb.h"
#include "Player.h"
#include "HPlayer.h"
#include "PcPlayer.h"

const int constexpr ESC = 27;
const int constexpr LEN = 5;
const enum  GAME_TYPE { HVH, HVC, CVC };
const enum  PL1 { LEFT1 = 'a', RIGHT1 = 'd', ROTATEL1 = 's', ROTATER1 = 'w', DROP1 = 'x' };
const enum  PL2 { LEFT2 = 'j', RIGHT2 = 'l', ROTATEL2 = 'k', ROTATER2 = 'i', DROP2 = 'm' };

class Game
{
	int level;
	int speed;
	bool colors, paused, finished;
	Player* player1, * player2;
	const char player1Keys[LEN] = { 'a','d','s','w','x' };
	const char player2Keys[LEN] = { 'j','l','k','i','m' };
	char keys[LEN];

	const int pos = 2, height = 18, width = 23;
	Board board1{ pos, height, width };
	Board board2{ pos + width, height, width };
	std::unique_ptr<Shape> shape1, shape2;
	int shapeX = 1, shapeY = 0;
	int maxX = 10;

public:
	Game(GAME_TYPE gameType, int _speed, bool _colors, string name1, string name2, int level = 1);
	~Game();
	void changeSettings(int _speed, bool _colors, string name1, string name2);
	void start();
	bool HasFinished();

private:
	void chooseGameType(GAME_TYPE gameType, string name1, string name2, int level);
	void gameLoop();
	void movePlayers();
	void checkKeys();
	void drawBoard();
	void drawGame();
	void checkRows();
	void checkEnd();
	void checkShapes();
	void printWinner(Player player1, Player player2, int winner);

};