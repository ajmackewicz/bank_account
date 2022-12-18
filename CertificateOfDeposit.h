#pragma once
#include "BankAccount.h"

class CertificateOfDeposit : public BankAccount
{
private:
	static const double INTEREST_RATE;
	
protected:
	double interestRate;
	int numbMaturityMonths;
	int currentMaturityMonth;

public:
	void createMonthlyStatement();

	// Constructors
	CertificateOfDeposit(string fn = "NoFN",
		string ln = "NoFN",
		double bal = 0.0);
	CertificateOfDeposit(string fn,
		string ln,
		double bal,
		double rt,
		int numbMaturityMonths);

	// Destructor
	~CertificateOfDeposit();
};

