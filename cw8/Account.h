// Workshop <Workshop #8>
// Name: <doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <Account.h>
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include <iostream>
#include "iAccount.h"	

namespace sict {

	class Account : public iAccount 
	{
		
		double m_balance;
	
	protected:
		double balance() const;
	
	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double ini_balance);
		// TODO: credit adds +ve amount to the balance 
		bool credit(double add_amount);
		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double subtract_amount );
		
		
	};
	//iAccount* CreateAccount(const char*, double);
}
#endif
