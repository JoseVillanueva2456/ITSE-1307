/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: April 10 2018
 * Description: This program converts a string to uppercase using
 *				a char array.
 */
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

const int MAX = 50;

string getString(string message) {
	string strSentence = "";

	// get string
	do {
		cout << message << endl;
		getline(cin, strSentence);

		if (strSentence.length() > MAX) {
			cerr << "String too long" << endl;
		}
	} while (strSentence.length() > MAX);

	return strSentence;
}

void initializeArray(char arrLetters[MAX], int strLength) {
	// initialize array (fill for use later)
	for (int count = 0; count < strLength; count++) {
		arrLetters[count] = '-';
	}
}

void arrayUpper(char arrLetters[MAX], int strLength, string strSentence) {
	// make char's uppercase
	for (int count = 0; count < strLength; count++) {
		arrLetters[count] = toupper(strSentence.at(count));
	}
}

void printArray(char arrLetters[MAX], int strLength) {
	// print array
	for (int count = 0; count < strLength; count++) {
		cout << arrLetters[count];
	}
	cout << endl;
}

int main()
{
	char arrLetters[MAX];
	string strSentence = "";
	int strLength = 0;

	strSentence = getString("Please enter a string (max 50 characters)");
	strLength = strSentence.length();
	// cerr << "String length: " << strLength << endl;

	initializeArray(arrLetters, strLength);
	arrayUpper(arrLetters, strLength, strSentence);
	printArray(arrLetters, strLength);

    return 0;
}

