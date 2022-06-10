#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player()
{
	totalkemenangan = 0;
}

void Player::setName()
{
	cin >> this->name;
}

string Player::getName()
{
	return this->name;
}

void Player::setPlayer(char mark)
{
	this->mark = mark;
}

char Player::getPlayer()
{
	return mark;
}

void Player::Updatestate(Player totalkemenangan)
{
	if (totalkemenangan.getName() == name)
	{
		cout << "\n  SELAMAT " << name << ", Kamu menang" << endl;
		setTotalKemenangan(1);
	}
	else if (totalkemenangan.getName() != name)
		cout << "  Nice Try " << name << ", hahah" << endl;
}

void Player::setTotalKemenangan(int score)
{
	totalkemenangan = totalkemenangan + score;
}

int Player::getTotalKemenangan()
{
	return totalkemenangan;
}

bool Player::operator==(Player x)
{
	if (this->name == x.name)
	{
		return true;
	}

	else
	{
		return false;
	}
}