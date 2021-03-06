/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: April 17 2018
 * Description: This program converts from 12 hour notation to 24 hour notation and
 *				vice versa. It also includes a menu to chose between conversions.
 */

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int getTotalMinutes(int intHours, int intMinutes) {
	return (intHours * 60) + intMinutes;
}

int getHours(int intTotalMinutes) {
	return intTotalMinutes / 60;
}

int getMinutes(int intTotalMinutes) {
	return intTotalMinutes % 60;
}

int getIntInput(string strMessage, int intMin, int intMax) {
	int intNumber = 0;

	do {
		cout << strMessage << endl;
		cin >> intNumber;

	} while (intNumber < intMin || intNumber > intMax);
	return intNumber;
}

void printTime(int intTotalMinutes, int intFormat12Or24) {
	if (intFormat12Or24 == 12) {
		int intHours = getHours(intTotalMinutes);
		if (intHours == 0) {
			intHours = 12;
		}
		else if (intHours >= 13) {
			intHours -= 12;
		}

		cout << setw(2) << intHours
			<< ":"
			<< setw(2) << setfill('0') << getMinutes(intTotalMinutes)
			<< (getHours(intTotalMinutes) >= 12 ? " PM" : " AM")
			<< endl;
	}
	else {
		cout << setw(2) << setfill('0') << getHours(intTotalMinutes)
			<< ":"
			<< setw(2) << setfill('0') << getMinutes(intTotalMinutes) << endl;
	}
}

int getMenuChoice() {
	int intMenuChoice = 0;
	do {
		cout << "Please enter '12' to convert to 12 hour notation" 
			"\n or enter '24' to convert to 24 hour notation" << endl;
		cin >> intMenuChoice;

	} while (intMenuChoice != 12 && intMenuChoice != 24);
	return intMenuChoice;
}

void menu(int intMenuChoice) {
	int intTotalMinutes = 0;
	int intMinutes = 0;
	int intHours = 0;

	switch (intMenuChoice) {
		case 12:
			intHours = getIntInput("Please enter hours (1-24)", 1, 24);
			intMinutes = getIntInput("Please enter minutes (0-59)", 0, 59);

			intTotalMinutes = getTotalMinutes(intHours, intMinutes);

			printTime(intTotalMinutes, 12);
			break;
		case 24:
			intHours = getIntInput("Please enter hours (0-24)", 0, 24);
			intMinutes = getIntInput("Please enter minutes (0-59)", 0, 59);

			intTotalMinutes = getTotalMinutes(intHours, intMinutes);

			printTime(intTotalMinutes, 24);
			break;
		default:
			cerr << "ERROR" << endl;
	}
}

int main()
{
	// runs everthing
	menu(getMenuChoice());

	return 0;
}