/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: March 12 2018
 * Description: This program converts uppercase letters into
 *				their corresponding telephone digits. 
 */

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	char letter;

	cout << "Program to convert uppercase "
		<< "letters to their corrresponding "
		<< "telephone digits." << endl;

	cout << "To stop the program enter #." << endl;

	cout << "Enter a letter: ";
	cin >> letter;
	cout << endl;

	while (letter != '#') {
		cout << "The letter you entered is: "
			<< letter << endl;
		cout << "The corresponding telephone digit is: "
			<< endl;

		if (letter >= 'A' && letter <= 'Z') {
			switch (letter) {
				case 'A':
				case 'B':
				case 'C':
					cout << 2 << endl;
					break;
				case 'D':
				case 'E':
				case 'F':
					cout << 3 << endl;
					break;
				case 'G':
				case 'H':
				case 'I':
					cout << 4 << endl;
					break;
				case 'J':
				case 'K':
				case 'L':
					cout << 5 << endl;
					break;
				case 'M':
				case 'N':
				case 'O':
					cout << 6 << endl;
					break;
				case 'P':
				case 'Q':
				case 'R':
				case 'S':
					cout << 7 << endl;
					break;
				case 'T':
				case 'U':
				case 'V':
					cout << 8 << endl;
					break;
				case 'W':
				case 'X':
				case 'Y':
				case 'Z':
					cout << 9 << endl;
			}

		} else {
			cout << "Invalid Input." << endl;
		}

		cout << "Program to convert uppercase "
			<< "letters to their corrresponding "
			<< "telephone digits." << endl;

		cout << "To stop the program enter #." << endl;

		cout << "Enter a letter: ";
		cin >> letter;
		cout << endl;
	}

    return 0;
}

