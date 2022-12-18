#include <iomanip>
#include "BankAccountHeader.h"

// DEFINITIONS FOR BANKACCOUNT
// Constructor
BankAccount::BankAccount(string fn, string ln, double bal)
{
	id = currentID();

	fname = fn;
	lname = ln;
	balance = bal;
	
	name = fname + " " + lname;
	type = "Checking";
}

//Setters
void BankAccount::setID(int ID)
{
	id = ID;
}

void BankAccount::setBal(double BAL)
{
	balance = BAL;
}

void BankAccount::setName(string FN, string LN)
{
	fname = FN;
	lname = LN;
	name = fname + " " + lname;
}

void BankAccount::setType(string TYPE)
{
	type = TYPE;
}

// Getters
int BankAccount::getID()
{
	return id;
}

string BankAccount::getName()
{
	return name;
}

string BankAccount::getType()
{
	return type;
}

double BankAccount::getBal()
{
	return balance;
}

bool BankAccount::isNoServiceChargeChecking()
{
	return (type == "NoServiceChargeChecking");
}

bool BankAccount::isHighInterestChecking()
{
	return (type == "HighInterestChecking");
}

bool BankAccount::isServiceChargeChecking()
{
	return (type == "ServiceChargeChecking");
}
// Others / Mutators 
int BankAccount::currentID()
{
	static int current = 0;
	current++;

	return current;
}

void BankAccount::deposit(double amount)
{
	balance += amount;
	cout << "Amount of $" << amount 
		<< " deposited to account number " << id << "." << endl
		<< "Balance: " << getBal() << endl;
}

void BankAccount::withdraw(double amount)
{
	balance -= amount;
	cout << "Amount of $" << amount
		<< " withdrawn from account number " << id << "." << endl
		<< "Balance remaining: $" << getBal() << endl;
}

void BankAccount::print()
{
	cout << fixed << setprecision(2) 
		<<"Printing information for account number " << id << ":" << endl
		<< "Name: " << name << endl
		<< "Type: " << type << endl
		<< "Balance: $" << balance << endl;
}
// Destructor
BankAccount::~BankAccount() {}


// DEFINITIONS FOR CHECKINGACCOUNT
// Constructors
CheckingAccount::CheckingAccount(string fn,
		string ln,
		double bal) : BankAccount(fn, ln, bal)
{
	type = "Checking";
	numberOfChecksWritten = 0;
}


// Printer
void CheckingAccount::createMonthlyStatement()
{
	BankAccount::print();
	cout << "Number of Checks Written: " << numberOfChecksWritten << endl;
}

// Destructor
CheckingAccount::~CheckingAccount() {}


// DEFINITIONS FOR SAVINGSACCOUNT
// Constructors
SavingsAccount::SavingsAccount(string fn,
		string ln,
		double bal) : BankAccount(fn, ln, bal)
{
	interestRate = INTEREST_RATE;
	type = "Savings";
}

// Others / Mutators
void SavingsAccount::postInterest()
{
	deposit(interestRate * balance);
	cout << "Interest of $" << interestRate * balance << " added to savings account number " << id << "." << endl
		<< endl;
}

void SavingsAccount::withdraw(double amount)
{
	BankAccount::withdraw(amount);
	cout << "Amount of $" << amount << " withdrawn" << endl
		<< "from savings account number " << id << "." << endl
		<< endl;
}

void SavingsAccount::createMonthlyStatement()
{
	BankAccount::print();
	cout << "Interest Rate: " << 100 * interestRate << "%" << endl;
}

// Destructor
SavingsAccount::~SavingsAccount() {}


// DEFINITIONS FOR HIGHINTERESTSAVINGS
// Constructors
HighInterestSavings::HighInterestSavings(string fn,
	string ln,
	double bal) : SavingsAccount(fn, ln, bal)
{
	interestRate = INTEREST_RATE;
	minBalance = MINIMUM_BALANCE;
	type = "HighInterestSavings";
}

HighInterestSavings::HighInterestSavings(string fn,
	string ln,
	double bal,
	double minBal) : SavingsAccount(fn, ln, bal)
{
	interestRate = INTEREST_RATE;
	minBalance = minBal;
	type = "HighInterestSavings";
}

