#include "board.h"

Board::Board(const int _pos, const int _height, const int _width) :pos(_pos), height(_height), width(_width)
{
	arrBoard = new point * [width];
	for (size_t i = 0; i < width; i++)
		arrBoard[i] = new point[height]{};
}

void Board::setShape(int x, int y, COLOR color)
{
	x %= width;
	arrBoard[x][y].set = 1;
	arrBoard[x][y].color = color;
}

void Board::print()
{
	for (size_t i = 0; i < height; i++)
	{
		gotoxy(pos, i);
		cout << (char)178;
		gotoxy(pos + width, i);
		cout << (char)178;
	}
	for (size_t i = 0; i <= width; i++)
	{
		gotoxy(pos + i, height);
		cout << (char)178;
	}
	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < height; j++)
		{
			if (arrBoard[i][j].set == 1)
			{
				setTextColor(arrBoard[i][j].color);
				gotoxy(pos + i, j);
				cout << (char)219;
			}
		}
	}
	setTextColor(WHITE);
}

int Board::getPos()
{
	return pos;
}

int Board::getWidth()
{
	return width - 1;
}

int Board::getHeight()
{
	return height - 1;
}

bool Board::isNotEmpty(int x, int y)
{
	x %= width;
	return arrBoard[x][y].set;
}

bool Board::isFull(int pl)
{
	pl == 1 ? pl = 2 : pl = 1;
	for (size_t i = 0; i < width; i++)
	{
		if (arrBoard[i][0].set == 1)
		{
			clearScreen();
			gotoxy(width, height / 2);
			cout << "GAME OVER" << endl << endl;
			gotoxy(width - 2, height / 2 + 1);
			cout << "player " << pl << " won!" << endl << endl << endl;
			cout << "press Escape to continue...";
			printScores();
			return true;
		}
	}
	return false;
}