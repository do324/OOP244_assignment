// Workshop <Workshop #8>
// Name: <doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <Account.cpp>
#include <iostream>
#include "Account.h"
using namespace std;

namespace sict {
	Account::Account(double ini_balance) {
		if (ini_balance > 0)
			m_balance = ini_balance;
		else
			m_balance = 0;
	}
	bool Account::credit(double add_amount) {
		if (add_amount > 0) {
			m_balance += add_amount;
			return true;
		} else {
			return false;
		}
	}
	bool Account::debit(double subtract_amount) {
		if (subtract_amount > 0) {
			m_balance -= subtract_amount;
			return true;
		} else {
			return false;
		}
	}
	double Account::balance() const {
		return m_balance;
	}
}
	