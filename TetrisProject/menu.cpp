#include "Menu.h"

Menu::~Menu()
{
	freeGame();
}

void Menu::Start()
{
	menuInfo();
	srand(time(0));	// improves random
	char c = getchar();
	int level;

	while (true)
	{
		switch (c)
		{
		case '1':
			freeGame();
			game = new Game(HVH, speed, colors, names);
			initGame();
			break;
		case '2':
			freeGame();
			level = levelInfo();
			names[1] = "computer";
			game = new Game(HVC, speed, colors, names, level);
			initGame();
			break;
		case '3':
			freeGame();
			level = levelInfo();
			names[0] = "computer1";
			names[1] = "computer2";
			game = new Game(CVC, speed, colors, names, level);
			initGame();
			break;
		case '4':
			continueGame();
			break;
		case '5':
			changeColors();
			break;
		case '6':
			changeSpeed();
			break;
		case '7':
			changeNames();
			break;
		case '8':
			clearScreen();
			instructionsInfo();
			menuInfo();
			break;
		case '9':
			clearScreen();
			cout << "Good Bye" << endl;
			_getch();
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
	game->start();
	if (game->HasFinished())
		game = nullptr;
	menuInfo();
}

void Menu::freeGame()
{
	if (game)
	{
		delete game;
		game = nullptr;
	}
}

void Menu::continueGame()
{
	if (game != nullptr)
	{
		game->changeSettings(speed, colors, names);
		game->start();
		if (game->HasFinished())
			freeGame();
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
	if (speed < MIN_SPEED)
		speed = MIN_SPEED;
	if (speed > MAX_SPEED)
		speed = MAX_SPEED;
	clearScreen();
	menuInfo();
}

void Menu::changeNames()
{
	for (size_t i = 0; i < NUM_PLAYERS; i++)
	{
		cout << "player" << i + 1 << "'s name: ";
		cin >> names[i];
	}
	clearScreen();
	cout << "names changed." << endl;
	menuInfo();
}

void Menu::menuInfo()
{
	cout << "(1) Start a new game - Human vs Human" << endl;
	cout << "(2) Start a new game - Human vs Computer" << endl;
	cout << "(3) Start a new game - Computer vs Computer" << endl;
	(game != NULL) ? (cout << "(4) Continue a paused game" << endl) : (cout << "");
	cout << "(5) play with colors? " << (colors == 1 ? "YES" : "NO") << endl;
	cout << "(6) set speed in ms?  " << speed << endl;
	cout << "(7) set your names?  " << endl;
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

int Menu::levelInfo()
{
	int level;
	do {
		clearScreen();
		cout << "level are: (1)BEST ,(2)GOOD, (3)NOVICE" << endl;
		cout << "please select computer level: ";
		cin >> level;
	} while (level > 3 || level < 1);
	return level;
}