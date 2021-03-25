#include "shape.h"

Shape::Shape(int _x, int _y, const Board& _board, bool colors) :x(_x), y(_y), board(_board)
{
	shape = (SHAPE)L;		//(rand() % 7);
	shape_t = T1;
	if (colors)
		color = (COLOR)(colori++ % 14 + 1);
	else
		color = LIGHTGREY;
	initShape(&arrShape);
	switch (shape)
	{
	case Shape::I:makeShapeI1(&arrShape);
		break;
	case Shape::J:makeShapeJ(&arrShape);
		break;
	case Shape::L:makeShapeL1(&arrShape);
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
	cleanDraw();
	bool validMove = false;
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
	if (_x == 0)
	{
		if (!checkFall(_y, false))
			y += _y;
		else if (!checkFall(1, false))
			y++;
	}
	draw();
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

void Shape::turn(int dir)
{
	if (!validTurn())
		return;
	cleanDraw();
	clearShape(&arrShape);
	switch (shape)
	{
	case Shape::I:
		if (shape_t == T1)
		{
			makeShapeI2(&arrShape);
			shape_t = T2;
		}
		else
		{
			makeShapeI1(&arrShape);
			shape_t = T1;
		}
		break;
	case Shape::J:makeShapeJ(&arrShape);
		break;
	case Shape::L:
		shape_t = (shape_t + dir == -1) ? (SHAPE_T)3 : SHAPE_T((shape_t + dir) % 4);
		if (shape_t == T1)
			makeShapeL1(&arrShape);
		if (shape_t == T2)
			makeShapeL2(&arrShape);
		if (shape_t == T3)
			makeShapeL3(&arrShape);
		if (shape_t == T4)
			makeShapeL4(&arrShape);
		break;
	case Shape::S:makeShapeS(&arrShape);
		break;
	case Shape::T:makeShapeT(&arrShape);
		break;
	case Shape::Z:makeShapeZ(&arrShape);
		break;
	}
}

bool Shape::validTurn()
{
	if (shape == O)
		return false;
	for (size_t i = 0; i < max(shapeH * 2, shapeL / 2); i++)
	{
		if (y + i > board.getHeight())
			return false;
		if (board.isNotEmpty(x + i, y) || board.isNotEmpty(x, y + i))
			return false;
	}
	if (x + max(shapeH * 2, shapeL / 2) >= board.getPos() + board.getWidth())
		return false;
	return true;
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

void Shape::clearShape(int*** arrShape)
{
	for (size_t i = 0; i < maxX; i++)
		for (size_t j = 0; j < maxY; j++)
			(*arrShape)[j][i] = 0;
}

void Shape::makeShapeO(int*** arr)
{
	for (size_t i = 0; i < 4; i++)
		for (size_t j = 0; j < 2; j++)
			(*arr)[i][j] = 1;
	shapeL = 4;
	shapeH = 2;
}

void Shape::makeShapeI1(int*** arr)
{
	for (size_t i = 0; i < 8; i++)
	{
		(*arr)[i][0] = 1;
	}
	shapeL = 8;
	shapeH = 1;
}

void Shape::makeShapeI2(int*** arr)
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

void Shape::makeShapeL1(int*** arr)
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

void Shape::makeShapeL2(int*** arr)
{
	for (size_t i = 2; i < 4; i++)
	{
		(*arr)[i][0] = 1;
	}
	for (size_t i = 0; i < 3; i++)
	{
		(*arr)[0][i] = 1;
		(*arr)[1][i] = 1;
	}
	shapeL = 4;
	shapeH = 3;
}

void Shape::makeShapeL3(int*** arr)
{
	for (size_t i = 0; i < 6; i++)
		(*arr)[i][0] = 1;
	for (size_t i = 4; i < 6; i++)
	{
		(*arr)[i][1] = 1;
		(*arr)[i][1] = 1;
	}
	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeL4(int*** arr)
{
	for (size_t i = 0; i < 3; i++)
	{
		(*arr)[2][i] = 1;
		(*arr)[3][i] = 1;
	}
	for (size_t i = 0; i < 2; i++)
	{
		(*arr)[i][2] = 1;
	}
	shapeL = 4;
	shapeH = 3;
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