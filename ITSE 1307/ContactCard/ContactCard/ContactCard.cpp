/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: February 14 2018
 * Description: This program creates a contact card based on
 *				character from a game called "Shovel Knight"
 */

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	string strFileName = "address.vcf";
	ofstream fileAddress;
	string strFirst = "Shovel";
	string strLast = "Knight";
	string strEmail = "ShovelKnight@gmail.com";
	string strBirthDay = "20140626";
	string strCompany = "Yacht Club Games";
	string strJobTitle = "Main Antagonist";
	string strCompanyWebsite = "http://yachtclubgames.com/";
	string strWorkAddress = "4640 Admiralty Way;Marina Del Rey;California;90292;United States";
	string strWorkPhone = "(210) 123-4567";

	fileAddress.open(strFileName);
	fileAddress << "BEGIN:VCARD" << endl;
	fileAddress << "VERSION:2.1" << endl;
	fileAddress << "N:" << strLast << ";" << strFirst << ";;" << endl;
	fileAddress << "FN:" << strFirst << " " << strLast << endl;
	fileAddress << "BDAY:" << strBirthDay << endl;
	fileAddress << "Email:" << strEmail << endl;
	fileAddress << "ORG:" << strCompany << endl;
	fileAddress << "TITLE:" << strJobTitle << endl;
	fileAddress << "ADR;WORK:;;" << strWorkAddress << endl;
	fileAddress << "URL;Work:" << strCompanyWebsite << endl;
	fileAddress << "TEL;WORK:" << strWorkPhone << endl;
	fileAddress << "END:VCARD" << endl;
	fileAddress.close();
	cout << "Wrote " << strFileName << endl;
    return 0;
}

