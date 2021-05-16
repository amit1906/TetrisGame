#pragma once
#include <memory>

#include "Utils.h"
#include "Board.h"
#include "Shape.h"
#include "Bomb.h"
#include "Player.h"
#include "HPlayer.h"
#include "PcPlayer.h"

const int constexpr ESC = 27;								// game enums
const int constexpr LEN = 5;
const int constexpr NUM_PLAYERS = 2;
const enum  GAME_TYPE { HVH, HVC, CVC };
const enum  PL1 { LEFT1 = 'a', RIGHT1 = 'd', ROTATEL1 = 's', ROTATER1 = 'w', DROP1 = 'x' };
const enum  PL2 { LEFT2 = 'j', RIGHT2 = 'l', ROTATEL2 = 'k', ROTATER2 = 'i', DROP2 = 'm' };

class Game
{
	int speed, level;										// game varaiables
	bool colors, paused, finished;
	const char player1Keys[LEN] = { LEFT1, RIGHT1, ROTATEL1, ROTATER1, DROP1 };
	const char player2Keys[LEN] = { LEFT2, RIGHT2, ROTATEL2, ROTATER2, DROP2 };
	char keys[LEN];

	const static int pos = 2, height = 18, width = 23;		// boards varaiables
	int shapeX = 1, shapeY = 0;								// shapes varaiables

	Player* players[NUM_PLAYERS];							// game arrays
	std::unique_ptr<Shape> shapes[NUM_PLAYERS];
	Board boards[NUM_PLAYERS]{ { pos, height, width } ,{ pos + width, height, width } };

public:
	Game(GAME_TYPE gameType, int _speed, bool _colors, const string names[], int level = 1);
	~Game();
	void changeSettings(int _speed, bool _colors, const string names[]);
	void start();
	bool HasFinished();
	static int getRandomShapeX(int boardInd);

private:
	void chooseGameType(GAME_TYPE gameType, const string names[], int level);
	void gameLoop();
	void movePlayers();
	void checkKeys();
	void drawBoards();
	void drawGame();
	void checkRows();
	void checkEnd();
	void checkShapes();
	void printWinner(Player player1, Player player2, int winner);

};