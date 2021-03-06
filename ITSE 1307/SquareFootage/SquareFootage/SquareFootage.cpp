/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: March 12 2018
 * Description: This program has the user enter the base price for three
 *				houses and their finished area in square feet then prints
 *				out the lowest model(s).
 */

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double dblModelOnePrice = 0.0;
	double dblModelTwoPrice = 0.0;
	double dblModelThreePrice = 0.0;
	double dblModelOneFeet = 0.0;
	double dblModelTwoFeet = 0.0;
	double dblModelThreeFeet = 0.0;
	double dblModelOneFinal = 0.0;
	double dblModelTwoFinal = 0.0;
	double dblModelThreeFinal = 0.0;

	// -------------------------------------------------------------------------------------------
	// Model one prompt & input (do loops stop user from entering 0 or a negative number)
	// -------------------------------------------------------------------------------------------

	do {
		cout << "Please enter the first model's base price" << endl;
		cin >> dblModelOnePrice;
	} while (dblModelOnePrice <= 0.0);
	
	do {
		cout << "Please enter the first model's finished area in square feet" << endl;
		cin >> dblModelOneFeet;
	} while (dblModelOneFeet <= 0.0);

	// -------------------------------------------------------------------------------------------
	// Model two prompt & input
	// -------------------------------------------------------------------------------------------

	do {
		cout << "Please enter the second model's base price" << endl;
		cin >> dblModelTwoPrice;
	} while (dblModelTwoPrice <= 0.0);

	do {
		cout << "Please enter the second model's finished area in square feet" << endl;
		cin >> dblModelTwoFeet;
	} while (dblModelTwoFeet <= 0.0);

	// -------------------------------------------------------------------------------------------
	// Model three prompt & input
	// -------------------------------------------------------------------------------------------

	do {
		cout << "Please enter the third model's base price" << endl;
		cin >> dblModelThreePrice;
	} while (dblModelThreePrice <= 0.0);

	do {
		cout << "Please enter the third model's finished area in square feet" << endl;
		cin >> dblModelThreeFeet;
	} while (dblModelThreeFeet <= 0.0);

	// -------------------------------------------------------------------------------------------
	// price per square foot calcualtions
	// -------------------------------------------------------------------------------------------

	dblModelOneFinal = (dblModelOnePrice / dblModelOneFeet);

	dblModelTwoFinal = (dblModelTwoPrice / dblModelTwoFeet);

	dblModelThreeFinal = (dblModelThreePrice / dblModelThreeFeet);

	// -------------------------------------------------------------------------------------------
	// print lowest price per square foot Model(s)
	// -------------------------------------------------------------------------------------------

	// set format
	cout << fixed << setprecision(2);
	cout << "Lowest price(s)" << endl;
	cout << "--------------------------------------" << endl;

	if (dblModelOneFinal < dblModelTwoFinal && dblModelOneFinal < dblModelThreeFinal) {

		// model one is the lowest
		cout << "Model 1: $" << dblModelOneFinal << " per square foot" << endl;

	}
	else if (dblModelTwoFinal < dblModelOneFinal && dblModelTwoFinal < dblModelThreeFinal) {

		// model two is the lowest
		cout << "Model 2: $" << dblModelTwoFinal << " per square foot" << endl;

	}
	else if (dblModelThreeFinal < dblModelOneFinal && dblModelThreeFinal < dblModelTwoFinal) {

		// model three is the lowest
		cout << "Model 3: " << dblModelThreeFinal << " per square foot" << endl;

	}
	else if (dblModelOneFinal == dblModelTwoFinal && dblModelOneFinal == dblModelThreeFinal) {

		// all models are the same
		cout << "Model 1: $" << dblModelOneFinal << " per square foot" << endl;
		cout << "Model 2: $" << dblModelTwoFinal << " per square foot" << endl;
		cout << "Model 3: $" << dblModelThreeFinal << " per square foot" << endl;

	}
	else if (dblModelOneFinal == dblModelTwoFinal) {

		// models one and two are the same
		cout << "Model 1: $" << dblModelOneFinal << " per square foot" << endl;
		cout << "Model 2: $" << dblModelTwoFinal << " per square foot" << endl;

	}
	else if (dblModelOneFinal == dblModelThreeFinal) {

		// models one and three are the same
		cout << "Model 1: $" << dblModelOneFinal << " per square foot" << endl;
		cout << "Model 3: $" << dblModelThreeFinal << " per square foot" << endl;

	}
	else {

		// models two and three are the same
		cout << "Model 2: $" << dblModelTwoFinal << " per square foot" << endl;
		cout << "Model 3: $" << dblModelThreeFinal << " per square foot" << endl;

	}

    return 0;
}