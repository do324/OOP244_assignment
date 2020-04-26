// Workshop <Workshop #8>
// Name: <doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <Allocator.cpp>
#include "SavingsAccount.h" 
#include "ChequingAccount.h"
using namespace std;
namespace sict {
	// define interest rate
	//
	const double interest = 0.05;
	const double transaction = 0.50;
	const double monthly = 2.00;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* type, double initBalance) {
		iAccount *p = nullptr;
		if (type[0] == 'S') {
			p = new SavingsAccount(initBalance, interest);
		}
		else if (type[0] == 'C') {
			p = new ChequingAccount(initBalance, transaction, monthly);
		}
		return p;
	}
}
