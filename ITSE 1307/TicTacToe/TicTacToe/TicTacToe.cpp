/*
* Name: Jose Villanueva
* Teacher: Christopher MacDougald
* Section: ITSE 1307-001
* Date: May 2 2018
* Description: This is a simple tic tac toe game.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int INT_ROW = 3;
const int INT_COLUMN = 3;

// initializes the array
void fillArray(char arrGrid[][INT_COLUMN]) {

	for (int intRow = 0; intRow < INT_ROW; intRow++) {

		for (int intColumn = 0; intColumn < INT_COLUMN; intColumn++) {
			arrGrid[intRow][intColumn] = '-';
		}
	}
}

// fills a spot
void fillBoard(char arrGrid[][INT_COLUMN], int intColumn, int intRow, char chrPlayer) {

	// subtract one from user for correct array indexing
	int intNewRow = intRow - 1;
	int intNewColumn = intColumn - 1;

	// ignore repeats
	if (arrGrid[intNewRow][intNewColumn] == '-') {
		arrGrid[intNewRow][intNewColumn] = chrPlayer;
	}
}

// prints output
void printBoard(char arrGrid[][INT_COLUMN]) {

	// for spacial reasons
	cout << endl;

	for (int intRow = 0; intRow < INT_ROW; intRow++) {

		// formatted output 
		cout << "Row " << setw(2) << setfill(' ') << (intRow + 1) << ": ";

		for (int intColumn = 0; intColumn < INT_COLUMN; intColumn++) {
			cout << arrGrid[intRow][intColumn];
		}
		cout << endl;
	}
	cout << endl;
}

// gets the row from user
int getRow() {
	int intRow = 0;

	do {
		cout << "Enter row to be played (1-3)" << endl;
		cin >> intRow;
	} while (intRow < 1 || intRow > 3);

	return intRow;
}

// gets the column from user
int getColumn() {
	int intColumn = 0;

	do {
		cout << "Enter Column to be played (1-3)" << endl;
		cin >> intColumn;
	} while (intColumn < 1 || intColumn > 3);

	return intColumn;
}

bool fullBoard(char arrGrid[][INT_COLUMN]) {
	int intFull = 0;

	// this checks if there is a full board
	for (int intRow = 0; intRow < INT_ROW; intRow++) {
		for (int intColumn = 0; intColumn < INT_COLUMN; intColumn++) {
			if (arrGrid[intRow][intColumn] != '-') {
				intFull++;
			}
		}
	}

	if (intFull == 9) {
		return true;
	}
	else {
		return false;
	}
}

bool checkWinner(char arrGrid[][INT_COLUMN], char chrPlayer) {
	int intWin = 0;

	// checks by row
	for (int intRow = 0; intRow < INT_ROW; intRow++) {

		for (int intColumn = 0; intColumn < INT_COLUMN; intColumn++) {

			if (arrGrid[intRow][intColumn] == chrPlayer) {
				intWin++;
			}
		}

		if (intWin == 3) {
			//cerr << "Win by Row" << endl;
			return true;
		}
		else {
			intWin = 0;
		}
	}

	// checks by column
	for (int intColumn = 0; intColumn < INT_COLUMN; intColumn++) {

		for (int intRow = 0; intRow < INT_ROW; intRow++) {
			if (arrGrid[intRow][intColumn] == chrPlayer) {
				intWin++;
			}
		}

		if (intWin == 3) {
			//cerr << "Win by Column" << endl;
			return true;
		}
		else {
			intWin = 0;
		}
	}

	// up/down diagnal checking (both row and column increment)
	for (int intCount = 0; intCount < 3; intCount++) {
		if (arrGrid[intCount][intCount] == chrPlayer) {
			intWin++;
		}
		else {
			intWin = 0;
		}

		if (intWin == 3) {
			//cerr << "Win by up/down diagnal" << endl;
			return true;
		}
	}

	// down/up diagnal checking (row decrements & column increments at the same time)
	for (int intRow = 2, intColumn = 0; intRow > -1, intColumn < 3; intRow--, intColumn++) {

		if (arrGrid[intRow][intColumn] == chrPlayer) {
			intWin++;
		}
		else {
			intWin = 0;
		}

		if (intWin == 3) {
			//cerr << "Win by down/up diagnal" << endl;
			return true;
		}
	}

	return false;
}

char changePlayer(char chrPlayer) {

	// change the letter
	if (chrPlayer == 'X') {
		return 'O';
	}
	else {
		return 'X';
	}
}

bool checkRepeat(char arrGrid[][INT_COLUMN], int intRow, int intColumn) {

	// subtract one from user for correct array indexing
	int intSelectedRow = intRow - 1;
	int intSelectedColumn = intColumn - 1;

	// repeat is true if current selection is not equal to '-'
	if (arrGrid[intSelectedRow][intSelectedColumn] != '-') {
		return true;
	}
	else {
		return false;
	}
}

bool endGame(bool bolWinnerExist, char arrGrid[][INT_COLUMN]) {

	if (bolWinnerExist == true) {
		// stop loop if winner exists
		return true;
	}
	else if (fullBoard(arrGrid)) {
		// stop loop if board is full
		return true;
	}
	else {
		return false;
	}
}

int main() {
	char arrGrid[INT_ROW][INT_COLUMN];
	bool bolWinnerExists = false;
	bool bolEndGame = false;
	char chrPlayer = 'X';
	int currentRow = 0;
	int currentColumn = 0;
	bool bolRepeatExists = false;

	// fill the array first
	fillArray(arrGrid);

	do {
		cout << "Player " << chrPlayer << " turn" << endl;

		// get player input (data stored for use in other variables)
		currentRow = getRow();
		currentColumn = getColumn();

		// check for a repeat
		bolRepeatExists = checkRepeat(arrGrid, currentRow, currentColumn);

		// fill board with player input and print (repeats wont show)
		fillBoard(arrGrid, currentColumn, currentRow, chrPlayer);
		printBoard(arrGrid);

		// check if there is a winner
		bolWinnerExists = checkWinner(arrGrid, chrPlayer);

		// check to end the game
		bolEndGame = endGame(bolWinnerExists, arrGrid);

		// change player only if there is no winner and no repeat
		if (bolWinnerExists == false && bolRepeatExists == false) {
			chrPlayer = changePlayer(chrPlayer);
		}

	} while (bolEndGame == false);

	// print the results
	if (bolWinnerExists == true) {
		// player won
		cout << "Player " << chrPlayer << " Won!" << endl;
	}
	else {
		// there is a full board with no winners
		cout << "Tie!" << endl;
	}

	return 0;
}