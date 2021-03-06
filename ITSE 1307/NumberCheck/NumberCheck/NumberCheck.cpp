/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: March 1 2018
 * Description: This program has the user enter a number,
 *				and checks if it is less than zero,
 *				more than zero, or equal to zero.
 */

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int intNumber = 0;

	cout << "Please enter a number" << endl;
	cin >> intNumber;

	if (intNumber > 0) {
		cout << "Number " << intNumber << " is greater than zero" << endl;
	}
	else if (intNumber < 0) {
		cout << "Number " << intNumber << " is less than zero" << endl;
	}
	else {
		cout << "Number " << intNumber << " is equal to zero" << endl;
	}

    return 0;
}

