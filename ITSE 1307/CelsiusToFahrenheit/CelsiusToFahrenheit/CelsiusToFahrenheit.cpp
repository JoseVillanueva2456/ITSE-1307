/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: COSC/ITSE 1307-001
 * Date: February 6 2018
 * Description: This program converts from 
 *				celsius to fahrenheit
 */

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	const double DBL_CONVERSION = 1.8;
	const double DBL_ADD = 32.0;
	double dblCelsius = 0.0;
	double dblFahrenheit = 0.0;

	cout << "Please enter degrees in celsius" << endl;
	cin >> dblCelsius;

	dblFahrenheit = (dblCelsius * DBL_CONVERSION) + DBL_ADD;

	cout << "Fahrenheit: " << dblFahrenheit << endl;
	
    return 0;
}

