#pragma once
#include "BankAccount.h"

class SavingsAccount : public BankAccount
{
private:
	static const double INTEREST_RATE;

protected:
	double interestRate;

public:
	void postInterest();
	void withdraw(double);
	virtual void createMonthlyStatement();
	
	// Constructor
	SavingsAccount(string fn = "NoFN", string ln = "NoLN", double bal = 0.0);

	// Destructor
	~SavingsAccount();
};

