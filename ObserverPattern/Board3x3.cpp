#include "Board3x3.h"
#include <iostream>

using namespace std;

Board3x3::Board3x3()
{
	this->reset_game();
}


void Board3x3::display()
{
	cout << endl << "      [0] [1] [2]";
	cout << endl << "  [0] | " << getValue(0, 0) << " |" << "| " << getValue(0, 1) << " |" << "| " << getValue(0, 2) << " ||";
	cout << endl << "  [1] | " << getValue(1, 0) << " |" << "| " << getValue(1, 1) << " |" << "| " << getValue(1, 2) << " ||";
	cout << endl << "  [2] | " << getValue(2, 0) << " |" << "| " << getValue(2, 1) << " |" << "| " << getValue(2, 2) << " ||";
	cout << endl;
}


bool Board3x3::check_grid_valid()
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != ' ')
				count++;
		}
	}

	if (count >= 1)
		return false;
	else
		return true;
}

bool Board3x3::check_grid_full()
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
				count++;
		}
	}

	if (count >= 1)
		return false;
	else
		return true;
}

void Board3x3::reset_game()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '0';
		}
	}

}

bool Board3x3::isLegal(int x, int y)
{
	if (board[x][y] == ' ')
		return true;
	else
		return false;
}


void Board3x3::setValue(int x, int y, char value)
{
	board[x][y] = value;
}

char Board3x3::getValue(int x, int y)
{
	char temp;
	temp = board[x][y];

	return temp;
}

char Board3x3::getwinvalue()
{
	return winvalue;
}


char Board3x3::getHorizontal()
{
	bool retval = false;
	for (int i = 0; i < 3; i++)
	{
		if (getValue(i, 0) == getValue(i, 1) && getValue(i, 0) == getValue(i, 2))
		{
			winvalue = getValue(i, 0);
			if (winvalue != ' ')
			{
				retval = true;
			}
		}
	}

	return retval;
}

char Board3x3::getDiagonal()
{
	bool retval = false;

	if (getValue(0, 0) == getValue(1, 1) && getValue(0, 0) == getValue(2, 2))
	{
		winvalue = getValue(0, 0);
		if (winvalue != ' ')
		{
			retval = true;
		}
	}

	if (getValue(0, 2) == getValue(1, 1) && getValue(0, 2) == getValue(2, 0))
	{
		winvalue = getValue(0, 2);
		if (winvalue != ' ')
		{
			retval = true;
		}
	}


	return retval;
}


char Board3x3::getVertical()
{
	bool retval = false;
	for (int i = 0; i < 3; i++)
	{
		if (getValue(1, i) == getValue(2, i) && getValue(0, i) == getValue(2, i))
		{
			winvalue = getValue(1, i);
			if (winvalue != ' ')
			{
				retval = true;
			}
		}
	}

	return retval;
}
