///////////////////////////////////////////////////////////
// Name			Date		          Reason
// Doyeon Kim       2018/09/30            allow longer names 
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
#include "CRA_Account.h"

//#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace sict
{
	CRA_Account::CRA_Account() 
	{
		familyname[0] = '\0';   
		givenname[0] = '\0';  
		sinnum = 0;
		for (size_t lc = 0; lc < max_yrs; lc++) yeartax[lc] = 0;
		for (size_t lc = 0; lc < max_yrs; lc++) balancetax[lc] = 0.0;
		allyears = 0;
	}

	void CRA_Account::setEmpty()
	{
		familyname[0] = '\0';
		givenname[0] = '\0';
		sinnum = 0;
	}

	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		if (validsin(sin) && '\0' != familyName && '\0' != givenName)
		{
			strncpy(familyname, familyName, max_name_length);
			strncpy(givenname, givenName, max_name_length);
			sinnum = sin;	
			allyears = 0;
		}
		else
		{
			setEmpty();
		}
	}

	void CRA_Account::set(int year, double balance)
	{
	    if (0 != sinnum && allyears < max_yrs)
		{
			if (0 == yeartax[allyears])
			{
				yeartax[allyears] = year;
				balancetax[allyears] = balance;
				allyears++;
			}
		}
	}

	bool CRA_Account::validsin(int sin)
	{
		int sum = 0;
		//int right = sin % 10;
		int even[4] = { (((sin / 10) % 10) * 2), (((sin / 1000) % 10) * 2), (((sin / 100000) % 10) * 2), (((sin / 10000000) % 10) * 2) };
		int odd[4] = { (((sin / 100) % 10)), (((sin / 10000) % 10)), (((sin / 1000000) % 10)), (((sin / 100000000) % 10)) };

		for (int i = 0; i < 4; i++)
		{
			sum += ((((even[i] / 1) % 10) + ((even[i] / 10) % 10)));
			sum += odd[i];
		}

		int upIntTen = ((sum + 9) / 10) * 10;

		if (((upIntTen - sum) == (sin / 1) % 10) && sin >= minSin && sin <= maxSin)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void CRA_Account::display() const
	{
		if (0 != sinnum|| '\0' != familyname || '\0' != givenname)
		{
			std::cout << "Family Name: " << this->familyname <<std::endl;
			std::cout << "Given Name : " << this->givenname << std::endl;
			std::cout << "CRA Account: " << this->sinnum << std::endl;
			std::cout.setf(std::ios::fixed);
			std::cout.precision(2);

			for (int i = 0; i < max_yrs; i++)
			{
				if (yeartax[i] == 0) 
					break;
				else
				{
					std::cout << "Year " << "("<<yeartax[i]<<")";
					if (balancetax[i] > 2)
					{
						std::cout << " balance owing: " << (balancetax[i]) << std::endl;  // <--- Changed.
					}
					else if (balancetax[i] < -2)
					{
						std::cout << " refund due: " << (-balancetax[i]) << std::endl;  // <--- Changed.
					}
					else
					{
						std::cout << " No balance owing or refund due!" << std::endl;
					}
				}
			}
			std::cout.unsetf(std::ios::fixed);
			std::cout.precision(6);

		}
		else
		{
			std::cout << "Account object is empty!" << std::endl << std::endl;
		}
	}

	bool CRA_Account::isEmpty()
	{
		if (0 == this->sinnum || this->sinnum <= minSin || this->sinnum >= maxSin || '\0' == this->givenname[0] || '\0' == this->familyname[0])
		{  
			return true;
		}
		else
		{
			return false;
		}
	}

	int CRA_Account::Getallyears() { return allyears; }  
}  