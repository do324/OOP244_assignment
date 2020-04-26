///////////////////////////////////////////////////////////
// Name			Date		          Reason
// Doyeon Kim       2018/09/30            allow longer names 
///////////////////////////////////////////////////////////
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>



namespace sict
{
	const int max_name_length = 40;
	const int max_yrs = 4;
	const int minSin = 100000000;
	const int maxSin = 999999999;

	class CRA_Account
	{
	public:
		CRA_Account(); 
		void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance);
		void setEmpty();
		void display() const;
		bool isEmpty();
		bool validsin(int sin);
		int Getallyears(); 
	private:
		char familyname[max_name_length + 1];
		char givenname[max_name_length + 1];
		int sinnum;
		int yeartax[max_yrs];
		double balancetax[max_yrs];
		int allyears;
	};

}
#endif 
