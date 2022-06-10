
#pragma once

class Board
{
public:
	virtual void display();
	virtual bool check_grid_valid();
	virtual bool check_grid_full();
	virtual void reset_game();
	virtual bool isLegal();

	virtual void setValue();
	virtual char getValue();


	virtual char getHorizontal();
	virtual char getDiagonal();
	virtual char getVertical();
};