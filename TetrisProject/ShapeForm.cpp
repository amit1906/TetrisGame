#include "Shape.h"

void Shape::makeShapeO()
{
	for (size_t i = 0; i < 4; i++)
		for (size_t j = 0; j < 2; j++)
			arrShape[i][j] = 1;
	shapeL = 4;
	shapeH = 2;
}

void Shape::makeShapeI1()
{
	for (size_t i = 0; i < 8; i++)
	{
		arrShape[i][0] = 1;
	}
	shapeL = 8;
	shapeH = 1;
}

void Shape::makeShapeI2()
{
	for (size_t i = 0; i < 4; i++)
	{
		arrShape[0][i] = 1;
		arrShape[1][i] = 1;
	}
	shapeL = 2;
	shapeH = 4;
}

void Shape::makeShapeL1()
{
	for (size_t i = 0; i < 2; i++)
	{
		arrShape[0][i] = 1;
		arrShape[1][i] = 1;
	}
	for (size_t i = 2; i < 6; i++)
		arrShape[i][1] = 1;
	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeL2()
{
	for (size_t i = 2; i < 4; i++)
	{
		arrShape[i][0] = 1;
	}
	for (size_t i = 0; i < 3; i++)
	{
		arrShape[0][i] = 1;
		arrShape[1][i] = 1;
	}
	shapeL = 4;
	shapeH = 3;
}

void Shape::makeShapeL3()
{
	for (size_t i = 0; i < 6; i++)
		arrShape[i][0] = 1;
	for (size_t i = 4; i < 6; i++)
	{
		arrShape[i][1] = 1;
		arrShape[i][1] = 1;
	}
	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeL4()
{
	for (size_t i = 0; i < 3; i++)
	{
		arrShape[2][i] = 1;
		arrShape[3][i] = 1;
	}
	for (size_t i = 0; i < 2; i++)
	{
		arrShape[i][2] = 1;
	}
	shapeL = 4;
	shapeH = 3;
}

void Shape::makeShapeJ1()
{
	for (size_t i = 0; i < 2; i++)
	{
		arrShape[4][i] = 1;
		arrShape[5][i] = 1;
	}
	for (size_t i = 0; i < 4; i++)
		arrShape[i][1] = 1;
	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeJ2()
{
	for (size_t i = 0; i < 3; i++)
	{
		arrShape[0][i] = 1;
		arrShape[1][i] = 1;
	}
	arrShape[2][2] = 1;
	arrShape[3][2] = 1;
	shapeL = 4;
	shapeH = 3;
}

void Shape::makeShapeJ3()
{
	for (size_t i = 0; i < 6; i++)
	{
		arrShape[i][0] = 1;
	}
	arrShape[0][1] = 1;
	arrShape[1][1] = 1;
	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeJ4()
{
	for (size_t i = 0; i < 3; i++)
	{
		arrShape[2][i] = 1;
		arrShape[3][i] = 1;
	}
	arrShape[0][0] = 1;
	arrShape[1][0] = 1;
	shapeL = 4;
	shapeH = 3;
}

void Shape::makeShapeT1()
{
	for (size_t i = 0; i < 6; i++)
		arrShape[i][1] = 1;
	arrShape[2][0] = 1;
	arrShape[3][0] = 1;
	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeT2()
{
	for (size_t i = 0; i < 3; i++)
	{
		arrShape[0][i] = 1;
		arrShape[1][i] = 1;
	}
	arrShape[2][1] = 1;
	arrShape[3][1] = 1;
	shapeL = 4;
	shapeH = 3;
}

void Shape::makeShapeT3()
{
	for (size_t i = 0; i < 6; i++)
		arrShape[i][0] = 1;
	arrShape[2][1] = 1;
	arrShape[3][1] = 1;
	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeT4()
{
	for (size_t i = 0; i < 3; i++)
	{
		arrShape[2][i] = 1;
		arrShape[3][i] = 1;
	}
	arrShape[0][1] = 1;
	arrShape[1][1] = 1;
	shapeL = 4;
	shapeH = 3;
}

void Shape::makeShapeS1()
{
	for (size_t i = 2; i < 6; i++)
		arrShape[i][0] = 1;
	for (size_t i = 0; i < 4; i++)
		arrShape[i][1] = 1;
	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeS2()
{
	for (size_t i = 1; i < 3; i++)
	{
		arrShape[2][i] = 1;
		arrShape[3][i] = 1;
	}
	for (size_t i = 0; i < 2; i++)
	{
		arrShape[0][i] = 1;
		arrShape[1][i] = 1;
	}
	shapeL = 4;
	shapeH = 3;
}

void Shape::makeShapeS3()
{
	for (size_t i = 0; i < 4; i++)
		arrShape[i][1] = 1;
	for (size_t i = 2; i < 6; i++)
		arrShape[i][0] = 1;
	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeS4()
{
	for (size_t i = 0; i < 2; i++)
	{
		arrShape[0][i] = 1;
		arrShape[1][i] = 1;
	}
	for (size_t i = 1; i < 3; i++)
	{
		arrShape[2][i] = 1;
		arrShape[3][i] = 1;
	}
	shapeL = 4;
	shapeH = 3;
}

void Shape::makeShapeZ1()
{
	for (size_t i = 0; i < 4; i++)
		arrShape[i][0] = 1;
	for (size_t i = 2; i < 6; i++)
		arrShape[i][1] = 1;

	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeZ2()
{
	for (size_t i = 0; i < 2; i++)
	{
		arrShape[2][i] = 1;
		arrShape[3][i] = 1;
	}
	for (size_t i = 1; i < 3; i++)
	{
		arrShape[0][i] = 1;
		arrShape[1][i] = 1;
	}
	shapeL = 4;
	shapeH = 3;
}

void Shape::makeShapeZ3()
{
	for (size_t i = 0; i < 4; i++)
		arrShape[i][0] = 1;
	for (size_t i = 2; i < 6; i++)
		arrShape[i][1] = 1;

	shapeL = 6;
	shapeH = 2;
}

void Shape::makeShapeZ4()
{
	for (size_t i = 0; i < 2; i++)
	{
		arrShape[2][i] = 1;
		arrShape[3][i] = 1;
	}
	for (size_t i = 1; i < 3; i++)
	{
		arrShape[0][i] = 1;
		arrShape[1][i] = 1;
	}
	shapeL = 4;
	shapeH = 3;
}