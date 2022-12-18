#pragma once
#include "SavingsAccount.h"

class HighInterestSavings : public SavingsAccount
{
private:
	static const double INTEREST_RATE;
	static const double MINIMUM_BALANCE;

protected:
	double minBalance;

public:
	void setMinBal(double minBal);
	void createMonthlyStatement();

	// Constructors
	HighInterestSavings(string fn = "NoFN", string ln = "NoFN", double bal = 0.0);
	HighInterestSavings(string fn, string ln, double bal, double minBal);

	// Destructor
	~HighInterestSavings();
};