// Setters
void HighInterestSavings::setMinBal(double minBal)
{
	minBalance = minBal;
}

void HighInterestSavings::createMonthlyStatement()
{
	SavingsAccount::createMonthlyStatement();
	cout << "Minimum Balance: $" << minBalance << endl;
}

// Destructor
HighInterestSavings::~HighInterestSavings() {}


// DEFINITIONS FOR CERTIFICATEOFDEPOSIT
// Constructors
CertificateOfDeposit::CertificateOfDeposit(string fn,
		string ln,
		double bal) : BankAccount(fn, ln, bal)
{
	type = "CertificateOfDeposit";
	interestRate = INTEREST_RATE;
	currentMaturityMonth = 0;
	numbMaturityMonths = 6;
}

CertificateOfDeposit::CertificateOfDeposit(string fn,
	string ln,
	double bal,
	double rt,
	int numbMonths) : BankAccount(fn, ln, bal)
{
	type = "CertificateOfDeposit";
	interestRate = INTEREST_RATE;
	currentMaturityMonth = 0;
	numbMaturityMonths = numbMonths;
}

// Printer
void CertificateOfDeposit::createMonthlyStatement()
{
	BankAccount::print();
	cout << "Interest Rate: " << 100 * interestRate << "%" << endl
		<< "Current Maturity Month: " << currentMaturityMonth << endl
		<< "Number of Maturity Months: " << numbMaturityMonths << endl;
}

// Destructor
CertificateOfDeposit::~CertificateOfDeposit() {}


// DEFINITIONS FOR NOSERVICECHARGECHECKING
// Constructor
NoServiceChargeChecking::NoServiceChargeChecking(string fn,
	string ln,
	double bal) : CheckingAccount(fn, ln, bal)
{
	type = "NoServiceChargeChecking";
	interestRate = INTEREST_RATE;
	minBalance = MINIMUM_BALANCE;
}

// Others / Mutators
void NoServiceChargeChecking::writeCheck(double amount)
{
	withdraw(amount);
	numberOfChecksWritten++;
}

void NoServiceChargeChecking::postInterest()
{
	deposit(interestRate * balance);
}

void NoServiceChargeChecking::createMonthlyStatement()
{
	CheckingAccount::createMonthlyStatement();
	cout << "Interest Rate: " << 100 * interestRate << "%" << endl
		<< "Minimum Balance: $" << minBalance << endl;
}

// Destructor
NoServiceChargeChecking::~NoServiceChargeChecking() {}


// DEFINITIONS OF HIGHINTERESTCHECKING
// Constructor
HighInterestChecking::HighInterestChecking(string fn,
	string ln,
	double bal) : NoServiceChargeChecking(fn, ln, bal)
{
	type = "HighInterestChecking";
	interestRate = INTEREST_RATE;
	minBalance = MINIMUM_BALANCE;
}

// Destructor
HighInterestChecking::~HighInterestChecking() {}


// DEFINITIONS FOR SERVICECHARGECHECKING
// Constructor
ServiceChargeChecking::ServiceChargeChecking(string fn,
	string ln,
	double bal) : CheckingAccount(fn, ln, bal) 
{
	type = "ServiceChargeChecking";
	maxNumberOfChecks = MAX_NUMBER_OF_CHECKS;
	serviceCharge = SERVICE_CHARGE;
}

// Others / Mutators
void ServiceChargeChecking::createMonthlyStatement()
{
	CheckingAccount::createMonthlyStatement();
	cout << "Maximum Number of Checks Allowed to Be Written: " << MAX_NUMBER_OF_CHECKS << endl
		<< "Service Charge: $" << SERVICE_CHARGE << endl;
}

void ServiceChargeChecking::writeCheck(double amount)
{
	if (numberOfChecksWritten >= MAX_NUMBER_OF_CHECKS)
		cout << "Maximum number of checks written." << endl;
	else
	{
		withdraw(amount);
		numberOfChecksWritten++;
	}
}

void ServiceChargeChecking::postServiceCharge()
{
	balance-=serviceCharge;
}

// Destructor
ServiceChargeChecking::~ServiceChargeChecking() {}
