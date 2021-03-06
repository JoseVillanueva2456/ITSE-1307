/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: COSC/ITSE 1307-001
 * Date: February 6 2018
 * Description: This program converts kilometers to miles
 */

#include "stdafx.h"
#include <iostream>
using namespace std;

const double DBL_CONVERSION = 1.609344;

int main()
{
	double dblKilometers = 0.0;

	cout << "Please enter your run in kilometers" << endl;
	cin >> dblKilometers;

	dblKilometers = dblKilometers / DBL_CONVERSION;

	cout << "Run in miles: " << dblKilometers << endl;
	
    return 0;
}

