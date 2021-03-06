/*
 * Name: Jose Villanueva
 * Teacher: Christopher MacDougald
 * Section: ITSE 1307-001
 * Date: February 13 2018
 * Description: This program computes and diplays
 *				a formatted Pay Stub with deducted taxes
 *				and fees.
 */

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// constants for easy future change
// note: percentages are converted into decimals
const double DBL_FEDERAL_INCOME_TAX = .15; // 15%
const double DBL_STATE_TAX = 0.0; // 0%
const double DBL_SOCIAL_SECURITY_TAX = 0.0575; // 5.75%
const double DBL_MEDICARE_MEDICAID_TAX = 0.0275; // 2.75%
const double DBL_PENSION_PLAN = 0.05; // 5%
const double DBL_HEALTH_INSURANCE = 75.00; // $75

int main()
{
	//declared variables
	string strEmployeeName = "Empty Name";
	double dblGrossAmount = 0.0;
	double dblFederalTax = 0.0;
	double dblStateTax = 0.0;
	double dblSocialTax = 0.0;
	double dblMedicalTax = 0.0;
	double dblPensionPlan = 0.0;
	double dblTotalDeducted = 0.0;
	double dblNetPay = 0.0;

	//--------------------------------------------------------------------------------------
	//prompt user for employee name and gross amount
	cout << "Please enter employee name" << endl;
	getline(cin, strEmployeeName);

	cout << "Please enter gross amount" << endl;
	cin >> dblGrossAmount;

	cout << endl << strEmployeeName << endl;
	cout << fixed << setprecision(2); // set format to 2 decimal places

	//--------------------------------------------------------------------------------------
	//Gross Amount formatted output

	cout << "Gross Amount: " << setfill('-') << setw(15)
		<< " $" << setfill(' ')  << setw(7)
		<< dblGrossAmount << endl;

	//--------------------------------------------------------------------------------------
	//Federal Tax formatted output
	
	// equations for taxes is Total * Percentage(in decimal form)
	dblFederalTax = dblGrossAmount * DBL_FEDERAL_INCOME_TAX;

	// add to total deducted
	dblTotalDeducted = dblTotalDeducted + dblFederalTax;

	cout << "Federal Tax: " << setfill('-') << setw(16)
		<< " $" << setfill(' ') << setw(7)
		<< dblFederalTax << endl;

	//--------------------------------------------------------------------------------------
	//State Tax formatted output

	dblStateTax = dblGrossAmount * DBL_STATE_TAX;

	dblTotalDeducted = dblTotalDeducted + dblStateTax;

	cout << "State Tax: " << setfill('-') << setw(18)
		<< " $" << setfill(' ') << setw(7)
		<< dblStateTax << endl;

	//--------------------------------------------------------------------------------------
	//Social Security Tax formatted output

	dblSocialTax = dblGrossAmount * DBL_SOCIAL_SECURITY_TAX;

	dblTotalDeducted = dblTotalDeducted + dblSocialTax;

	cout << "Social Tax: " << setfill('-') << setw(17)
		<< " $" << setfill(' ') << setw(7)
		<< dblSocialTax << endl;

	//--------------------------------------------------------------------------------------
	//Medicare / Medicaid Tax formatted output

	dblMedicalTax = dblGrossAmount * DBL_MEDICARE_MEDICAID_TAX;

	dblTotalDeducted = dblTotalDeducted + dblMedicalTax;

	cout << "Medicaid / Medicare Tax: " << setfill('-') << setw(4)
		<< " $" << setfill(' ') << setw(7)
		<< dblMedicalTax << endl;

	//--------------------------------------------------------------------------------------
	//Pension Plan formatted output

	dblPensionPlan = dblGrossAmount * DBL_PENSION_PLAN;

	dblTotalDeducted = dblTotalDeducted + dblPensionPlan;

	cout << "Pension Plan: " << setfill('-') << setw(15)
		<< " $" << setfill(' ') << setw(7)
		<< dblPensionPlan << endl;

	//--------------------------------------------------------------------------------------
	//Health Insurance formatted output

	dblTotalDeducted = dblTotalDeducted + DBL_HEALTH_INSURANCE;

	cout << "Health Insurance: " << setfill('-') << setw(11)
		<< " $" << setfill(' ') << setw(7)
		<< DBL_HEALTH_INSURANCE << endl;

	//--------------------------------------------------------------------------------------
	//Net Pay formatted output

	dblNetPay = dblGrossAmount - dblTotalDeducted;

	cout << "Net Pay: " << setfill('-') << setw(20)
		<< " $" << setfill(' ') << setw(7)
		<< dblNetPay << endl;

    return 0;
}

