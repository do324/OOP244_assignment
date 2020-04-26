// Workshop <Workshop #8>
// Name: <doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <CequingAccount.cpp>
///////////////////////////////////////////////////
#include <math.h> 
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double inibalance, double transaction_fee, double month_fee) : Account(inibalance) {
		(transaction_fee > 0) ? m_transaction = transaction_fee : m_transaction = 0;
		(month_fee > 0) ? m_monthend = month_fee : m_monthend = 0.0;
	}


	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double amtToCredit) {
		Account::debit(m_transaction);
		return Account::credit(amtToCredit);
	}




	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//

		bool ChequingAccount::debit(double amtToDebit) {
			return Account::debit(amtToDebit + m_transaction);
		}

	// monthEnd debits month end fee
	//
		void ChequingAccount::monthEnd() {
			Account::debit(m_monthend + m_transaction);
		}



	// display inserts account information into ostream os
	//
		void ChequingAccount::display(std::ostream& os) const {
			os << "Account type: Chequing" << std::endl;
			os.unsetf(std::ios::floatfield);
			os.precision(2);
			os.setf(std::ios::fixed, std::ios::floatfield);
			os << "Balance: $" << round(Account::balance()) << std::endl;
			os << "Per Transaction Fee: " << m_transaction << std::endl;
			os << "Monthly Fee: " << m_monthend << std::endl;

		}



}