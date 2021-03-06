/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: May 9 2018
 * Description: This is a working prototype of a Mao card game.
 *				TODO - implement number card logic.
 */

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Player.h"
using namespace std;

const int INTMAXDECKS = 3;
const int INTMAXPLAYERS = 6;
const int INTPLAYERHANDSIZE = 7;

// ----------------------------------------------------------------------------------------------------------------
// test methods
// ----------------------------------------------------------------------------------------------------------------

void testCard() {
	Card objCard(1);
	cout << "Card Testing" << endl;
	cout << objCard.getValue() << endl
		<< objCard.getFaceValue() << endl
		<< objCard.getFaceString() << endl
		<< objCard.getSuiteValue() << endl
		<< objCard.getSuiteString() << endl
		<< objCard.toString() << endl;
	objCard.setValue(45);
}

void testDeck() {
	Deck objDeck = Deck();
	cout << "Deck Testing" << endl;
	objDeck.printDeck();
	//Get cards until we reach the shuffle point you can also get cards until you reach NULL
	do {
		objDeck.getCard();
		cout << "Percentage: " << objDeck.getPercentOfDeckDealt() << endl;
	}
	while(!objDeck.shouldShuffle());
	if (objDeck.shouldShuffle()) {
		objDeck.shuffle();
	}
	objDeck.printDeck();
}

void testDiscardPile() {
	Deck objDeck = Deck(4);
	objDeck.shuffle();
	DiscardPile objDiscard = DiscardPile();
	Card objCardToDiscard = objDeck.getCard();
	cout << objCardToDiscard.toString() << endl;
	objDiscard.addCard(objCardToDiscard);
	cout << objDiscard.getTopCard().toString() << endl;
}

void testPlayer() {
	Player objPlayerOne = Player();
	Player objPlayerTwo = Player();
	Deck objDeck = Deck(4);
	DiscardPile objDiscard = DiscardPile();
	objDeck.shuffle();
	objPlayerOne.setBet(5);
	objPlayerTwo.setMoney(300);
	objPlayerTwo.setBet(400);
	for (int intCards = 0; intCards < 7; intCards++) {
		objPlayerOne.addCardToHand(objDeck.getCard());
		objPlayerTwo.addCardToHand(objDeck.getCard());
	}
	objPlayerOne.printHand();
	objPlayerOne.clearHand();
	objPlayerOne.printHand();
	cout << "-----" << endl;
	objPlayerTwo.printHand();
	//HINT: Logic for checking if player card can be added to discard.
	Card cardPlayerDiscard = objPlayerTwo.removeCardFromHand(0); //Remove card 1 NOTE: it's the index, index starts at zero
	if (objDiscard.checkValidCard(cardPlayerDiscard)) { //Check if it can be added to discard
		objDiscard.addCard(cardPlayerDiscard); //Add to discard
	}
	else { //Nope
		objPlayerTwo.addCardToHand(cardPlayerDiscard); //Add back to players hand.
	}
	objPlayerTwo.printHand();
	cout << "-----" << endl;
	objPlayerOne.wonBet();
	objPlayerOne.printHand();
	objPlayerTwo.lostBet();
	objPlayerTwo.printHand();
}

// ----------------------------------------------------------------------------------------------------------------
// game methods (my methods)
// ----------------------------------------------------------------------------------------------------------------

// promt user for amount of players
int getPlayerAmount(string message) {
	int intPlayerAmount = 0;

	do {
		cout << message << endl;
		cin >> intPlayerAmount;

	} while (intPlayerAmount < 2 || intPlayerAmount > 6);

	return intPlayerAmount;
}

// just gets the amount of decks to be used
int getDeckAmount(int numberOfPlayers) {

	if (numberOfPlayers <= 2) {
		// 1-2 players = 1 deck
		return 1;
	}
	else if (numberOfPlayers >= 5) {
		// 5-6 players = 3 decks
		return 3;
	}
	else {
		// 3-4 players = 2 decks
		return 2;
	}
}

