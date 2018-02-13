/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: February 13 2018
 * Description: This program computes and displays
 *				the missing angle of a triangle
 *				using the pythagorean theorem
 */

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double dblAngleApple = 0.0;
	double dblAngleBanana = 0.0;
	double dblAngleCarrot = 0.0;
	
	cout << "Please enter angle A and angle B of a triangle whith a space in between" << endl;

	cin >> dblAngleApple >> dblAngleBanana;

	// pythagorean theorem equation is angleC = sqrt((angleA^2) + (angleB^2))
	dblAngleCarrot = sqrt(pow(dblAngleApple, 2.0) + pow(dblAngleBanana, 2.0));

	cout << fixed << setprecision(2);
	cout << "Angle A is: " << dblAngleApple << endl;
	cout << "Angle B is: " << dblAngleBanana << endl;
	cout << "Angle C is: " << dblAngleCarrot << endl;

	return 0;
}

