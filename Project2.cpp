#include <iostream>
#include <iomanip>
#include "InvestmentAccount.h"

using namespace std;

//Displays the account details, as well as account balances and interest earned for each year.
void displayOutput(InvestmentAccount account, int numberOfYears)
{
    int years;
    int i;
    years = numberOfYears;
    InvestmentAccount userAccount = account;

    //loop to output Ending Balance and Interest Earned from 1 to # of years specified 
    for (i = 1; i < (years + 1); ++i) {
        cout << "Year: " << i << "        " << userAccount.format(userAccount.round(userAccount.getEndingBalance(i), 2));
        std::cout << std::setw(20);
        cout << userAccount.format(userAccount.round(userAccount.getInterestEarned(i), 2)) << endl;
    }
}

int main()
{
    double startingAmount;
    double interestRate;
    double depositAmount;
    int years;
    int i;
    
    //Gets Prompts the user for input
    cout << "***** Data Input *****" << endl;
    cout << "Intial Investment Amount: " << endl;
    cin >> startingAmount;
    cout << "Monthly Deposit: " << endl;
    cin >> depositAmount;
    cout << "Annual Intrest: " << endl;
    cin >> interestRate;
    cout << "Number of Years: " << endl;
    cin >> years;

    //loops to check to make sure none of the values negative and prompts user for new values if need be
    while ((startingAmount < 0) || (depositAmount < 0) || (interestRate < 0) || (years < 0)) {
        cout << "Values must be positive. Please enter values again" << endl;
        cout << "***** Data Input *****" << endl;
        cout << "Intial Investment Amount: " << endl;
        cin >> startingAmount;
        cout << "Monthly Deposit: " << endl;
        cin >> depositAmount;
        cout << "Annual Intrest: " << endl;
        cin >> interestRate;
        cout << "Number of Years: " << endl;
        cin >> years;
    }
    //outputs validated amounts
    cout << "***** Data Input *****" << endl;
    cout << "Intial Investment Amount: "<< startingAmount << endl;
    cout << "Monthly Deposit: " << depositAmount << endl;
    cout << "Annual Interest: " << interestRate << endl;
    cout << "Number of Years: " << years << endl;


    //Create two InvestmentAccount objects...one with monthly deposit and one without monthly deposit
    InvestmentAccount accountNoDeposit(startingAmount, interestRate);
    InvestmentAccount accountWDeposit(startingAmount, interestRate, depositAmount);
    
    //outputs objects with amounts for each year the account is open.
    cout << "Balance and Interest Without Monthly Deposits" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Year        Year End Balance     Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------------" << endl;
    displayOutput(accountNoDeposit, years);

    cout << " " << endl;
    cout << "Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Year        Year End Balance     Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------------" << endl;
    displayOutput(accountWDeposit, years);
}


