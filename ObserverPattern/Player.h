#pragma once
#include<iostream>
#include <string>

using namespace std;

class Player
{
	char mark;
	string name;
	int totalkemenangan;

public:
	Player();

	void setName();
	string getName();
	void setPlayer(char);
	char getPlayer();
	void Updatestate(Player);

	void setTotalKemenangan(int);
	int getTotalKemenangan();

	bool operator==(Player);

};