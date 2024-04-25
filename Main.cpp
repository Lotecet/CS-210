#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "Banking.h"

using namespace std;

// Global Variables
Banking investment;		// Class variable for holding the Investment Portfolio data
double monthlyDeposit;	// Variable housing the Monthly Deposit value
double initialInvest;	// Variable housing the Initial Investment value
double annualInt;		// Variable housing the Annual Interest Rate
int numYears;			// Number of years for investments 
string temp;            // A temp variable so the user can press contiue
char input = 'a';		// character to exit program or not

// Check if Input is a Positive Real Number, if not it displays an error message
void PositiveRealNumber(double num) {
	if (num <= 0) {
		cout << "*** Please Enter a Valid Positive Number ***" << endl;
	}
}

void StartingInputScreen() {
	// Get Initial Investment input from the user
	cout << string(34, '*') << endl;
	cout << string(10, '*') << " Data Input " << string(10, '*') << endl;
	cout << "Initial Investment Amount: $";
	cin >> initialInvest;
	cin.clear();

	// check if the Initial Investment is valid
	while (initialInvest <= 0) {
		PositiveRealNumber(initialInvest);
		cout << "Initial Investment Amount: $";
		cin >> initialInvest;
		cin.clear();
	}
	investment.SetInvestment(initialInvest);

	// Get Monthly Deposit amount
	cout << "Monthly Deposit: $";
	cin >> monthlyDeposit;
	cin.clear();
	
	// Check if the Monthly Deposit is valid
	while (monthlyDeposit <= 0) {
		PositiveRealNumber(monthlyDeposit);
		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;
		cin.clear();
	}
	investment.SetMonthlyDeposit(monthlyDeposit);

	// Get Anual Interest
	cout << "Annual Interest: %";
	cin >> annualInt;
	cin.clear();

	// Check if Annual Interest is valid
	while (annualInt < 0) {
		PositiveRealNumber(annualInt);
		cout << "Annual Interest: %";
		cin >> annualInt;
		cin.clear();
	}
	investment.SetInterestRate(annualInt);

	// Get number of Years to Invest
	cout << "Number of years: ";
	cin >> numYears;
	cin.clear();

	// Check if the Monthly Deposit is valid
	while (numYears <= 0) {
		PositiveRealNumber(numYears);
		cout << "Number of years: ";
		cin >> numYears;
		cin.clear();
	}
	investment.SetNumYears(numYears);
}

// Main logic
int main() {
	
	// Loops until the user wants to quit
	while (input != 'q') {
		// Start the Input Screen so the user can enter values
		StartingInputScreen();
		cout << "Press any key to continue then <Enter>...";
		cin >> temp;

		// Calculate the Investment WITHOUT Monthly Deposits
		investment.CalculateBalanceWithoutMonthlyDeposit(initialInvest, annualInt, numYears);
		// Calculate the Investment WITH Monthly Deposits
		investment.CalculatebalanceWithMonthlyDeposit(initialInvest, monthlyDeposit, annualInt, numYears);

		// Check if the user wants to quit or run again
		cout << "Enter 'q' to quit. Or any other character to run again...";
		cin >> input;
	}
	return 0;
}
