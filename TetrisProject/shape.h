#pragma once
#include "utils.h"
#include "board.h"
using namespace std;

static int colori = 1;
constexpr int maxBlock = 8;

class Shape
{
	enum SHAPE { I, J, L, O, S, T, Z };
	enum SHAPE_T { T1, T2, T3, T4 };
	Board board;
	SHAPE shape;
	SHAPE_T shape_t;
	COLOR color;
	int shapeL, shapeH;
	int x, y;
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
	void initShape();
	void clearShape();
	bool isValidTurn();
	void cleanDraw();
	void makeShapeO();		// shape O
	void makeShapeI1();		// shape I
	void makeShapeI2();
	void makeShapeL1();		// shape L
	void makeShapeL2();
	void makeShapeL3();
	void makeShapeL4();
	void makeShapeS();		// shape S
	void makeShapeT();		// shape T
	void makeShapeJ();		// shape J
	void makeShapeZ();		// shape Z
	void turnDigree();

};