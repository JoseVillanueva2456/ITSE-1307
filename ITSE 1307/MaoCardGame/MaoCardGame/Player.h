#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Card.h"

class Player
{
public:
	Player();
	~Player();
	void clearHand();
	int getNumberOfCards();
	Card removeCardFromHand(int intCardIndex);
	Card getCardFromHand(int intCardIndex);
	void addCardToHand(Card cardAdding);
	int getBet();
	int getPlayerNumber();
	void inputBet();
	void setBet(int intBet);
	void printHand();
	void wonBet();
	void lostBet();
	void setMoney(int intMoney);
	int getMoney();

private:
	int intPlayerNumber;
	int intBet;
	std::vector <Card> vtrHand;
	int intMoney;

};

