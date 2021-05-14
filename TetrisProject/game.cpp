#include "Game.h"

Game::Game(GAME_TYPE gameType, int _speed, bool _colors, const string names[], int level)
	:speed(_speed), colors(_colors)
{
	paused = finished = false;
	for (size_t i = 0; i < NUM_PLAYERS; i++)
	{
		shapeX = rand() % (width - maxX) + pos;
		shapeX += i * width;
		shapeX -= shapeX % 2 - 1;
		shapes[i] = std::make_unique<Shape>(shapeX, shapeY, boards[i], colors);
	}
	chooseGameType(gameType, names, level);
}

Game::~Game()	// shapes are unique_ptr doesnt need to be freed...
{
	for (Player* player : players)
	{
		delete player;
		player = nullptr;
	}
}

void Game::changeSettings(int _speed, bool _colors, const string names[])
{
	speed = _speed;
	colors = _colors;
	for (size_t i = 0; i < NUM_PLAYERS; i++)
	{
		players[i]->setName(names[i]);
	}
}

void Game::chooseGameType(GAME_TYPE gameType, const string names[], int level)
{
	switch (gameType)
	{
	case  HVH:
		players[0] = new HPlayer(names[0], shapes[0].get(), player1Keys);
		players[1] = new HPlayer(names[1], shapes[1].get(), player2Keys);
		break;
	case  HVC:
		players[0] = new HPlayer(names[0], shapes[0].get(), player1Keys);
		players[1] = new PcPlayer(names[1], boards[1], shapes[1].get(), level);
		break;
	case  CVC:
		players[0] = new PcPlayer(names[0], boards[0], shapes[0].get(), level);
		players[1] = new PcPlayer(names[1], boards[1], shapes[1].get(), level);
		break;
	}
}

void Game::start()
{
	clearScreen();
	drawBoards();
	gameLoop();
	clearScreen();
	paused = false;
}

void Game::gameLoop()
{
	while (!paused && !finished)
	{
		checkShapes();
		checkKeys();
		movePlayers();
		drawGame();
		checkRows();
		checkEnd();
	}
}

void Game::movePlayers()
{
	for (size_t i = 0; i < NUM_PLAYERS; i++)
	{
		players[i]->makeMove(boards[i], keys);
	}
}

void Game::drawBoards()
{
	for (Board board : boards)
	{
		board.printFrame();
		board.printContent();
	}
}

void Game::drawGame()
{
	for (size_t i = 0; i < NUM_PLAYERS; i++)
	{
		shapes[i]->move();
		players[i]->printPlayerStats(boards[i].getPos(), boards[i].getHeight());
	}
	drawBoards();
	hideCursor();
	Sleep(speed);
}

void Game::checkShapes()
{
	int bombAppears[NUM_PLAYERS] = { (rand() % 20 == 1) ? 1 : 0, (rand() % 20 == 1) ? 1 : 0 };
	for (size_t i = 0; i < NUM_PLAYERS; i++)
	{
		if (shapes[i]->checkFall())
		{
			shapeX = rand() % (width - maxX) + pos;
			shapeX += i * width;
			shapeX -= shapeX % 2 - 1;
			if (bombAppears[i] == 1)
				shapes[i] = std::make_unique<Bomb>(shapeX, shapeY, boards[i], colors);
			else
				shapes[i] = std::make_unique<Shape>(shapeX, shapeY, boards[i], colors);

			players[i]->setShape(shapes[i].get());
			players[i]->increaseScore(1);
		}
	}
}

void Game::checkKeys()
{
	int keysItr = 20;
	for (size_t i = 0; i < LEN; i++)
		keys[i] = ' ';

	for (size_t i = 0; i < keysItr; i++)
	{
		if (_kbhit())
		{
			keys[0] = _getch();
			if (keys[0] >= 'A' && keys[0] <= 'Z')
				keys[0] += 'a' - 'A';
			switch (keys[0])
			{
			case PL1::LEFT1:	keys[1] = PL1::LEFT1;
				break;
			case PL1::RIGHT1:	keys[1] = PL1::RIGHT1;
				break;
			case PL1::ROTATER1:	keys[3] = PL1::ROTATER1;
				break;
			case PL1::ROTATEL1:	keys[3] = PL1::ROTATEL1;
				break;
			case PL1::DROP1:	keys[1] = PL1::DROP1;
				break;
			case PL2::LEFT2:	keys[2] = PL2::LEFT2;
				break;
			case PL2::RIGHT2:	keys[2] = PL2::RIGHT2;
				break;
			case PL2::ROTATER2:	keys[4] = PL2::ROTATER2;
				break;
			case PL2::ROTATEL2:	keys[4] = PL2::ROTATEL2;
				break;
			case PL2::DROP2:	keys[2] = PL2::DROP2;
				break;
			case ESC:			paused = true;
				break;
			}
		}
	}
}

void Game::checkRows()
{
	for (size_t i = 0; i < NUM_PLAYERS; i++)
	{
		boards[i].checkRows(*players[i]);
	}
}

void Game::checkEnd()
{
	bool pl1Won = boards[1].isFull(*players[0]);
	bool pl2Won = boards[0].isFull(*players[1]);

	if (pl1Won && pl2Won)
	{
		if (players[0]->getScore() >= players[1]->getScore())
			printWinner(*players[0], *players[1], 1);
		else
			printWinner(*players[0], *players[1], 2);
		finished = true;
	}
	else if (pl1Won)
	{
		printWinner(*players[0], *players[1], 1);
		finished = true;
	}
	else if (pl2Won)
	{
		printWinner(*players[0], *players[1], 2);
		finished = true;
	}
	if (pl1Won || pl2Won)
		while (!(_kbhit() && _getch() == ESC));
}

void Game::printWinner(Player player1, Player player2, int winner)
{
	string winnerName;
	winnerName = (winner == 1) ? player1.getName() : player2.getName();
	clearScreen();
	gotoxy(width / 4, height / 6);
	cout << "GAME OVER" << endl << endl;
	gotoxy(width / 4 - 1, height / 6 + 1);
	cout << winnerName << " won!" << endl << endl << endl;
	cout << "press Escape to continue...";
	player1.printPlayerStats(1, 8);
	player2.printPlayerStats(15, 8);
}

bool Game::HasFinished()
{
	return finished;
}