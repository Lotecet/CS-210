#include "Banking.h"
#include <iostream>
#include <iomanip>


using namespace std;

// Setter for Investment amount
void Banking:: SetInvestment(double initialInvestment) {
	monthlyTotalAmount = initialInvestment;
}

// Getter for Investment amount
double Banking::GetInvestment() const {
	return monthlyTotalAmount;
}

// Setter for Monthly Deposits
void Banking::SetMonthlyDeposit(double monthlyDepositnumber) {
	monthlyDeposit = monthlyDepositnumber;
}

// Getter for Monthly Deposits
double Banking::GetMonthlyDeposit() const {
	return monthlyDeposit;
}

// Setter for the Interest Rate
void Banking::SetInterestRate(double anualInterest) {
	monthlyYearlyTotalInterest = anualInterest;
}

// Getter for the Interest Rate
double Banking::GetInterestRate() const {
	return monthlyYearlyTotalInterest;
}

// Setter for the Number of Investment Years
void Banking::SetNumYears(int numYears) {
	monthlyNumYears = numYears;
}

// Getter for the Number of Investment Years
int Banking::GetNumYears() const {
	return monthlyNumYears;
}

// Display Interest Header information
void Banking::InterestHeader(char check) {
	
	cout << endl;
	if (check == 'w') {
		cout << "    Balance and Interest With Additional Monthly Deposits" << endl;
	}
	else {
		cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;
	}
	cout << string(63, '=') << endl;
	cout << "   Year        Year End Balance     Year End Earned Interest" << endl;
	cout << string(63, '-') << endl;
}

// Display and Calculate the Balance WITHOUT a Monthly Deposit
double Banking::CalculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {
	monthlyTotalAmount = initialInvestment;
	char checkHeader = 'a';

	// Display the openning header information
	InterestHeader(checkHeader);

	// Calculate the Interest
	for (int i = 1; i <= numberOfYears; ++i) {
		monthlyInterestAmount = monthlyTotalAmount * (interestRate / 100.00);
		monthlyTotalAmount = monthlyTotalAmount + monthlyInterestAmount;
		
		// Aligns the Columns correctly
		if (monthlyTotalAmount < 1000) {
			cout << string(3, ' ') << left << setw(5) << i << "\t\t$" << fixed << setprecision(2) << monthlyTotalAmount << "\t\t\t\t$" << monthlyInterestAmount << endl;
		}
		else {
			cout << string(3, ' ') << left << setw(5) << i << "\t\t$" << fixed << setprecision(2) << monthlyTotalAmount << "\t\t\t$" << monthlyInterestAmount << endl;
		}
	}
	return monthlyTotalAmount;
}

// Display and Calculate the Balance WITH a Monthly Deposit
double Banking::CalculatebalanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears) {
	monthlyTotalAmount = initialInvestment;
	char checkHeader = 'w';

	// Display the openning header information
	InterestHeader(checkHeader);

	// Calculate the Interest
	for (int i = 1; i <= numberOfYears; ++i) {
		monthlyYearlyTotalInterest = 0;

		for (int j = 0; j < 12; ++j) {
			monthlyInterestAmount = (monthlyTotalAmount + monthlyDeposit) * ((annualInterest / 100.00) / 12);
			monthlyYearlyTotalInterest = monthlyYearlyTotalInterest + monthlyInterestAmount;
			monthlyTotalAmount = monthlyTotalAmount + monthlyDeposit + monthlyInterestAmount;
		}

		// Aligns the Columns correctly
		if (monthlyTotalAmount < 1000) {
			cout << string(3, ' ') << left << setw(5) << i << "\t\t$" << fixed << setprecision(2) << monthlyTotalAmount << "\t\t\t\t$" << monthlyYearlyTotalInterest << endl;
		}
		else {
			cout << string(3, ' ') << left << setw(5) << i << "\t\t$" << fixed << setprecision(2) << monthlyTotalAmount << "\t\t\t$" << monthlyYearlyTotalInterest << endl;
		}
	}
	return monthlyTotalAmount;
}
