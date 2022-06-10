#include "Game Manager.h"

using namespace std;

GameManager::GameManager()
{
	cout << endl;
	cout << "  Tictatoe game \n" << endl;
	cout << "  nama pemain 1 : ";
	plyr1.setName();
	plyr1.setPlayer('X');

	cout << "  Nama Pemain 2 : ";
	plyr2.setName();
	plyr2.setPlayer('X');

	plyrTurn = plyr1;

}

void GameManager::switchTurn()
{
	if (plyrTurn == plyr1)
	{
		plyrTurn = plyr2;
	}

	else if (plyrTurn == plyr2)
	{
		plyrTurn = plyr1;
	}

}

void GameManager::makeMove()
{
	int koordinatX, koordinatY;
	cout << "\n  ====================\n  " << plyrTurn.getName() << "'s turn";

	board.display();
	cout << "  Insert Koordinat : ";
	cin >> koordinatX;
	cin >> koordinatY;

	if (board.isLegal(koordinatX, koordinatY))
	{
		board.setValue(plyrTurn.getPlayer(), koordinatX, koordinatY);
		switchTurn();
	}

	else
	{
		cout << "  Move is Ilegal" << endl;
	}
}

bool GameManager::checkWinCondition()
{
	if (board.getDiagonal() || board.getHorizontal() || board.getVertical())
	{
		isWin = true;
		switchTurn();
		plyrWin = plyrTurn;
		board.display();
		return true;
	}
	else if (board.check_grid_full())
	{
		isDraw = true;
		return true;
	}
	else
	{
		return false;
	}
}


void GameManager::newgame()
{
	board.reset_game();
	if (!board.check_grid_valid())
	{
		cout << "  Error";
		exit;
	}
	else
	{
		isWin = false;
		isDraw = false;
	}
}

void GameManager::announcment()
{
	if (isWin)
	{

		plyr1.Updatestate(plyrWin);
		plyr2.Updatestate(plyrWin);

		cout << endl << "  Skor   : " << endl;
		cout << "  " << plyr1.getName() << ": " << plyr1.getTotalKemenangan() << endl;
		cout << "  " << plyr2.getName() << ": " << plyr2.getTotalKemenangan() << endl;
	}
	else if (isDraw)
	{
		cout << "  Seri" << endl;
	}
}