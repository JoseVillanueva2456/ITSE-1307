/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: February 20 2018
 * Description: This program computes volume from
 *				inputted mass and density, stores
 *				the data in a file, reads it and
 *				stores the result in a different
 *				file.
 */

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	string strDataFileName = "input.dat";
	string strOutputFileName = "output.txt";
	double dblMass = 0.0;
	double dblDensity = 0.0;
	double dblReadMass = 0.0;
	double dblReadDensity = 0.0;
	double dblVolume = 0.0;

	cout << "Enter mass in grams" << endl;
	cin >> dblMass;

	cout << "Enter density in grams per cubic centimeters" << endl;
	cin >> dblDensity;

	// store inputted data
	ofstream storeData;
	storeData.open(strDataFileName);
	storeData << fixed << setprecision(2); // format to 2 decimal places
	storeData << dblMass << endl;
	storeData << dblDensity << endl;
	storeData.close();
	cout << "Wrote " << strDataFileName << endl;
	
	// read inputted data
	ifstream readData;
	readData.open(strDataFileName);
	readData >> dblReadMass;
	readData >> dblReadDensity;
	readData.close();

	// equation is voulume = mass / density
	dblVolume = dblReadMass / dblReadDensity;

	cout << fixed << setprecision(2);

	// store results
	ofstream outputData;
	outputData.open(strOutputFileName);
	outputData << fixed << setprecision(2); // format to 2 decimal places
	outputData << dblVolume;
	outputData.close();

	cout << "Wrote " << strOutputFileName << endl;

    return 0;
}