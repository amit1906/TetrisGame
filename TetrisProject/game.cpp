#include "Game.h"

Game::Game(GAME_TYPE gameType, int _speed, bool _colors, string name1, string name2, int level)
	:speed(_speed), colors(_colors)
{
	paused = finished = false;
	shapeX = rand() % (width - maxX) + pos;
	shapeX -= shapeX % 2 - 1;
	shape1 = std::make_unique<Shape>(shapeX, shapeY, board1, colors);
	shapeX = rand() % (width - maxX) + width + pos;
	shapeX -= shapeX % 2;
	shape2 = std::make_unique<Shape>(shapeX, shapeY, board2, colors);
	chooseGameType(gameType, name1, name2, level);
}

Game::~Game()
{
	//delete shape1;		// because of use of unique_ptr
	//delete shape2;
	//shape1 = shape2 = nullptr;
	delete player1;
	delete player2;
	player1 = player2 = nullptr;
}

void Game::changeSettings(int _speed, bool _colors, string name1, string name2)
{
	speed = _speed;
	colors = _colors;
	player1->setName(name1);
	player2->setName(name2);
}

void Game::chooseGameType(GAME_TYPE gameType, string name1, string name2, int level)
{
	switch (gameType)
	{
	case  HVH:
		player1 = new HPlayer(name1, shape1.get(), player1Keys);
		player2 = new HPlayer(name2, shape2.get(), player2Keys);
		break;
	case  HVC:
		player1 = new HPlayer(name1, shape1.get(), player1Keys);
		player2 = new PcPlayer(name2, board2, shape2.get(), level);
		break;
	case  CVC:
		player1 = new PcPlayer(name2, board1, shape1.get(), level);
		player2 = new PcPlayer(name2, board2, shape2.get(), level);
		break;
	}
}

void Game::start()
{
	clearScreen();
	drawBoard();
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
	player1->makeMove(board1, keys);
	player2->makeMove(board2, keys);
}

void Game::drawBoard()
{
	board1.printFrame();
	board2.printFrame();
	board1.printContent();
	board2.printContent();
}

void Game::drawGame()
{
	shape1->move();
	shape2->move();
	drawBoard();
	player1->printPlayerStats(board1.getPos(), board1.getHeight());
	player2->printPlayerStats(board2.getPos(), board1.getHeight());
	hideCursor();
	Sleep(speed);
}

void Game::checkShapes()
{
	int bombAppear1 = (rand() % 20 == 1) ? 1 : 0;
	int bombAppear2 = (rand() % 20 == 1) ? 1 : 0;
	if (shape1->checkFall())
	{
		//delete shape1;
		shapeX = rand() % (width - maxX) + pos;
		shapeX -= shapeX % 2 - 1;
		if (bombAppear1 == 1)
			shape1 = std::make_unique<Bomb>(shapeX, shapeY, board1, colors);
		else
			shape1 = std::make_unique<Shape>(shapeX, shapeY, board1, colors);

		player1->setShape(shape1.get());
	}
	if (shape2->checkFall())
	{
		//delete shape2;
		shapeX = rand() % (width - maxX) + width + pos;
		shapeX -= shapeX % 2;
		if (bombAppear2 == 1)
			shape2 = std::make_unique<Bomb>(shapeX, shapeY, board2, colors);
		else
			shape2 = std::make_unique<Shape>(shapeX, shapeY, board2, colors);

		player2->setShape(shape2.get());
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
	board1.checkRows(*player1);
	board2.checkRows(*player2);
}

void Game::checkEnd()
{
	bool pl1Won = board1.isFull(*player1);
	bool pl2Won = board2.isFull(*player2);

	if (pl1Won && pl2Won)
	{
		if (player1->getScore() >= player2->getScore())
			printWinner(*player1, *player2);
		else
			printWinner(*player2, *player1);
		finished = true;
	}
	else if (pl1Won)
	{
		printWinner(*player2, *player1);
		finished = true;
	}
	else if (pl2Won)
	{
		printWinner(*player1, *player2);
		finished = true;
	}
	if (pl1Won || pl2Won)
		while (!(_kbhit() && _getch() == ESC));
}

void Game::printWinner(Player winner, Player loser)
{
	string winnerName = winner.getName();
	clearScreen();
	gotoxy(width / 4, height / 6);
	cout << "GAME OVER" << endl << endl;
	gotoxy(width / 4 - 1, height / 6 + 1);
	cout << winnerName << " won!" << endl << endl << endl;
	cout << "press Escape to continue...";
	winner.printPlayerStats(1, 8);
	loser.printPlayerStats(15, 8);
}

bool Game::HasFinished()
{
	return finished;
}