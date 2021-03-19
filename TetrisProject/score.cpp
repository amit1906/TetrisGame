#include "score.h"

void printScores(int pos1, int pos2, int height)
{
	gotoxy(pos1 + 2, height + 2);
	cout << "player 1";
	gotoxy(pos2 + 3, height + 2);
	cout << "player 2";
	printScores();
}

void printScores()
{
	gotoxy(80, 4);
	cout << "player 1: " << 0;
	gotoxy(80, 5);
	cout << "player 2: " << 0;
	gotoxy(80, 2);
	cout << "scores:";
}