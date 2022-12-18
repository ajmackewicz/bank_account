#pragma once
class NoServiceChargeChecking : public CheckingAccount
{
private:
	static const double INTEREST_RATE;
	static const double MINIMUM_BALANCE;

protected:
	double interestRate;
	double minBalance;

public:
	void writeCheck(double);
	void postInterest();
	void createMonthlyStatement();

	// Constructor
	NoServiceChargeChecking(string fn = "NoFN", string ln = "NoLN", double bal = 0.0);

	// Destructor
	~NoServiceChargeChecking();
};
