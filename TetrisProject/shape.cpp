#include "shape.h"

Shape::Shape(int _x, int _y, const Board& _board, bool colors) :x(_x), y(_y), board(_board)
{
	SHAPE shape = (SHAPE)(rand() % 7);
	if (colors)
		color = (COLOR)(colori++ % 14 + 1);
	else
		color = LIGHTGREY;
	initShape(&arrShape);
	switch (shape)
	{
	case Shape::I:makeShapeI(&arrShape);
		break;
	case Shape::J:makeShapeJ(&arrShape);
		break;
	case Shape::L:makeShapeL(&arrShape);
		break;
	case Shape::O:makeShapeO(&arrShape);
		break;
	case Shape::S:makeShapeS(&arrShape);
		break;
	case Shape::T:makeShapeT(&arrShape);
		break;
	case Shape::Z:makeShapeZ(&arrShape);
		break;
	}
}

void Shape::move(int _x, int _y)
{
	bool validMove = false;
	cleanDraw();

	if (x + _x >= board.getPos() - 1 && x + _x < board.getPos() + board.getWidth() - shapeL)
	{
		validMove = true;
		for (size_t i = 0; i < maxX; i++)
		{
			for (size_t j = 0; j < maxY; j++)
			{
				if (arrShape[i][j] == 1 && board.isNotEmpty(x + _x + i, y + _y + j) == 1)
				{
					validMove = false;
				}
			}
		}
	}
	if (validMove)
		x += _x;

	if (!checkFall(_y, false))
		y += _y;
	else if (!checkFall(1, false))
		y++;
}

bool Shape::checkFall(int _y, bool toSet)
{
	if (y + _y > board.getHeight())
	{
		if (toSet)
			setShape();
		return true;
	}
	for (size_t i = 0; i < maxX; i++)
	{
		for (size_t j = 0; j < maxY; j++)
		{
			if (arrShape[i][j] == 1 && board.isNotEmpty(x + i, y + _y + j) == 1)
			{
				if (toSet)
					setShape();
				return true;
			}
		}
	}
	return false;
}

void Shape::draw()
{
	setTextColor(color);
	for (size_t i = 0; i < maxX; i++)
	{
		for (size_t j = 0; j < maxY; j++)
		{
			if (arrShape[i][j] == 1)
			{
				gotoxy(x + i + 2, y + j);
				cout << (char)219;
			}
		}
	}
	setTextColor(COLOR(WHITE));
}

void Shape::cleanDraw()
{
	for (size_t i = 0; i < maxX; i++)
	{
		for (size_t j = 0; j < maxY; j++)
		{
			if (arrShape[i][j] == 1)
			{
				gotoxy(x + i + 2, y + j);
				cout << ' ';
			}
		}
	}
}

void Shape::turn()
{

}

int Shape::getShapeL()
{
	return shapeL;
}

void Shape::setShape()
{
	for (size_t i = 0; i < maxX; i++)
	{
		for (size_t j = 0; j < maxY; j++)
		{
			if (arrShape[i][j] == 1)
				board.setShape(x + i, y + j, color);
		}
	}
}

void Shape::initShape(int*** arrShape)
{
	int** arr;
	arr = new int* [maxX];
	for (size_t i = 0; i < maxX; i++)
		arr[i] = new int[maxY] {};

	*arrShape = arr;
}

void Shape::makeShapeO(int*** arr)
{
	for (size_t i = 0; i < 4; i++)
		for (size_t j = 0; j < 2; j++)
			(*arr)[i][j] = 1;
	shapeL = 4;
	shapeH = 2;
}

void Shape::makeShapeI(int*** arr)
{
	for (size_t i = 0; i < 4; i++)
	{
		(*arr)[0][i] = 1;
		(*arr)[1][i] = 1;
	}
	shapeL = 2;
	shapeH = 4;
}

void Shape::makeShapeJ(int*** arr)
{
	for (size_t i = 0; i < 2; i++)
	{
		(*arr)[4][i] = 1;
		(*arr)[5][i] = 1;
	}
	for (size_t i = 0; i < 4; i++)
		(*arr)[i][1] = 1;
	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeL(int*** arr)
{
	for (size_t i = 0; i < 2; i++)
	{
		(*arr)[0][i] = 1;
		(*arr)[1][i] = 1;
	}
	for (size_t i = 2; i < 6; i++)
		(*arr)[i][1] = 1;
	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeS(int*** arr)
{
	for (size_t i = 2; i < 6; i++)
		(*arr)[i][0] = 1;
	for (size_t i = 0; i < 4; i++)
		(*arr)[i][1] = 1;
	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeT(int*** arr)
{
	for (size_t i = 0; i < 6; i++)
		(*arr)[i][1] = 1;
	(*arr)[2][0] = 1;
	(*arr)[3][0] = 1;
	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeZ(int*** arr)
{
	for (size_t i = 0; i < 4; i++)
		(*arr)[i][0] = 1;
	for (size_t i = 2; i < 6; i++)
		(*arr)[i][1] = 1;

	shapeL = 6;
	shapeH = 2;
}