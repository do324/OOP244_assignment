#include <iostream>
#include "SavingsAccount.h"
using namespace std;

sict::SavingsAccount::SavingsAccount(double ini_balance, double interest_rate) : Account(ini_balance) {
		if (interest_rate > 0)
			m_Interest = interest_rate;
		else
			m_Interest = 0;
	}
	void sict:: SavingsAccount::monthEnd() {
		double interest = (balance() * m_Interest);
		credit(interest);
	}
	void sict::SavingsAccount::display(ostream & os) const {
		os << "Account type: Savings" << endl;
		os.precision(2);											// change to 2 decimal places and fixed 
		os.setf(ios::fixed);
		os << "Balance: $" << balance() << endl;
		os << "Interest Rate (%): " << (m_Interest* 100) << endl;
		os.precision(6);
		os.unsetf(ios::fixed);
	}



