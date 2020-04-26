#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__
#include <iostream>

#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {
		double m_Interest;


	public:
		// TODO: constructor initializes balance and interest rate
		SavingsAccount(double /*ini_balance*/, double /*interest_rate*/);
		// TODO: perform month end transactions
		void monthEnd();
		// TODO: display inserts the account information into an ostream			
		void display(std::ostream& /*os*/) const;
	};
	//iAccount* CreateAccount(const char*, double);
}
#endif
