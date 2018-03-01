/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: March 1 2018
 * Description: This program has the user enter three numbers,
 *				and reoders them from descending order.
 */

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int intNumberOne = 0;
	int intNumberTwo = 0;
	int intNumberThree = 0;

	cout << "Please enter the first number" << endl;
	cin >> intNumberOne;

	cout << "Please enter the second number" << endl;
	cin >> intNumberTwo;

	cout << "Please enter the third number" << endl;
	cin >> intNumberThree;
	cout << endl;

	// checks if numberOne is the largest
	if (intNumberOne > intNumberTwo && intNumberOne > intNumberThree) {
		cout << intNumberOne << endl;

		// checks if number two is the second largest
		if (intNumberTwo > intNumberThree) {
			cout << intNumberTwo << endl;
			cout << intNumberThree << endl;

		// else number three is the second largest
		} else {
			cout << intNumberThree << endl;
			cout << intNumberTwo << endl;
		}
	}else if (intNumberTwo > intNumberOne && intNumberTwo > intNumberThree) {
		cout << intNumberTwo << endl;

		if (intNumberOne > intNumberThree) {
			cout << intNumberOne << endl;
			cout << intNumberThree << endl;
		} else {
			cout << intNumberThree << endl;
			cout << intNumberOne << endl;
		}
	}else if (intNumberThree > intNumberOne && intNumberThree > intNumberTwo) {
		cout << intNumberThree << endl;

		if (intNumberOne > intNumberTwo) {
			cout << intNumberOne << endl;
			cout << intNumberTwo << endl;

		} else {
			cout << intNumberTwo << endl;
			cout << intNumberOne << endl;
		}
	}

	return 0;
}

