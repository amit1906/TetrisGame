#pragma once
#include "utils.h"
#include "board.h"
using namespace std;

static int colori = 1;

class Shape
{
	Board board;
	enum SHAPE { I, J, L, O, S, T, Z };
	COLOR color;
	const int maxX = 8, maxY = 8;
	int shapeL, shapeH;
	int x, y;
	int** arrShape;

public:
	Shape(int _x, int _y, const Board& _board, bool colors);
	void move(int _x = 0, int _y = 1);
	void draw();
	void turn();
	bool checkFall(int _y = 1, bool toSet = true);
	int getShapeL();

private:
	void setShape();
	void initShape(int*** arrShape);
	void makeShapeO(int*** arrShape);
	void makeShapeL(int*** arr);
	void makeShapeS(int*** arr);
	void makeShapeI(int*** arr);
	void makeShapeT(int*** arr);
	void makeShapeJ(int*** arr);
	void makeShapeZ(int*** arr);
	void cleanDraw();

};