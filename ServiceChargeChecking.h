#pragma once
#include "CheckingAccount.h"

class ServiceChargeChecking : public CheckingAccount
{
private:	
	static const int MAX_NUMBER_OF_CHECKS;
	static const double SERVICE_CHARGE;

protected:
	int maxNumberOfChecks;
	int serviceCharge;

public:
	void createMonthlyStatement();
	void writeCheck(double amount);
	void postServiceCharge();

	// Constructor
	ServiceChargeChecking(string fn = "NoFN", string ln = "NoLN", double bal = 0.0);

	// Destructor
	~ServiceChargeChecking();
};
