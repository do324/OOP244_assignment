// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

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
			os << "Balance: $" << balance() << std::endl;
			os << "Per Transaction Fee: " << m_transaction << std::endl;
			os << "Monthly Fee: " << m_monthend << std::endl;

		}



}