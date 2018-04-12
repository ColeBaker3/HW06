#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
#include <vector>
#include <sstream>
#include "Customer.h"
#include "Transaction.h"

/**
The Bank has Accounts and an Account belongs to a Customer.
Additionally, there are specialized types of accounts: Checking_Account and Savings_Account.
Checking_Account and Savings_Account have specialized ways of adding interest, and describing itself.
@author: Ed Walker
*/

class Account {
protected:
	Customer *customer;		// The customer who owns this account
	double balance;			// The available balance in this account
	int account_number;		// A unique number identifying this account
	std::vector<Transaction *> transactions;  // The record of transactions that have occured with this account

	std::string get_fees()
	{
		std::stringstream ss;
		ss << "Check Charge: " << customer->get_check_charge() << " Overdraft Fee: " << customer->get_overdraft_penalty();
		return ss.str();
	}

protected:
	/**
	Add interest based on a specified interest rate to account
	@param interest	The interest rate
	*/
	void add_interest(double interest) {
		double amt = balance*interest;
		balance = balance + amt;
		std::string fees = get_fees();
		Transaction *tran = new Transaction(account_number, "Interest", interest, fees); //Create a Transaction object and assign it to the transaction vector.

		transactions.push_back(tran);
	}

public:
	/**
	Constructor requires a customer to create an account
	Balance always starts with 0 when account is created.
	*/
	Account(Customer *cust, int id) : customer(cust), account_number(id), balance(0) {}

	/**
	Generic accesser and setter methods for properties customer, balance, and account_number
	*/

	Customer *get_customer() {
		return customer;
	}

	void set_customer(Customer *cust) {
		customer = cust;
	}

	int get_account() {
		return account_number;
	}

	void set_balance(double new_balance) {
		balance = new_balance;
	}

	void set_account(int account_number) {
		this->account_number = account_number;
	}

	double get_balance() {
		return balance;
	}

	/**
	Generic method describing the account information.
	Remember that you will need to indicate if an account is Savings or Checking in
	an overridden version of to_string() in the derived classes.
	@return string describing generic information about the account
	*/
	virtual std::string to_string() {
		std::stringstream ss; // for composing the string that describes this account

		ss << "  Account information:" << std::endl;
		ss << "  Balance: $" << balance << std::endl;
		ss << "  Account ID: " << account_number << std::endl << std::endl;

		ss << "  Customer information:" << std::endl;
		ss << "  Address:  " << customer->get_address() << std::endl;
		ss << "  Phone:  " << customer->get_p_num() << std::endl;
		ss << "  Age:  " << customer->get_age() << std::endl;
		ss << "  Customer number:  " << customer->get_cust_num() << std::endl << std::endl;

		ss << "  Transactions:" << std::endl;
		for (int i = 0; i < transactions.size(); i++) {
			ss << "  Transaction " << i + 1 << ":  " << transactions[i]->process_tran() << std::endl;
		}
		std::cout << std::endl;
		return ss.str();
	}

	/**
	Deposits amount into account
	@param amt The deposit amount
	*/
	virtual void deposit(double amt) {
		balance += amt;
		std::string fees = get_fees();
		Transaction *tran = new Transaction(account_number, "Deposit", amt, fees); //Create a Transaction object and assign it to transaction vector.

		transactions.push_back(tran);
	}

	/**
	Withdraws amount from account
	@param amt The withdrawal amount
	*/
	virtual void withdraw(double amt) {
		balance -= amt;
		std::string fees = get_fees();
		Transaction *tran = new Transaction(account_number, "Withdraw", amt, fees); //Create a Transaction object and assign it to tran.

		transactions.push_back(tran);
	}
	// We want the Savings_Account and Checking_Account to implement this.
	virtual void add_interest() = 0;

};

class Savings_Account : public Account {
public:
	Savings_Account(Customer* cust, int id) : Account(cust, id) {}
	void deposit() {

	}
	void withdraw() {

	}
	void add_interest() {

	}
};

class Checking_Account : public Account {
public:
	Checking_Account(Customer* cust, int id) : Account(cust, id) {}
	void deposit() {

	}
	void withdraw() {

	}
	void add_interest() {

	}
};

#endif