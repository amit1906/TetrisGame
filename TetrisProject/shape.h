#pragma once
#include "Utils.h"
#include "Board.h"

static int colori = 1;
constexpr int maxBlock = 8;

class Shape
{
private:
	enum SHAPE { O, I, L, J, T, S, Z };
	enum SHAPE_T { T1, T2, T3, T4 };
	SHAPE_T shape_t;
	COLOR color;

protected:
	Board board;
	SHAPE shape;
	int arrShape[maxBlock][maxBlock]{};
	int shapeL, shapeH;
	int x, y;

public:
	Shape(int _x, int _y, const Board& _board, bool colors);
	void move(int _x = 0, int _y = 1);
	void draw();
	void turn(int dir);
	virtual bool checkFall(int _y = 1, bool toSet = true);
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