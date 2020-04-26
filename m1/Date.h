// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//DOYOEN KIM
//139766166

//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include<iostream>
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4
namespace AMA {
	const int min_year = 2000;
	const int max_year = 2030;
	class Date {
		int mdays(int mon, int year)const;
		int year_;
		int mon_;
		int day_;
		void errCode(int errorCode);
		int valid;
		int readerr;
	public:
		bool operator==(const Date& D)const;
		bool operator!=(const Date& D)const;
		bool operator<(const Date& D)const;
		bool operator>(const Date& D)const;
		bool operator<=(const Date& D)const;
		bool operator>=(const Date& D)const;
		Date();
		Date(int year, int month, int day);
		int errCode()const;
		bool bad()const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	}
	;
	std::ostream& operator<<(std::ostream& ostr, const Date& date);
	std::istream& operator>>(std::istream& istr, Date& date);
}
#endif