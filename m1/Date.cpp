// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name  DOYEON KIM             Date  2018/07/13               Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"
#include <iostream>
#include <iomanip>

namespace AMA {
	int Date::mdays(int mon, int year)const {
		int days[] = {
			31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1
		}
		;
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
	int Date::errCode()const {
		return readerr;
	}
	void Date::errCode(int errorCode) {
		readerr = errorCode;
	}
	bool Date::bad() const {
		bool answer;
		if (readerr != NO_ERROR) {
			answer = true;
		}
		else {
			answer = false;
		}
		return answer;
	}
	Date::Date() {
		year_ = 0;
		mon_ = 0;
		day_ = 0;
		valid = 0;
		readerr = NO_ERROR;
	}
	Date::Date(int year, int month, int day) {
		year_ = year;
		mon_ = month;
		day_ = day;
		valid = year * 372 + month * 13 + day;
		if (year_ > min_year && year_ < max_year) {
			if (month >= 1 && month <= 12) {
				int day_m = mdays(month, year);
				if (day >= 0 && day <= day_m) {
					readerr = NO_ERROR;
				}
				else {
					readerr = DAY_ERROR;
					year_ = 0;
					mon_ = 0;
					day_ = 0;
					valid = 0;
				}
			}
			else {
				readerr = MON_ERROR;
				year_ = 0;
				mon_ = 0;
				day_ = 0;
				valid = 0;
			}
		}
		else {
			readerr = YEAR_ERROR;
			year_ = 0;
			mon_ = 0;
			day_ = 0;
			valid = 0;
		}
	}
	bool Date::operator==(const Date& a)const {
		if (this->year_ == a.year_ && this->mon_ == a.mon_ && this->day_ == a.day_) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Date::operator!=(const Date& a)const {
		if (this->year_ != a.year_ || this->mon_ != a.mon_ || this->day_ != a.day_) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Date::operator<(const Date& a)const {
		if (this->year_ < a.year_ || this->mon_ < a.mon_ || this->day_ < a.day_) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Date::operator>(const Date& a)const {
		if (this->year_ > a.year_ || this->mon_ > a.mon_ || this->day_ > a.day_) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Date::operator<=(const Date& a)const {
		if (this->year_ <= a.year_ && this->mon_ <= a.mon_ && this->day_ <= a.day_) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Date::operator>=(const Date& a)const {
		if (this->year_ >= a.year_ && this->mon_ >= a.mon_ && this->day_ >= a.day_) {
			return true;
		}
		else {
			return false;
		}
	}
	std::istream& Date::read(std::istream& istr) {
		istr >> year_;
		istr.ignore();
		istr >> mon_;
		istr.ignore();
		istr >> day_;
		if (!(istr.fail())) {
			if (!(year_ >= min_year && year_ <= max_year)) {
				year_ = 0;
				mon_ = 0;
				day_ = 0;
				readerr = YEAR_ERROR;
			}
			else if (!(mon_ > 0 && mon_ <= 12)) {
				year_ = 0;
				mon_ = 0;
				day_ = 0;
				readerr = MON_ERROR;
			}
			else if (!(day_ > 0 && day_ <= mdays(mon_, year_))) {
				year_ = 0;
				mon_ = 0;
				day_ = 0;
				readerr = DAY_ERROR;
			}
			else {
				readerr = NO_ERROR;
			}
		}
		else {
			readerr = CIN_FAILED;
		}
		return istr;
	}
	std::ostream& Date::write(std::ostream& ostr) const {
		ostr << year_ << "/";
		if (mon_ <= 9) {
			ostr << "0";
		}
		ostr << mon_ << "/";
		if (day_ <= 9) {
			ostr << "0";
		}
		ostr << day_;
		return ostr;
	}
	std::istream& operator >> (std::istream& in, Date& d) {
		d.read(in);
		return in;
	}
	std::ostream& operator<<(std::ostream& out, const Date& d) {
		d.write(out);
		return out;
	}
}