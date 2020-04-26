#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account {
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;

	private:
		char familyname[40];
		char givenname[40];
		int sinnum = 0;
		

	};

}
#endif
