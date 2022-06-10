#include<iostream>
#include "Board.h"
#include "Board3x3.h"
#include "Player.h"
#include "Game Manager.h"

using namespace std;

int main()
{
	GameManager gameTictactoe;
	char ulang;
	bool gameState = true;
	while (gameState)
	{
		gameTictactoe.makeMove();
		if (gameTictactoe.checkWinCondition())
		{
			gameTictactoe.announcment();
			cout << endl << "  ====================\n  Apakah anda ingin bermain lagi? (y/n)";
			cin >> ulang;
			if (ulang == 'y')
			{
				gameTictactoe.newgame();
			}
			else
			{
				cout << endl << " Sampai Jumpa";
				break;
			}
		}
	}

	return 0;
}