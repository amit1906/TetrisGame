#include "game.h"

Game::Game(int _speed, bool _colors, string name1, string name2) :
	speed(_speed), colors(_colors), score1(name1), score2(name2)
{
	shapeX = rand() % (width - maxX) + pos;
	shapeX -= shapeX % 2 - 1;
	shape1 = new Shape(shapeX, shapeY, board1, colors);
	shapeX = rand() % (width - maxX) + width + pos;
	shapeX -= shapeX % 2;
	shape2 = new Shape(shapeX, shapeY, board2, colors);
}

void Game::changeSettings(int _speed, bool _colors, string name1, string name2)
{
	speed = _speed;
	colors = _colors;
	score1.setName(name1);
	score2.setName(name2);
}

void Game::start()
{
	clearScreen();
	drawBoard();
	gameLoop();
	clearScreen();
}

void Game::gameLoop()
{
	while (!toEnd)
	{
		checkShapes();
		checkKeys();
		drawGame();
		checkRows();
		checkEnd();
	}
	toEnd = false;
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
	score1.printPlayer(board1.getPos(), board1.getHeight());
	score2.printPlayer(board2.getPos(), board1.getHeight());
	hideCursor();
	Sleep(speed);
}

void Game::checkShapes()
{
	if (shape1->checkFall())
	{
		delete shape1;
		shapeX = rand() % (width - maxX) + pos;
		shapeX -= shapeX % 2 - 1;
		shape1 = new Shape(shapeX, shapeY, board1, colors);
	}
	if (shape2->checkFall())
	{
		delete shape2;
		shapeX = rand() % (width - maxX) + width + pos;
		shapeX -= shapeX % 2;
		shape2 = new Shape(shapeX, shapeY, board2, colors);
	}
}

void Game::checkKeys()
{
	int keysItr = 20;
	char c1 = ' ', c2 = ' ', c;

	for (size_t i = 0; i < keysItr; i++)
	{
		if (_kbhit())
		{
			c = _getch();
			if (c >= 'A' && c <= 'Z')
				c += 'a' - 'A';
			switch (c)
			{
			case PL1::LEFT1:	c1 = PL1::LEFT1;
				break;
			case PL1::RIGHT1:	c1 = PL1::RIGHT1;
				break;
			case PL1::ROTATER1:	c1 = PL1::ROTATER1;
				break;
			case PL1::ROTATEL1:	c1 = PL1::ROTATEL1;
				break;
			case PL1::DROP1:	c1 = PL1::DROP1;
				break;
			case PL2::LEFT2:	c2 = PL2::LEFT2;
				break;
			case PL2::RIGHT2:	c2 = PL2::RIGHT2;
				break;
			case PL2::ROTATER2:	c2 = PL2::ROTATER2;
				break;
			case PL2::ROTATEL2:	c2 = PL2::ROTATEL2;
				break;
			case PL2::DROP2:	c2 = PL2::DROP2;
				break;
			case ESC:			toEnd = true;
				break;
			}
		}
	}
	c = c1;
	for (size_t i = 0; i < 2; i++)
	{
		if (i == 1)
			c = c2;
		switch (c)
		{
		case PL1::LEFT1:	shape1->move(-2);
			break;
		case PL1::RIGHT1:	shape1->move(2);
			break;
		case PL1::ROTATER1:	shape1->turn(1);
			break;
		case PL1::ROTATEL1:	shape1->turn(-1);
			break;
		case PL1::DROP1:	shape1->move(0, 3);
			break;
		case PL2::LEFT2:	shape2->move(-2);
			break;
		case PL2::RIGHT2:	shape2->move(2);
			break;
		case PL2::ROTATER2:	shape2->turn(1);
			break;
		case PL2::ROTATEL2:	shape2->turn(-1);
			break;
		case PL2::DROP2:	shape2->move(0, 3);
			break;
		}
	}
}

void Game::checkEnd()
{
	if (board1.isFull(score1, score1, score2) || board2.isFull(score2, score1, score2))
	{
		while (!(_kbhit() && _getch() == ESC));
		toEnd = true;
	}
}

void Game::checkRows()
{
	board1.checkRows(score1);
	board2.checkRows(score2);
}