// creates initial hands
void createFirstHands(Deck objDeck, int intNumberOfPlayers, Player arrPlayers[]) {
	objDeck.shuffle();

	for (int player = 0; player < intNumberOfPlayers; player++) {

		for (int intCards = 0; intCards < INTPLAYERHANDSIZE; intCards++) {
			arrPlayers[player].addCardToHand(objDeck.getCard());
		}
	}
}

// changes the turn
void changeTurn(int& intNumberOfPlayers, bool& bolMoveForward, int& intCurrentTurn) {

	// change turn forwards or backwards
	if (bolMoveForward == true) {
		if (intCurrentTurn != intNumberOfPlayers - 1) {
			// change turn
			cerr << "Change Turn 1" << endl;
			cerr << "Current turn: " << intCurrentTurn << endl;
			cerr << "numberOfPlayers: " << intNumberOfPlayers << endl;

			intCurrentTurn++;
		}
		else {
			// reset turns
			cerr << "Change Turn 2" << endl;
			intCurrentTurn = 0;
		}
	}
	else {
		if (intCurrentTurn != 0) {
			// change turn
			cerr << "Change Turn 3" << endl;
			intCurrentTurn--;
		}
		else {
			// reset turns
			cerr << "Change Turn 4" << endl;
			intCurrentTurn = intNumberOfPlayers - 1;
		}
	}

	cerr << "CHANGE TO PLAYER: " << intCurrentTurn + 1 << endl;
}

