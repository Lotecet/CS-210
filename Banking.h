/* 
Mitchell Gossman
CS 210
04/05/24
*/

#pragma once
#ifndef BANKING_H
#define BANKING_H

// Class declarations
class Banking {
public:
	void InterestHeader(char check);

	double CalculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears);
	double CalculatebalanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears);

	void SetInvestment(double initialInvestment);
	double GetInvestment() const;
	
	void SetMonthlyDeposit(double monthlyDeposit);
	double GetMonthlyDeposit() const;

	void SetInterestRate(double anualInterest);
	double GetInterestRate() const;

	void SetNumYears(int numYears);
	int GetNumYears() const;

private:
	double monthlyTotalAmount;
	double monthlyInterestAmount;
	double monthlyYearlyTotalInterest;
	double monthlyDeposit;
	int monthlyNumYears;
};

#endif
