/*
* Name: Jose Villanueva
* Teacher: Christopher MacDougald
* Section: ITSE 1307-001
* Date: April 17 2018
* Description: This is a simple seat reservation program for a plane.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int INT_ROW = 12;
const int INT_COLUMN = 6;

// initializes the array
void fillArray(char arrGrid[][INT_COLUMN]) {

	for (int intRow = 0; intRow < INT_ROW; intRow++) {

		for (int intColumn = 0; intColumn < INT_COLUMN; intColumn++) {
			arrGrid[intRow][intColumn] = '-';
		}
	}
}

// fills a seat
void fillSeat(char arrGrid[][INT_COLUMN], int intColumn, int intRow) {
	int intNewRow = intRow - 1;
	int intNewColumn = intColumn - 1;
	// subtract one from user for correct array indexing

	arrGrid[intNewRow][intNewColumn] = 'x';
}

// prints output
void printArray(char arrGrid[][INT_COLUMN]) {

	for (int intRow = 0; intRow < INT_ROW; intRow++) {

		// formatted output 
		cout << "Row " << setw(2) << setfill(' ') << (intRow + 1) << ": ";

		for (int intColumn = 0; intColumn < INT_COLUMN; intColumn++) {
			cout << arrGrid[intRow][intColumn];
		}
		cout << endl;
	}
}

// gets the row from user
int getRow() {
	int intRow = 0;

	do {
		cout << "Enter row to be filled (max 12)" << endl;
		cin >> intRow;
	} while (intRow < 1 || intRow > 12);

	return intRow;
}

// gets the column from user
int getColumn() {
	int intColumn = 0;

	do {
		cout << "Enter Column to be filled (max 6)" << endl;
		cin >> intColumn;
	} while (intColumn < 1 || intColumn > 6);

	return intColumn;
}

int main() {
	char chrLetter = 'Y';

	char arrGrid[INT_ROW][INT_COLUMN];

	// fill the array first
	fillArray(arrGrid);

	do {
		cout << "Do you wish to fill a seat?" << endl;
		cout << "('y' for yes, 'n' for no)" << endl;
		cin >> chrLetter;

		// change to uppercase for user
		chrLetter = toupper(chrLetter);

		if (chrLetter == 'Y') {
			// if yes, fill seat
			fillSeat(arrGrid, getColumn(), getRow());
		}
		else if (chrLetter != 'N') {
			// other than 'N' is invalid
			cerr << "Invalid input" << endl;
		}
		cout << endl;

		// loop only ends with input of 'N'
	} while (chrLetter != 'N');

	// after filling requested seat(s), print the output
	printArray(arrGrid);

	return 0;
}