#include "Shape.h"

Shape::Shape(int _x, int _y, const Board& _board, bool colors) 
	:x(_x), y(_y), board(_board)
{
	shape = (SHAPE)(rand() % 7);
	shape_t = (SHAPE_T)T1;	//(rand() % 4);
	if (colors)
		color = (COLOR)(colori++ % 14 + 1);
	else
		color = LIGHTGREY;
	switch (shape)
	{
	case Shape::O:makeShapeO();
		break;
	case Shape::I:makeShapeI1();
		break;
	case Shape::L:makeShapeL1();
		break;
	case Shape::J:makeShapeJ1();
		break;
	case Shape::T:makeShapeT1();
		break;
	case Shape::S:makeShapeS1();
		break;
	case Shape::Z:makeShapeZ1();
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
		for (size_t i = 0; i < maxBlock; i++)
		{
			for (size_t j = 0; j < maxBlock; j++)
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
	for (size_t i = 0; i < maxBlock; i++)
	{
		for (size_t j = 0; j < maxBlock; j++)
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
	for (size_t i = 0; i < maxBlock; i++)
	{
		for (size_t j = 0; j < maxBlock; j++)
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
	for (size_t i = 0; i < maxBlock; i++)
	{
		for (size_t j = 0; j < maxBlock; j++)
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
	if (!isValidTurn())
		return;
	cleanDraw();
	clearShape();
	switch (shape)
	{
	case Shape::I:
		if (shape_t % 2 == T1)
		{
			makeShapeI2();
			shape_t = T2;
		}
		else
		{
			makeShapeI1();
			shape_t = T1;
		}
		break;
	case Shape::J:
		shape_t = (shape_t + dir == -1) ? (SHAPE_T)3 : SHAPE_T((shape_t + dir) % 4);
		if (shape_t == T1)
			makeShapeJ1();
		if (shape_t == T2)
			makeShapeJ2();
		if (shape_t == T3)
			makeShapeJ3();
		if (shape_t == T4)
			makeShapeJ4();
		break;
	case Shape::L:
		shape_t = (shape_t + dir == -1) ? (SHAPE_T)3 : SHAPE_T((shape_t + dir) % 4);
		if (shape_t == T1)
			makeShapeL1();
		if (shape_t == T2)
			makeShapeL2();
		if (shape_t == T3)
			makeShapeL3();
		if (shape_t == T4)
			makeShapeL4();
		break;
	case Shape::T:
		shape_t = (shape_t + dir == -1) ? (SHAPE_T)3 : SHAPE_T((shape_t + dir) % 4);
		if (shape_t == T1)
			makeShapeT1();
		if (shape_t == T2)
			makeShapeT2();
		if (shape_t == T3)
			makeShapeT3();
		if (shape_t == T4)
			makeShapeT4();
		break;
	case Shape::S:
		shape_t = (shape_t + dir == -1) ? (SHAPE_T)3 : SHAPE_T((shape_t + dir) % 4);
		if (shape_t == T1)
			makeShapeS1();
		if (shape_t == T2)
			makeShapeS2();
		if (shape_t == T3)
			makeShapeS3();
		if (shape_t == T4)
			makeShapeS4();
		break;
	case Shape::Z:
		shape_t = (shape_t + dir == -1) ? (SHAPE_T)3 : SHAPE_T((shape_t + dir) % 4);
		if (shape_t == T1)
			makeShapeZ1();
		if (shape_t == T2)
			makeShapeZ2();
		if (shape_t == T3)
			makeShapeZ3();
		if (shape_t == T4)
			makeShapeZ4();
		break;
	}
	draw();
}

void Shape::turnDigree()
{
	int res[maxBlock][maxBlock];

	for (int i = 0; i < maxBlock; ++i)
	{
		for (int j = 0; j < maxBlock; ++j)
		{
			res[i][j] = arrShape[maxBlock - j - 1][i];
		}
	}
	for (size_t i = 0; i < maxBlock; i++)
	{
		for (size_t j = 0; j < maxBlock; j++)
		{
			arrShape[i][j] = res[i][j];
		}
	}

}

bool Shape::isValidTurn()
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
	for (size_t i = 0; i < maxBlock; i++)
	{
		for (size_t j = 0; j < maxBlock; j++)
		{
			if (arrShape[i][j] == 1)
				board.setShape(x + i, y + j, color);
		}
	}
}

void Shape::clearShape()
{
	for (size_t i = 0; i < maxBlock; i++)
		for (size_t j = 0; j < maxBlock; j++)
			arrShape[j][i] = 0;
}