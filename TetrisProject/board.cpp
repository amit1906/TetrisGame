#include "Board.h"

Board::Board(const int _pos, const int _height, const int _width)
	:pos(_pos), height(_height), width(_width)
{
	arrBoard = new point * [width];
	for (size_t i = 0; i < width; i++)
		arrBoard[i] = new point[height]{};
}

Board::Board(const Board& board)
	:pos(board.pos), height(board.height), width(board.width)
{
	arrBoard = new point * [width];
	for (size_t i = 0; i < width; i++)
		arrBoard[i] = new point[height]{};

	for (size_t i = 0; i < height; i++)
		for (size_t j = 0; j < width; j++)
			arrBoard[j][i] = board.arrBoard[j][i];
}

Board::~Board()	// this dtor prevents memory leak, but might cause exception...
{
	//for (size_t i = 0; i < width; i++)
	//{
	//	delete arrBoard[i];
	//	arrBoard[i] = nullptr;
	//}
	//delete[] arrBoard;
	//arrBoard = nullptr;
}

void Board::SetBoard(const Board& b)
{
	for (size_t i = 0; i < height; i++)
		for (size_t j = 0; j < width; j++)
			arrBoard[j][i].set = b.arrBoard[j][i].set;
}

void Board::setShape(int x, int y, COLOR color, int toSet)
{
	x %= width;
	arrBoard[x][y].color = color;
	if (toSet == 1)
		arrBoard[x][y].set = 1;
	else
		arrBoard[x][y].set = 0;
}

void Board::unSetShape(int x, int y)
{
	x %= width;
	arrBoard[x][y].set = 0;
}

void Board::SetShape(int x, int y, int set, COLOR color)
{
	arrBoard[x][y].color = color;
	arrBoard[x][y].set = set;
}

bool Board::isEmpty(int x, int y) const
{
	x %= width;
	return (arrBoard[x][y].set == 0);
}

void Board::printFrame() const
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

void Board::printContent(bool clean) const
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

int Board::getPos() const
{
	return pos;
}

int Board::getWidth() const
{
	return width - 1;
}

int Board::getHeight() const
{
	return height - 1;
}

void Board::checkRows(Player& player)
{
	int delRows = 0;
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
				player.increaseScore(10);
				printContent(true);
				if (i < height - 1)
					i += 2;
			}
		}
	}
}

int Board::checkRows() const
{
	int delRows = 0;
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 1; j < width; j++)
		{
			if (arrBoard[j][i].set == 0)
				break;
			else if (j == width - 1)
			{
				delRows++;
				if (i < height - 1)
					i += 2;
			}
		}
	}
	return delRows;
}

void Board::deleteRow(int row)
{
	setTextColor(RED);
	for (size_t i = 1; i < width; i++)
	{
		gotoxy(pos + i, row);
		cout << (char)219;
	}
	Sleep(400);
	for (size_t i = row; i > 0; i--)
	{
		for (size_t j = 1; j < width; j++)
		{
			arrBoard[j][i] = arrBoard[j][i - 1];
		}
	}
}

void Board::fixBoard(int from, int to)
{
	int rowset, rowFrom;
	for (size_t i = from; i < to; i++)
	{
		rowset = 0;
		rowFrom = 0;
		for (size_t j = height - 1; j > 0; j--)
		{
			if (isEmpty(i, j) && rowset == 0)
				rowset = j;
			if (!isEmpty(i, j) && rowset != 0 && rowFrom == 0)
				rowFrom = j;
		}
		for (size_t j = rowFrom; j > 0; j--)
		{
			SetShape(i, rowset--, arrBoard[i][j].set, arrBoard[i][j].color);
			unSetShape(i, j);
		}
	}
	printContent(true);
}

bool Board::isFull(Player player) const
{
	for (size_t i = 0; i < width; i++)
	{
		if (arrBoard[i][0].set == 1)
		{
			return true;
		}
	}
	return false;
}