// gets the next player as an int (doesn't change player)
int getNextPlayer(bool& bolMoveForward, int& intCurrentTurn, int& intNumberOfPlayers) {

	if (bolMoveForward == true) {
		if (intCurrentTurn != intNumberOfPlayers - 1) {

			return intCurrentTurn + 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (intCurrentTurn != 0) {
			return intCurrentTurn - 1;
		}
		else {
			return intNumberOfPlayers - 1;
		}
	}
}

// gives a player a card from the deck
void penalisePlayer(Player arrPlayers[], Deck& objDeck, int& intPlayerToPenalise) {
	Card cardToGive;

	objDeck.shuffle();

	cardToGive = objDeck.getCard();

	arrPlayers[intPlayerToPenalise].addCardToHand(cardToGive);
}

// checks if at least one card in hand is playable
bool cardPlayable(Player arrPlayers[], DiscardPile& objDiscard, int& intCurrentTurn) {
	Card currentCard;
	int intHandMax = arrPlayers[intCurrentTurn].getNumberOfCards();

	for (int count = 0; count < intHandMax; count++) {
		currentCard = arrPlayers[intCurrentTurn].getCardFromHand(count);

		if (objDiscard.checkValidCard(currentCard)) { //Check if it can be added to discard
			if (currentCard.getFaceValue() == 2) {
				// A "2" is playable no matter what
				return true;
			}

			// true if one card is playable
			return true;
		}
	}

	// false if none are playable
	return false;
}

Card getCardPlay(Player arrPlayers[], DiscardPile& objDiscard, int& intCurrentTurn, Deck objDeck) {
	int intCardToPlay = 0;
	int intHandMax = arrPlayers[intCurrentTurn].getNumberOfCards();
	bool bolValidCard = false;
	Card currentCard;

	// checks if on card is playable
	if (cardPlayable(arrPlayers, objDiscard, intCurrentTurn) == true) {

		// checks if the card can added to discard
		do {

			// checks if card is in range
			do {
				cout << "(Play a card 1-" << intHandMax << ")" << endl;
				cin >> intCardToPlay;

			} while (intCardToPlay < 1 || intCardToPlay > intHandMax);

			currentCard = arrPlayers[intCurrentTurn].getCardFromHand(intCardToPlay - 1);

			// check if it can be added to discard, a number "2" is an exception
			if (objDiscard.checkValidCard(currentCard) || currentCard.getFaceValue() == 2) {
				// remove from hand
				currentCard = arrPlayers[intCurrentTurn].removeCardFromHand(intCardToPlay - 1); 
				objDiscard.addCard(currentCard); //Add to discard
				bolValidCard = true;
			}
			else {
				// not valid
				cout << "\nInvalid play" << endl;
				// cerr << objDiscard.getTopCard().toString() << endl;
				arrPlayers[intCurrentTurn].printHand();
				bolValidCard = false;
			}
		} while (bolValidCard == false);
	}
	else {
		// no card can be played, draw card(penalise)
		cout << "\nNo playable card" << endl;
		penalisePlayer(arrPlayers, objDeck, intCurrentTurn);
	}
	
	return currentCard;
}

void acePlay(bool& bolMoveForward, int& intCurrentTurn, int& intNumberOfPlayers) {
	// skip next players turn (opposite of change turn)

	cerr << "\nACE PLAY" << endl;

	if (bolMoveForward == true) {

		// if "0", minus, else set to max
		if (intCurrentTurn != 0) {
			intCurrentTurn--;
		}
		else {
			intCurrentTurn = intNumberOfPlayers - 1;
		}
	}
	else {

		// if not max, plus, else, set to "0" 
		if (intCurrentTurn != intNumberOfPlayers - 1) {
			intCurrentTurn++;
		}
		else {
			intCurrentTurn = 0;
		}
	}
}

void jackPlay(Player arrPlayers[], Deck& objDeck, int& intCurrentTurn, bool& moveForward, int& numberOfPlayers) {
	// jack
	// gives next player a card (penalise next player)
	int intNextPlayer = getNextPlayer(moveForward, intCurrentTurn, numberOfPlayers);
	Card cardToGive = objDeck.getCard();

	penalisePlayer(arrPlayers, objDeck, intNextPlayer);

	cerr << "\nJACK PLAY" << endl;
}

void queenPlay(Player arrPlayers[], Deck& objDeck, int& intCurrentTurn) {
	// queen
	// say "Hail to the chairwoman"
	string strInput = "";
	cout << "\nHail to the chair..... (complete this)" << endl;
	cin >> strInput;

	if (strInput == "woman") {
		// do nothing
	}
	else {
		// penalise player if wrong
		penalisePlayer(arrPlayers, objDeck, intCurrentTurn);
	}

	cerr << "\nQUEEN PLAY" << endl;
}

void kingPlay(Player arrPlayers[], Deck& objDeck, int& intCurrentTurn) {
	// queen
	// say "Hail to the chairman"
	string strInput = "";
	cout << "\nHail to the chair... (complete this)" << endl;
	cin >> strInput;

	if (strInput == "man") {
		// do nothing
	}
	else {
		// penalise player if wrong
		penalisePlayer(arrPlayers, objDeck, intCurrentTurn);
	}

	cerr << "\nKing PLAY" << endl;
}

void numberCardThree() {
	// 3 - penalise next player
}

void numberCardFour() {
	// 4 - give next player one of your cards
}

void numberCardFive() {
	// 5 - say "High five"
}

void numberCardSix() {
	// 6 - discard 1 card (discard rules don't apply)
}

void numberCardSeven() {
	// 7 - penalise current player (add 1 card to hand)
}

void numberCardEight() {
	// 8 - switch play rotation 
}

void numberCardNine() {
	// 9 - say the symbol of card
}

// this menu calls the method corresponding with the number card given
void numberMenu(Player arrPlayers[], Deck& objDeck, int& intCurrentTurn, Card& objCurrentCard, DiscardPile& objDiscard, bool& bolMoveForward, int& intNumberOfPlayers) {
	int intCardValue = objCurrentCard.getFaceValue();

	// 2 - can play no matter what (ignores discard rules)

	if (intCardValue == 3) {
		numberCardThree();
	}
	else if (intCardValue == 4) {
		numberCardFour();
	}
	else if (intCardValue == 5) {
		numberCardFive();
	}
	else if (intCardValue == 6) {
		numberCardSix();
	}
	else if (intCardValue == 7) {
		numberCardSeven();
	}
	else if (intCardValue == 8) {
		numberCardEight();
	}
	else {
		numberCardNine();
	}
}

// redirects to different methods based on current played card
void cardMenu(Player arrPlayers[], Deck& objDeck, int& intCurrentTurn, Card& objCurrentCard, DiscardPile& objDiscard, bool& bolMoveForward, int& intNumberOfPlayers) {
	int intCardFaceValue = objCurrentCard.getValue();

	// runs needed methods and passes needed parameters
	if (intCardFaceValue == 1 || intCardFaceValue == 14 
		|| intCardFaceValue == 27 || intCardFaceValue == 40) {

		// ace
		acePlay(bolMoveForward, intCurrentTurn, intNumberOfPlayers);
	}
	else if (intCardFaceValue == 11 || intCardFaceValue == 24
		|| intCardFaceValue == 37 || intCardFaceValue == 50) {

		// jack
		jackPlay(arrPlayers, objDeck, intCurrentTurn, bolMoveForward, intNumberOfPlayers);
	}
	else if (intCardFaceValue == 12 || intCardFaceValue == 25
		|| intCardFaceValue == 38 || intCardFaceValue == 51) {

		// queen
		queenPlay(arrPlayers, objDeck, intCurrentTurn);
	}
	else if (intCardFaceValue == 13 || intCardFaceValue == 26
		|| intCardFaceValue == 39 || intCardFaceValue == 52) {

		// king
		kingPlay(arrPlayers, objDeck, intCurrentTurn);
	}
	else {
		// number cards (redirects to another menu, so send all parameters aswell)
		numberMenu(arrPlayers, objDeck, intCurrentTurn, objCurrentCard, objDiscard, bolMoveForward, intNumberOfPlayers);
	}
}

void lostBets(Player arrPlayers[], int numberOfPlayers, int intCurrentTurn) {

	// all players, except the winner, lose money
	for (int player = 0; player < numberOfPlayers; player++) {

		if (player != intCurrentTurn) {
			arrPlayers[player].lostBet();
		}
	}
}

// updates player amount that still have money
void checkRemaingPlayers(Player arrPlayers[], int& intNumberOfPlayers) {
	int intCurrentPlayerCount = intNumberOfPlayers;

	// check through all players
	for (int player = 0; player < intCurrentPlayerCount; player++) {
		// cerr << "\nPLAYER CHECK: " << player << endl;

		if (arrPlayers[player].getMoney() == 0) {

			// cerr << "\nPLAYER CHECK" << endl;
			intNumberOfPlayers--;
		}
	}

	cerr << "\nREMAINING PLAYERS: " << intNumberOfPlayers << endl;
}

// checks if current player is a winner
bool checkWinner(Player arrPlayers[], int& intCurrentTurn) {

	if (arrPlayers[intCurrentTurn].getNumberOfCards() == 0) {
		return true;
	}
	else {
		return false;
	}
}

void playerLost(Player arrPlayers[], int intNumberOfPlayers) {

	for (int player = 0; player < intNumberOfPlayers - 1; player++) {

		if (arrPlayers[player].getMoney() == 0) {
			cout << "Player " << player + 1 << " can no longer play" << endl;
		}
	}
}

// gets the bets of any remaining players (works for initial bets too)
void getBets(Player arrPlayers[], int intNumberOfPlayers) {

	for (int player = 0; player < intNumberOfPlayers; player++) {

		if (arrPlayers[player].getMoney() != 0) {
			
			cout << "Player " << player + 1 << endl;
			arrPlayers[player].inputBet();
		}
	}
}

void resetGame(Player arrPlayers[], Deck& objDeck, int& intCurrentTurn, DiscardPile& objDiscard, bool& bolMoveForward, int& intNumberOfPlayers, int intInitialPlayers) {
	// change turn
	changeTurn(intNumberOfPlayers, bolMoveForward, intCurrentTurn);

	// reset deck (new deck)
	objDeck = Deck();

	// reset discard (new discard pile)
	objDiscard = DiscardPile();

	// empty hands
	for (int player = 0; player < intInitialPlayers; player++) {
		arrPlayers[player].clearHand();
	}

	// get new hands
	createFirstHands(objDeck, intNumberOfPlayers, arrPlayers);

	// announce new game and game winner
	cout << "\nGAME WON BY PLAYER " << intCurrentTurn << endl;

	// get new bets
	getBets(arrPlayers, intNumberOfPlayers);
}

int main()
{
	srand(time(0)); //Setup the randomness at the beginning of the program

	int intNumberOfPlayers = 0;
	int intInitialPlayers = 0;
	int intNumberOfDecks = 0;
	int intCurrentTurn = 0;
	int intRemainingPlayers = 0;
	bool bolMoveForward = true;

	Player arrPlayers[INTMAXPLAYERS];
	DiscardPile objDiscard = DiscardPile();
	Deck objDeck;

	// Uncomment to see different ways to use the different classes.
	// testCard();
	// testDeck();
	// testDiscardPile();
	// testPlayer();

	//objDeck.printDeck();
	/*
	Card testCard;
	for (int count = 1; count < 53; count++) {
		testCard = Card(count);
		cout << testCard.toString() << " Count: " << count << endl;
		cout << "Face Value: " << testCard.getFaceValue() << endl;
	}
	*/

	// get player amount
	intNumberOfPlayers = getPlayerAmount("Enter player amount (2-6)");
	intNumberOfDecks = getDeckAmount(intNumberOfPlayers);

	// deck is shuffled in CreateFirstHands()
	objDeck = Deck(intNumberOfDecks);

	createFirstHands(objDeck, intNumberOfPlayers, arrPlayers);

	// get initial bets
	getBets(arrPlayers, intNumberOfPlayers);

	cerr << "\n";
	
	do {

		cerr << "DEBUG: " << arrPlayers[intCurrentTurn].getPlayerNumber() << endl;

		// if the current player lost, change turn
		// TODO - IMPLEMENT THIS IS CHANGE TURN METHOD
		if (arrPlayers[intCurrentTurn].getMoney() == 0) {
			cerr << "First change turn ran" << endl;
			changeTurn(intNumberOfPlayers, bolMoveForward, intCurrentTurn);
		}

		// print the current player's hand 
		arrPlayers[intCurrentTurn].printHand();

		// prompt for card (play)
		Card objCurrentCard = Card(getCardPlay(arrPlayers, objDiscard, intCurrentTurn, objDeck));

		// run menu with all variables
		cardMenu(arrPlayers, objDeck, intCurrentTurn, objCurrentCard, objDiscard, bolMoveForward, intNumberOfPlayers);

		// check if current player is a winner
		if(checkWinner(arrPlayers, intCurrentTurn) == true) {

			// winner wins double thier bet
			arrPlayers[intCurrentTurn].wonBet();

			// losers lose money
			lostBets(arrPlayers, intNumberOfPlayers, intCurrentTurn);

			// print disqualified player(s)
			playerLost(arrPlayers, intNumberOfPlayers);

			// check remaining players
			checkRemaingPlayers(arrPlayers, intNumberOfPlayers);

			// reset the game
			if (intNumberOfPlayers != 1) {

				// reset game only if there is more than one player left
				resetGame(arrPlayers, objDeck, intCurrentTurn, objDiscard, bolMoveForward, intNumberOfPlayers, intInitialPlayers);
			}


		}
		else {

			// change the turn
			changeTurn(intNumberOfPlayers, bolMoveForward, intCurrentTurn);
		}

		// TESETING
		// changeTurn(intNumberOfPlayers, bolMoveForward, intCurrentTurn);
		cerr << "\n";

	} while (intNumberOfPlayers != 1);

	// game is over when only one player remains
	cout << endl << "GAME OVER" << endl;
	cout << "Player " << intCurrentTurn + 1 << " is the only remaining player" << endl;

    return 0;
}