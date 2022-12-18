#pragma once
#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
protected:
	int id;
	string fname;
	string lname;
	string name;
	double balance;
	string type;

public:
	int currentID();
	void setID(int ID);
	void setBal(double BAL);
	void setName(string FN, string LN);
	virtual void setType(string TYPE); // Necessary to be virtual?

	int getID();
	string getName();
	string getType();
	double getBal();

	bool isNoServiceChargeChecking();
	bool isHighInterestChecking();
	bool isServiceChargeChecking();


	void deposit(double amount);
	virtual void withdraw(double amount);

	void print();
	virtual void createMonthlyStatement() = 0;

	// Constructor
	BankAccount(string fn = "No Name", string ln = "No Name", double bal = 0.0);

	// Destructor
	~BankAccount();
};

