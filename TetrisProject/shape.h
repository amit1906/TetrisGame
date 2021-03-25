#pragma once
#include "utils.h"
#include "board.h"
using namespace std;

static int colori = 1;

class Shape
{
	enum SHAPE { I, J, L, O, S, T, Z };
	enum SHAPE_T { T1, T2, T3, T4 };
	Board board;
	SHAPE shape;
	SHAPE_T shape_t;
	COLOR color;
	const int maxX = 8, maxY = 8;
	int shapeL, shapeH;
	int x, y;
	int** arrShape;

public:
	Shape(int _x, int _y, const Board& _board, bool colors);
	void move(int _x = 0, int _y = 1);
	void draw();
	void turn(int dir);
	bool checkFall(int _y = 1, bool toSet = true);
	int getShapeL();

private:
	void setShape();
	void initShape(int*** arrShape);
	void clearShape(int*** arrShape);
	bool validTurn();
	void cleanDraw();
	void makeShapeO(int*** arrShape);	// shape O
	void makeShapeI1(int*** arr);		// shape I
	void makeShapeI2(int*** arr);
	void makeShapeL1(int*** arr);		// shape L
	void makeShapeL2(int*** arr);
	void makeShapeL3(int*** arr);
	void makeShapeL4(int*** arr);
	void makeShapeS(int*** arr);		// shape S
	void makeShapeT(int*** arr);		// shape T
	void makeShapeJ(int*** arr);		// shape J
	void makeShapeZ(int*** arr);		// shape Z

};