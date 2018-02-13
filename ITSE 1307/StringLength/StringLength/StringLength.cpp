/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: February 12 2018
 * Description: This program gets a string and outputs
 *				it along with the string length
 */

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string strSentence = "Empty";

	cout << "Please enter a string" << endl;

	getline(cin, strSentence);

	cout << "What you entered: " << strSentence << endl;
	cout << "String length: " << strSentence.length() << endl;

	return 0;
}

