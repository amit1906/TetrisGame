#pragma once
#include "Utils.h"
#include "Board.h"

static int colori = 1;
constexpr int MAX_BLOCK = 8;

class Shape
{
public:
	enum MOVE_DIR { NONE, LEFT, RIGHT, ROTATEL, ROTATER, DROP };
	enum TURN_DIR { TURN_LEFT = -1, TURN_RIGHT = 1 };

private:
	enum SHAPE { O, I, L, J, T, S, Z };
	enum SHAPE_T { T1, T2, T3, T4 };
	SHAPE_T shape_t;
	COLOR color;

protected:
	Board& board;
	SHAPE shape;
	int arrShape[MAX_BLOCK][MAX_BLOCK]{};
	int shapeL, shapeH;
	int x, y;

public:
	Shape(int _x, int _y, Board& _board, bool colors);
	Shape(const Shape& _shape, Board& _board);
	virtual ~Shape() = default;
	void SetBoard(const Board& b);
	void move(MOVE_DIR dir = NONE);
	void turn(TURN_DIR dir, bool toDraw = true);
	virtual bool checkFall(int _y = 1, bool toSet = true);
	int makeFall(bool toSet);
	int getShapeH() const;
	int getShapeL() const;
	int getX() const;
	int getY() const;
	void setY(int _y = 0);
	void setX(int _x = 1);
	void unSetShape();
	int getShape();
	void draw();

private:
	void initShape(SHAPE_T t = T1);
	void setShape();
	void clearShape();
	bool isValidTurn();
	void cleanDraw();
	void turnDigree();
	void getDirection(MOVE_DIR dir, int& _x, int& _y);

	void makeShapeO();		// shape O
	void makeShapeI1();		// shape I
	void makeShapeI2();
	void makeShapeL1();		// shape L	// turn 1
	void makeShapeL2();					// turn 2
	void makeShapeL3();					// turn 3
	void makeShapeL4();					// turn 4	etc...
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