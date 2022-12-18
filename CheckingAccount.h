#pragma once
#include "BankAccount.h"

class CheckingAccount : public BankAccount
{
protected:
	int numberOfChecksWritten;

public:
	virtual void writeCheck(double) = 0;
	virtual void createMonthlyStatement(); 
	
	// Constructors
	CheckingAccount(string fn, string ln, double bal);

	// Destructor
	~CheckingAccount();
};

