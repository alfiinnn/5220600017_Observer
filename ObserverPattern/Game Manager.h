#pragma once
#include <iostream>
#include <string>
#include"Player.h"
#include"Board3x3.h"

using namespace std;

class GameManager
{
	Player plyr1;
	Player plyr2;
	Board3x3 board;

	Player plyrWin;
	Player plyrTurn;
	int turnCount = 1;

	bool isWin = false;
	bool isDraw = false;

public:
	GameManager();

	void switchTurn();
	void makeMove();
	bool checkWinCondition();
	void newgame();
	void announcment();


};