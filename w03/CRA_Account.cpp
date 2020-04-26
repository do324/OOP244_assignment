#include <iostream>
#include <cstring>
#include <cstdio>
#include "CRA_Account.h"

//#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace sict {

	void CRA_Account::set(const char *familyName, const char *givenName, int sin) {
		if (sin >= min_sin && sin <= max_sin)

		{
			strncpy(familyname, familyName, max_name_length);
			strncpy(givenname, givenName, max_name_length);
			sinnum = sin;
		}

		else {

			sinnum = 0;


		}
	}
	

	bool CRA_Account::isEmpty() const {
		bool tf = false;
		if (sinnum <= 0) {
			tf = true;
		}
		return tf;
	}

	void CRA_Account::display() const {

		if (isEmpty()) {

			cout << "Account object is empty!" << endl;
		}
		else {

			
			cout << "Family Name: " << familyname << endl;
			cout << "Given Name : " << givenname << endl;
			cout << "CRA Account: " << sinnum << endl;

		}
	}
}