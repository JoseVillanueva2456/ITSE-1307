/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: COSC/ITSE 1307-001
 * Date: February 6 2018
 * Description: This program takes in your first name, last name
 *				and phone number to print out as a business card
 */

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string strFirstName = "";
	string strLastName = "";
	int strPhoneNumber = 0;

	cout << "Please enter your first name" << endl;
	cin >> strFirstName;

	cout << "Please enter your last name" << endl;
	cin >> strLastName;

	cout << "Please enter your phone number" << endl;
	cin >> strPhoneNumber;

	cout << endl;

	cout << "First Name: " << strFirstName << endl;

	cout << "Last Name: " << strLastName << endl;

	cout << "Phone Number: " << strPhoneNumber << endl;

    return 0;
}

