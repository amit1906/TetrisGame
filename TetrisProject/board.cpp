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

void Board::printFrame()
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
}

void Board::printContent(bool clean)
{
	for (size_t i = 1; i < width; i++)
	{
		for (size_t j = 0; j < height; j++)
		{
			if (arrBoard[i][j].set == 1)
			{
				setTextColor(arrBoard[i][j].color);
				gotoxy(pos + i, j);
				cout << (char)219;
			}
			else if (clean)
			{
				gotoxy(pos + i, j);
				cout << ' ';
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

void Board::checkRows(Score& score)
{
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 1; j < width; j++)
		{
			if (arrBoard[j][i].set == 0)
				break;
			else if (j == width - 1)
			{
				deleteRow(i);
				cout << "\a";
				score.increaseScore();
				printContent(true);
				if (i < height - 1)
					i += 2;
			}
		}
	}
}

void Board::deleteRow(int row)
{
	setTextColor(RED);
	for (size_t i = 1; i < width; i++)
	{
		gotoxy(pos + i, row);
		cout << (char)219;
	}
	Sleep(500);
	for (size_t i = row; i > 0; i--)
	{
		for (size_t j = 1; j < width; j++)
		{
			arrBoard[j][i] = arrBoard[j][i - 1];
		}
	}
}

bool Board::isFull(Score pl, Score score1, Score score2)
{
	string winner;
	if (pl.getName() == score1.getName())
		winner = score2.getName();
	else
		winner = score1.getName();

	for (size_t i = 0; i < width; i++)
	{
		if (arrBoard[i][0].set == 1)
		{
			clearScreen();
			gotoxy(width / 4, height / 6);
			cout << "GAME OVER" << endl << endl;
			gotoxy(width / 4 - 1, height / 6 + 1);
			cout << winner << " won!" << endl << endl << endl;
			cout << "press Escape to continue...";
			score1.printPlayer(1, 8);
			score2.printPlayer(15, 8);
			return true;
		}
	}
	return false;
}