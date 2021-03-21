#include "game.h"

Game::Game()
{
	colors = true;
	shapeX = rand() % (width - maxX) + pos;
	shapeX -= shapeX % 2 - 1;
	shape1 = new Shape(shapeX, shapeY, board1, colors);
	shapeX = rand() % (width - maxX) + width + pos;
	shapeX -= shapeX % 2;
	shape2 = new Shape(shapeX, shapeY, board2, colors);
}

void Game::startGame()
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
			case PL1::ROTATER1:
				break;
			case PL1::ROTATEL1:
				break;
			case PL1::DROP1:	c1 = PL1::DROP1;
				break;
			case PL2::LEFT2:	c2 = PL2::LEFT2;
				break;
			case PL2::RIGHT2:	c2 = PL2::RIGHT2;
				break;
			case PL2::ROTATER2:
				break;
			case PL2::ROTATEL2:
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
		case PL1::ROTATER1:
			break;
		case PL1::ROTATEL1:
			break;
		case PL1::DROP1:	shape1->move(0, 3);
			break;
		case PL2::LEFT2:	shape2->move(-2);
			break;
		case PL2::RIGHT2:	shape2->move(2);
			break;
		case PL2::ROTATER2:
			break;
		case PL2::ROTATEL2:
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

void Game::menu()
{
	menuInfo();
	string name;
	char c = getchar();
	//	char c = '1';				// remove

	while (true)
	{
		switch (c)
		{
		case '1':
			startGame();
			menuInfo();
			break;
		case '2':
			break;
		case '3':
			if (colors)
				colors = false;
			else
				colors = true;
			clearScreen();
			menuInfo();
			break;
		case '4':
			cout << "choose your new speed (1-1000): ";
			cin >> speed;
			if (speed < 1)
				speed = 1;
			if (speed > 1000)
				speed = 1000;
			clearScreen();
			menuInfo();
			break;
		case '5':
			cout << "player1's name: ";
			cin >> name;
			score1.setName(name);
			cout << "player2's name: ";
			cin >> name;
			score2.setName(name);
			clearScreen();
			menuInfo();
			break;
		case '8':
			clearScreen();
			instructionsInfo();
			menuInfo();
			break;
		case '9':
			exit(0);
			break;
		default:
			clearScreen();
			menuInfo();
			break;
		}
		cin >> c;
	}
}

void Game::menuInfo()
{
	cout << "(1) Start a new game" << endl;
	cout << "(2) Continue a paused game" << endl;
	cout << "(3) play with colors? " << (colors == 1 ? "YES" : "NO") << " \t(NEW FEATURE)" << endl;
	cout << "(4) set speed in ms?  " << speed << " \t(NEW FEATURE)" << endl;
	cout << "(5) set your names?  " << "\t\t(NEW FEATURE)" << endl;
	cout << "(8) Present instructions" << endl;
	cout << "(9) EXIT" << endl;
	cout << "choose option: ";
}
void Game::instructionsInfo()
{
	cout << "Instructions for playing" << endl;
	cout << "use the following keys to play:\n" << endl;
	cout << "\t\t\tLeft Player\tRight Player" << endl;
	cout << "LEFT:\t\t\t a or A\t\tj or J" << endl;
	cout << "RIGHT:\t\t\t d or D\t\tl (small L) or L" << endl;
	cout << "ROTATE clockwise:\t s or S\t\tk or K" << endl;
	cout << "ROTATE counterclockwise: w or W\t\ti or I (uppercase i)" << endl;
	cout << "DROP:\t\t\t x or X\t\tm or M" << endl << endl;
}
