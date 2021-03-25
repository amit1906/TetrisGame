#include "menu.h"

void Menu::Start()
{
	menuInfo();
	//char c = getchar();
		char c = '1';	// remove

	while (true)
	{
		switch (c)
		{
		case '1':
			initGame();
			break;
		case '2':
			continueGame();
			break;
		case '3':
			changeColors();
			break;
		case '4':
			changeSpeed();
			break;
		case '5':
			changeNames();
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

void Menu::initGame()
{
	delete game;
	game = new Game(speed, colors, name1, name2);
	game->start();
	menuInfo();
}

void Menu::continueGame()
{
	if (game != NULL)
	{
		game->changeSettings(speed, colors, name1, name2);
		game->start();
		menuInfo();
	}
	else
	{
		clearScreen();
		menuInfo();
	}
}

void Menu::changeColors()
{
	if (colors)
		colors = false;
	else
		colors = true;
	clearScreen();
	menuInfo();
}

void Menu::changeSpeed()
{
	cout << "choose your new speed (1-1000): ";
	cin >> speed;
	if (speed < 1)
		speed = 1;
	if (speed > 1000)
		speed = 1000;
	clearScreen();
	menuInfo();
}

void Menu::changeNames()
{
	string name;
	cout << "player1's name: ";
	cin >> name;
	name1 = name;
	cout << "player2's name: ";
	cin >> name;
	name2 = name;
	clearScreen();
	cout << "names changed." << endl;
	menuInfo();
}

void Menu::menuInfo()
{
	cout << "(1) Start a new game" << endl;
	(game != NULL) ? (cout << "(2) Continue a paused game" << endl) : cout << "";
	cout << "(3) play with colors? " << (colors == 1 ? "YES" : "NO") << " \t(NEW FEATURE)" << endl;
	cout << "(4) set speed in ms?  " << speed << " \t(NEW FEATURE)" << endl;
	cout << "(5) set your names?  " << "\t\t(NEW FEATURE)" << endl;
	cout << "(8) Present instructions" << endl;
	cout << "(9) EXIT" << endl;
	cout << "choose option: ";
}

void Menu::instructionsInfo()
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