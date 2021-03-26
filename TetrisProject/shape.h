#pragma once
#include "utils.h"
#include "board.h"

static int colori = 1;
constexpr int maxBlock = 8;

class Shape
{
	enum SHAPE { O, I, L, J, T, S, Z };
	enum SHAPE_T { T1, T2, T3, T4 };
	Board board;
	SHAPE shape;
	SHAPE_T shape_t;
	COLOR color;
	int x, y;
	int shapeL, shapeH;
	int arrShape[maxBlock][maxBlock]{};

public:
	Shape(int _x, int _y, const Board& _board, bool colors);
	void move(int _x = 0, int _y = 1);
	void draw();
	void turn(int dir);
	bool checkFall(int _y = 1, bool toSet = true);
	int getShapeL();

private:
	void setShape();
	void clearShape();
	bool isValidTurn();
	void cleanDraw();
	void turnDigree();

	void makeShapeO();		// shape O
	void makeShapeI1();		// shape I
	void makeShapeI2();
	void makeShapeL1();		// shape L
	void makeShapeL2();
	void makeShapeL3();
	void makeShapeL4();
	void makeShapeJ1();		// shape J
	void makeShapeJ2();
	void makeShapeJ3();
	void makeShapeJ4();
	void makeShapeT1();		// shape T
	void makeShapeT2();
	void makeShapeT3();
	void makeShapeT4();
	void makeShapeS1();		// shape S
	void makeShapeS2();
	void makeShapeS3();
	void makeShapeS4();
	void makeShapeZ1();		// shape Z
	void makeShapeZ2();
	void makeShapeZ3();
	void makeShapeZ4();

};