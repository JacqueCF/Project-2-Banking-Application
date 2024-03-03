#include "InvestmentAccount.h"

//Implementation for InvestmentAccount

//constructor for no montly deposit
InvestmentAccount::InvestmentAccount(double startingAmount, double interestRate) {
	initialAmount = startingAmount;
	annualInterestRate = interestRate;
	monthlyDeposit = 0;
}
//constructor with monthly deposit
InvestmentAccount::InvestmentAccount(double startingAmount, double interestRate, double depositAmount) {
	initialAmount = startingAmount;
	annualInterestRate = interestRate;
	monthlyDeposit = depositAmount;
}

// gets ending balance based on number of years 
double InvestmentAccount::getEndingBalance(int numberOfYears) //calculates the ending balance after num of years
{
	double years = numberOfYears;
	int i;
	double closingBal = initialAmount;
	double monthlyInterest;
	// loop from 1 month until # months = (year * 12) and calculate intrest for the month
	for (i = 0; i < (years * 12); ++i) {
		monthlyInterest = (closingBal + monthlyDeposit) * ((annualInterestRate / 100) / 12);
		closingBal = monthlyInterest + closingBal + monthlyDeposit;
	}
	
	
	return closingBal;
}

double InvestmentAccount::getInterestEarned(int numberOfYears) //calculate interest earned for number of years
{
	//Calculate the interest earned for number of years
	double years = numberOfYears;
	double closingBal = getEndingBalance(years);
	double yearDifference;
	double interestEarned;

	// gets value of ending balance if its equal to a year
	if (years < 1){
		yearDifference = getEndingBalance(years) - initialAmount;
		interestEarned = yearDifference - (monthlyDeposit * 12);
	}
	// gets value of ending balance if its more than one year
	else{
		yearDifference = getEndingBalance(years) - getEndingBalance(years - 1);
		interestEarned = yearDifference - (monthlyDeposit * 12);
	 }
	return interestEarned;
}

double InvestmentAccount::getInitialAmount()
{
	return initialAmount;
}

double InvestmentAccount::getMonthlyDeposit()
{
	return monthlyDeposit;
}

double InvestmentAccount::getAnnualInterestRate()
{
	return annualInterestRate;
}

//The following method rounds a value to the specified number of places.
//NOTE: It works for most values...but is not guaranteed to work for all values!
//@param value - the value to round
//@param places - the number of places to round
//@returns - the rounded number
double InvestmentAccount::round(double value, int places) {
	const int multiplier = pow(10, places);

	double roundedValue = (int)(value * multiplier + 0.5);
	roundedValue = (double)roundedValue / multiplier;
	return roundedValue;
}

//Formats a double value for output purposes.
//This method will not append with any 0s...so the value should be rounded prior to use.
//@param value - the value to format
//@returns - the formatted value.
std::string InvestmentAccount::format(double value) {
	std::string valueAsString = std::to_string(value);
	std::string formatted;

	bool decimalFound = false;
	int decimalCount = 0;

	int i;
	for (i = 0; i < valueAsString.size(); i++) {
		char currentChar = valueAsString[i];

		if (decimalCount == 2) {
			break;
		}

		if (currentChar == '.') {
			decimalFound = true;
		}
		else if (decimalFound && decimalCount != 2) {
			decimalCount++;
		}

		formatted.append(std::string(1, currentChar));
	}

	return formatted;
}
