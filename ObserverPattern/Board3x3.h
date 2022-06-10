#pragma once
#include "Board.h"
#include <iostream>

class Board3x3 : public Board
{
	char board[3][3];
	char winvalue;

public:
	Board3x3();

	void display();
	bool check_grid_valid();
	bool check_grid_full();
	void reset_game();
	bool isLegal(int, int);

	void setValue(int, int, char);
	char getValue(int, int);
	char getwinvalue();

	char getHorizontal();
	char getDiagonal();
	char getVertical();


};