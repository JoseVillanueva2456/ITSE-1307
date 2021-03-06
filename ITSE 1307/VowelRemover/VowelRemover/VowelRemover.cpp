/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: April 19 2018
 * Description: This program removes vowels from a user's inputted string.
 */

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char letter) {
	// checks if vowel
	char chrLetter = toupper(letter);
	if (chrLetter == 'A' || chrLetter == 'E'
		|| chrLetter == 'I' || chrLetter == 'O' || chrLetter == 'U') {

		return true;
	}
	else {
		return false;
	}
}

string removeVowel(string str) {
	string strNewString = str;
	string strFirstHalve = "";
	string strSecondHalve = "";
	int intLength = strNewString.length();

	for (int count = 0; count < intLength; count++) {

		if (isVowel(strNewString.at(count))) {

			if (count > 0 && count < intLength) {

				// vowel is in the middle (or in the end)
				strFirstHalve = strNewString.substr(0, count);

				// "second half" ignores a vowel at the end by returning an empty string
				strSecondHalve = strNewString.substr(count + 1, intLength);
				strNewString = strFirstHalve + strSecondHalve;

				// minus 1 to count to properly check new char location
				count -= 1;

			} else {

				// vowel is at beginning
				strNewString = strNewString.substr(1, intLength);
				count -= 1;
			}

			// update length when finished altering the string
			intLength = strNewString.length();
		}
	}
	
	return strNewString;
}

int main()
{
	string strSentence = " ";

	do {
		cout << "Please enter a String" << endl;
		getline(cin, strSentence);
	} while (strSentence == " ");

	strSentence = removeVowel(strSentence);

	cout << "\nNew String: " << strSentence << endl;

    return 0;
}

