#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "BankAccountHeader.h"

using namespace std;

// Initializing static variables
const double CertificateOfDeposit::INTEREST_RATE = 0.20;

const double NoServiceChargeChecking::INTEREST_RATE = 0.05;
const double NoServiceChargeChecking::MINIMUM_BALANCE = 200;

const double HighInterestChecking::INTEREST_RATE = 0.10;
const double HighInterestChecking::MINIMUM_BALANCE = 500;

const int ServiceChargeChecking::MAX_NUMBER_OF_CHECKS = 50;
const double ServiceChargeChecking::SERVICE_CHARGE = 10.0;

const double SavingsAccount::INTEREST_RATE = 0.05;

const double HighInterestSavings::INTEREST_RATE = 0.10;
const double HighInterestSavings::MINIMUM_BALANCE = 200;

// Global function's prototypes
void showMenu();
void createAccount(BankAccount* &);
void accountMenu(BankAccount* &);
void setContinue(bool&);
template <class CheckingType>
void writeCheck(BankAccount *, double);

// Main Function
int main()
{
	bool toContinue = true;
	BankAccount *account[6];
	for (int i = 0; i < 6; i++)
		account[i] = nullptr;

	showMenu();
	for (int i = 0; i < 6 && toContinue == true; i++)
	{
		createAccount(account[i]);
		
		cout << "Press any key to continue to the account menu." << endl;
		cin.ignore(2);

		accountMenu(account[i]);
		cout << endl;
	
		cout << "_____________________________________________" << endl
			<< endl;

		cout << "Do you want to create another test account? [y/n] ";
		setContinue(toContinue);
	}
	return 0;
}

// Global functions' definitions
void showMenu()
{
	cout << endl
		<< "\tWELCOME to THE BANK" << endl 
		<< endl;
	cout << "Create an account." << endl
		<< endl;
}

void createAccount(BankAccount* &account)
{
	int choice;
	bool invalidEntry;

	cout << "Choose an account type:" << endl
		<< endl
		<< "\t1 - Checking account with no service charge" << endl
		<< "\t2 - Checking account with high interest" << endl
		<< "\t3 - Checking account with service charge" << endl
		<< "\t4 - Savings account" << endl
		<< "\t5 - Savings account with high interest" << endl
		<< "\t6 - Certificate of deposit account" << endl 
		<< endl;

	do
	{
		cin >> choice;

		invalidEntry = false;

		if (choice == 1)
			account = new NoServiceChargeChecking;
		else if (choice == 2)
			account = new HighInterestChecking;
		else if (choice == 3)
			account = new ServiceChargeChecking;
		else if (choice == 4)
			account = new SavingsAccount;
		else if (choice == 5)
			account = new HighInterestSavings;
		else if (choice == 6)
			account = new CertificateOfDeposit;
		else
		{
			invalidEntry = true;
			cout << "Invaid entry. Please enter a number between 1 and 6." << endl;
		}
	} while (invalidEntry);

	// Setting name
	string fn, ln;
	cout << "Enter first and last name: ";
	cin >> fn >> ln;
	account->setName(fn, ln);

	// Setting balance
	double amount;
	cout << "Enter starting balance: $";
	cin >> amount;
	account->setBal(amount);

	cout << endl;

	// Printing account information to console
	account->createMonthlyStatement();
	cout << endl
		<< "Account for " << account->getName() << " made." << endl;
}

void accountMenu(BankAccount* &account)
{
	int choice;

	cout << "\tACCOUNT MENU" << endl
		<< endl;
	cout << "Welcome, " << account->getName() << "." << endl
		<< endl;
	cout << "What would you like to do?" << endl
		<< endl
		<< "\t1 - Withdraw" << endl
		<< "\t2 - Deposit" << endl
		<< "\t3 - See monthly statement" << endl;
	if (account->isNoServiceChargeChecking()
		|| account->getType() == "HighInterestChecking"
		|| account->getType() == "ServiceChargeChecking")
	{
		cout << "\t4 - Write a check" << endl;
	}
	cout << endl;

	cin >> choice;
	if (choice == 1)
	{
		double amount;
		cout << "Enter the amount to withdraw: $";
		cin >> amount;
		account->withdraw(amount);
	}
	else if (choice == 2)
	{
		double amount;
		cout << "Enter the amount to deposit: $";
		cin >> amount;
		account->deposit(amount);
	}
	else if (choice == 3)
	{
		account->createMonthlyStatement();
	}
	else if (choice == 4
		&& (account->isNoServiceChargeChecking()
		|| account->isHighInterestChecking()
		|| account->isServiceChargeChecking()) 
		)
	{
		double amount;
		cout << "Enter the amount for the check to be written: $";
		cin >> amount;

		if (account->isNoServiceChargeChecking())
			writeCheck<NoServiceChargeChecking>(account, amount);
		else if (account->isHighInterestChecking())
			writeCheck<HighInterestChecking>(account, amount);
		else if (account->isServiceChargeChecking())
			writeCheck<ServiceChargeChecking>(account, amount);
	}
}

template <class CheckingType>
void writeCheck(BankAccount *accnt, double amnt)
{
	CheckingType *tempAccount = dynamic_cast<CheckingType*>(accnt);
	tempAccount->writeCheck(amnt);
	accnt = tempAccount;
	delete tempAccount;	
}

void setContinue(bool& contVar)
{
	char input;
	cin >> input;

	if (input == 'y')
		contVar = true;
	else if (input == 'n')
		contVar = false;
}

