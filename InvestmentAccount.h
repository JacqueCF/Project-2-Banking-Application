#pragma once

#include <string>

class InvestmentAccount
{

public:
	//gets values for investment account with no monthly deposit
	InvestmentAccount(double startingAmount, double interestRate); 

	//gets investment account with monthly deposit
	InvestmentAccount(double startingAmount, double interestRate, double depositAmount);

	double getEndingBalance(int numberOfYears);  //Calculate the ending balance after number of years
	

	double getInterestEarned(int numberOfYears); //Calculate the interest earned for number of years

	double getInitialAmount(); //sets user input for initial starting amount
	double getMonthlyDeposit(); //sets user input for monthly deposit
	double getAnnualInterestRate(); //sets user input for Annual Interest Rate

	double round(double value, int places); //rounds values for interest earned and ending balance

	std::string format(double value); //formats values for interest earned and ending balance so that it has two decimal places

private:
	double initialAmount;
	double monthlyDeposit;
	double annualInterestRate;

};


