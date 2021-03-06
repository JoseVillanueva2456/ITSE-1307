/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: March 29 2018
 * Description: This program converts from 12 hour notation to 24 hour notation and
 *				vice versa. It also includes a menu to chose between conversions.
 */

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int getMenuChoice();
int timeMenu(int menuChoice);
int convertNotationOne(char suffix, int minutes, int hour);
char getNotationSuffix();
int getNotationOneHour();
int getNotationOneMinutes();
int convertNotationTwo(int minutes, int hour);
int getNotationTwoHour();
int getNotationTwoMinutes();

int main() {
	// run basically everything
	timeMenu(getMenuChoice());

	return 0;
}

int getMenuChoice() {
	// prompt user to enter conversion method
	int intChoice = 0;

	do {
		cout << "Enter \"1\" to convert from 12 hour notation to 24 hour notation"
			<< endl;
		cout
			<< "or enter \"2\" to convert from 24 hour notation to 12 hour notation"
			<< endl;
		cin >> intChoice;

		// can only be 1 or 2
	} while (intChoice < 1 || intChoice > 2);

	return intChoice;
}

int timeMenu(int menuChoice) {
	// holds a switch statement to controll conversion options

	switch (menuChoice) {
	case 1:
		// convert 12 hour to 24 hour
		convertNotationOne(getNotationSuffix(), getNotationOneMinutes(),
			getNotationOneHour());
		break;
	case 2:
		// convert 24 hour to 12 hour
		convertNotationTwo(getNotationTwoMinutes(), getNotationTwoHour());
		break;
	default:
		cerr << "Error" << endl;
	}

	return 0;
}

//-------------------------------------------------------------------------------------------
// 12 to 24 notation conversion fuctions
//-------------------------------------------------------------------------------------------

int convertNotationOne(char suffix, int minutes, int hour) {
	char chrSuffix = suffix;
	int intHour = hour;
	int intMinutes = minutes;

	// cout << "Suffix: " << chrSuffix << " Hour: " << intHour << " Minute: " <<
	// intMinutes << endl;

	if (chrSuffix == 'A') {
		// format for four number output "0000"
		cout << "Converted to 24 hour Notation: " 
			<< setfill('0') << setw(2) << intHour 
			<< setfill('0') << setw(2) << intMinutes << endl;
	}
	else {
		// else pm then, hour = hour + 12
		intHour = intHour + 12;

		// format for four number output "0000"
		cout << "Converted to 24 hour Notation: " << intHour 
			<< setfill('0') << setw(2) << intMinutes << endl;
	}

	return 0;
}

char getNotationSuffix() {
	// gets am or pm for notation one conversion
	char chrSuffix = ' ';

	do {
		cout << "Enter \"A\" for AM or \"P\" for PM" << endl;
		cin >> chrSuffix;

		// convert to uppercase for user convenience
		chrSuffix = toupper(chrSuffix);

		// repeat untill suffix = 'A' or 'P'
	} while (chrSuffix != 'A' && chrSuffix != 'P');

	return chrSuffix;
}

int getNotationOneHour() {
	// gets hours for NotationOne conversion
	int intHour = 0;

	do {
		cout << "Please enter hour (1-12 hours)" << endl;
		cin >> intHour;

		// repeat untill hour is between 1 and 12
	} while (intHour < 1 || intHour > 12);

	return intHour;
}

int getNotationOneMinutes() {
	// gets minutes for notation on conversion
	int intMinutes = 0;

	do {
		cout << "Please enter minutes" << endl;
		cin >> intMinutes;

		// repeat until minutes is between 1 and 59
	} while (intMinutes < 1 || intMinutes > 59);

	return intMinutes;
}

//-------------------------------------------------------------------------------------------
// 24 to 12 notation conversion function
//-------------------------------------------------------------------------------------------

int convertNotationTwo(int minutes, int hour) {
	int intHour = hour;
	int intMinutes = minutes;

	if (intHour <= 12) {
		cout << "Converted to 12 hour Notation : " << intHour << ":"
			<< setfill('0') << setw(2) << intMinutes << "AM" << endl;
	}
	else {
		// else take off 12 hours for PM standard
		intHour = intHour - 12;
		cout << "Converted to 12 hour Notation : " << intHour << ":"
			<< setfill('0') << setw(2) << intMinutes << "PM" << endl;
	}

	return 0;
}

int getNotationTwoHour() {
	int intHour = 0;

	do {
		cout << "Please enter first halve of the 24 hour notation (\"00\"00 hour portion)" << endl;
		cin >> intHour;

		// repeat untill between 1 and 24
	} while (intHour < 1 || intHour > 24);

	return  intHour;
}

int getNotationTwoMinutes() {
	int intMinutes = 0;

	do {
		cout << "Please enter second halve of the 24 hour notation (00\"00\" minutes portion)" << endl;
		cin >> intMinutes;

		// repeat untill between 1 and 59
	} while (intMinutes < 1 || intMinutes > 59);

	return  intMinutes;
}