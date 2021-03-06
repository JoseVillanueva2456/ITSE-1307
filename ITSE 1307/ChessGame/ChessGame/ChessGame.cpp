/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: April 17 2018
 * Description: This program prints a chess board using functions.
 */

#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

const int INT_ROW = 8;
const int INT_COLUMN = 8;

// initializes the array
void fillArray(char arrGrid[][INT_COLUMN]) {

	for (int intRow = 0; intRow < INT_ROW; intRow++) {

		for (int intColumn = 0; intColumn < INT_COLUMN; intColumn++) {
			arrGrid[intRow][intColumn] = '*';
		}
	}
}

// sets the initial chess pieces
void setInitialPieces(char arrGrid[][INT_COLUMN]) {
	arrGrid[0][0] = 'R';
	arrGrid[0][1] = 'N';
	arrGrid[0][2] = 'B';
	arrGrid[0][3] = 'Q';
	arrGrid[0][4] = 'K';
	arrGrid[0][5] = 'B';
	arrGrid[0][6] = 'N';
	arrGrid[0][7] = 'R';

	arrGrid[7][0] = 'r';
	arrGrid[7][1] = 'n';
	arrGrid[7][2] = 'b';
	arrGrid[7][3] = 'q';
	arrGrid[7][4] = 'k';
	arrGrid[7][5] = 'b';
	arrGrid[7][6] = 'n';
	arrGrid[7][7] = 'r';

	// fill pawn
	for (int count = 0; count < INT_ROW; count++) {
		arrGrid[1][count] = 'P';
		arrGrid[6][count] = 'p';
	}
}

// prints output
void printArray(char arrGrid[][INT_COLUMN]) {

	for (int intRow = 0; intRow < INT_ROW; intRow++) {
		for (int intColumn = 0; intColumn < INT_COLUMN; intColumn++) {
			cout << arrGrid[intRow][intColumn];
		}
		cout << endl;
	}
}

int main()
{
	char arrChessGrid[INT_ROW][INT_COLUMN];

	fillArray(arrChessGrid);
	setInitialPieces(arrChessGrid);
	printArray(arrChessGrid);

    return 0;
}

