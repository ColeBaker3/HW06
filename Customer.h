#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>

using std::string;

/**
The Bank has Customers.  Each Customer has a name, address, age, and telephone number.
Additionally, there are specialized types of Customers: Adult, Senior, and Student.
Each type of Customer has its own checking and savings interest rates,
as well as its own checking and overdraft fees.
@author: Ed Walker
*/
class Customer
{
protected: //allow the classes Adult, Senior, and Student to access these variables
		   //define the basic info that every customer will have
	string name, address, phone_num;
	int age, cust_num;
public:
	Customer(string _name, string _address, string _phone_num, int _age, int _cust_num) {
		name = _name;
		address = _address;
		phone_num = _phone_num;
		age = _age;
		cust_num = _cust_num;
	}

	//Allow a customer's basic information to be accessed

	string get_name() {
		return name;
	}
	string get_address() {
		return address;
	}
	int get_age() {
		return age;
	}
	string get_p_num() { //phone number
		return phone_num;
	}
	int get_cust_num() {
		return cust_num;
	}
	void set_name(string _name) {
		name = _name;
	}
	void set_address(string _address) {
		address = _address;
	}
	void set_age(int _age) {
		age = _age;
	}
	void set_p_num(string _phone_num) {
		phone_num = _phone_num;
	}
	void set_cust_num(int _cust_num) {
		cust_num = _cust_num;
	}
	virtual int get_check_charge() = 0;
	virtual int get_overdraft_penalty() = 0;

};

class Senior : public Customer {
private:
	const int CHECK_CHARGE = 40;
	const int OVERDRAFT_PENALTY = 10;
public:
	Senior(string _name, string _address, string _phone_num, int _age, int _cust_num) : Customer(_name, _address, _phone_num, _age, _cust_num) {};
	virtual int get_check_charge() {
		return CHECK_CHARGE;
	}
	virtual int get_overdraft_penalty() {
		return OVERDRAFT_PENALTY;
	}
};

class Student : public Customer {
private:
	const int CHECK_CHARGE = 40;
	const int OVERDRAFT_PENALTY = 5;
public:
	Student(string _name, string _address, string _phone_num, int _age, int _cust_num) : Customer(_name, _address, _phone_num, _age, _cust_num) {};
	virtual int get_check_charge() {
		return CHECK_CHARGE;
	}
	virtual int get_overdraft_penalty() {
		return OVERDRAFT_PENALTY;
	}
};

class Adult : public Customer { //access the public objects from customer (such as get_name(), etc.)
private:
	const int CHECK_CHARGE = 45;
	const int OVERDRAFT_PENALTY = 5;
public:
	Adult(string _name, string _address, string _phone_num, int _age, int _cust_num) : Customer(_name, _address, _phone_num, _age, _cust_num) {};
	virtual int get_check_charge() {

		return CHECK_CHARGE;
	}
	virtual int get_overdraft_penalty() {
		return OVERDRAFT_PENALTY;
	}
};

#endif