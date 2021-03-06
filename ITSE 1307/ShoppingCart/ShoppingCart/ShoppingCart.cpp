/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: March 27 2018
 * Description: This program takes the total cost of a shopping cart
 *				and adds a $10 shipping fee for each item if the total
 *				cost is below $200.
 */

// Psuedo Code
//
// BEGIN
//		Prompt user enter cost of item
//
//		WHILE user wants to enter an amount
//			add item amount to total cost
//			increment item count by one
//		END
//
//		IF total >= 200
//			PRINT total cost
//		ELSE
//			total cost = total cost + (total count * shipping fee)
//			PRINT total cost
//		END
// END
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

double itemCheck(double itemAmount) {
	// stops negative numbers from being included into total cost
	if (itemAmount > 0.0) {
		return itemAmount;
	}
	else {
		return 0.0;
	}
}

int countCheck(double itemAmount) {
	// stops invalid items from being counted
	if (itemAmount > 0.0) {
		return 1;
	}
	else if (itemAmount == 0.0) {
		return 0;
	}
	else {
		// only one "invalid input" prompt needed
		cout << "Invalid Input" << endl;
		return 0;
	}
}

int main()
{
	const double DBL_FEE = 10.0;
	int intItemCount = 0;
	double dblItemAmount = 0.0;
	double dblTotalCost = 0.0;

	do {
		cout << "Please enter item amount (enter \"0\" when finished)" << endl;
		cin >> dblItemAmount;

		// check item amount first
		intItemCount += countCheck(dblItemAmount);
		dblTotalCost += itemCheck(dblItemAmount);

	} while (dblItemAmount != 0.0);

	// set decimal format
	cout << fixed << setprecision(2);

	if (dblTotalCost >= 200.0) {
		// print total without fee if above or equal to 200
		cout << endl <<  "Total Cost: $" << dblTotalCost << endl;
	}
	else {
		// print total with fee calculated into total
		dblTotalCost = dblTotalCost + (intItemCount * DBL_FEE);
		cout << endl << "Total Cost: $" << dblTotalCost << endl;
	}

    return 0;
}

