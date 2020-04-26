// milestone5
// Name: <doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <Date.cpp>
#include <iostream>
#include "Date.h"

namespace aid {

	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	int Date::errCode() const {
		return err;
	}

	void Date::errCode(int errorCode) {
		err = errorCode;
	}

	bool Date::bad() const {
		bool answer;
		if (err != NO_ERROR) {
			answer = true;
		}
		else {
			answer = false;
		}
		return answer;
	}


	Date::Date() {
		year = 0;
		month = 0;
		day = 0;
		valid = 0;
		errCode(NO_ERROR);
	}

	Date::Date(int y, int m, int d) {

		bool valid = true;

		if (y < min_year || y > max_year) {
			errCode(YEAR_ERROR);
			year = 0;
			month = 0;
			day = 0;
			valid = 0;
			valid = !(bad());
		}

		else if (m < 1 || m > 12) {
			errCode(MON_ERROR);
			year = 0;
			month = 0;
			day = 0;
			valid = 0;
			valid = !(bad());
		}

		else if (d < 1 || d > mdays(m, y)) {
			errCode(DAY_ERROR);
			year = 0;
			month = 0;
			day = 0;
			valid = 0;
			valid = !(bad());
		}

		else if (valid) {
			errCode(NO_ERROR);
			year = y;
			month = m;
			day = d;
			valid = (year * 372 + month * 31 + day);
		}
	}

	bool Date::operator==(const Date& rhs)const {
		if (this->year == rhs.year && this->month == rhs.month && this->day == rhs.day) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Date::operator!=(const Date& rhs)const {
		if (this->year != rhs.year || this->month != rhs.month || this->day != rhs.day) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Date::operator<(const Date& rhs)const {
		if (this->year < rhs.year || this->month < rhs.month || this->day < rhs.day) {
			return true;
		}
		else {
			return false;
		}
	}


	bool Date::operator>(const Date& rhs)const {
		if (this->year > rhs.year || this->month > rhs.month || this->day > rhs.day) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Date::operator<=(const Date& rhs)const {
		if (this->year <= rhs.year && this->month <= rhs.month && this->day <= rhs.day) {
			return true;
		}
		else {
			return false;
		}
	}


	bool Date::operator>=(const Date& rhs)const {
		if (this->year >= rhs.year && this->month >= rhs.month && this->day >= rhs.day) {
			return true;
		}
		else {
			return false;
		}
	}


	std::istream& Date::read(std::istream& istr) {
		int y;
		int m;
		int d;

		istr >> y;
		istr.ignore();
		istr >> m;
		istr.ignore();
		istr >> d;

		if (istr.fail()) {
			errCode(CIN_FAILED);
		}
		else if (min_year > y || y > max_year) {
			errCode(YEAR_ERROR);
		}
		else if (m < 1 || 12 < m) {
			errCode(MON_ERROR);
		}
		else if (1 > d || mdays(m, y) < d) {
			errCode(DAY_ERROR);
		}
		else if (min_date > (y * 372 + m * 31 + d)) {
			errCode(PAST_ERROR);
		}
		else {
			year = y;
			month = m;
			day = d;
		}
		return istr;
	}


	std::ostream& Date::write(std::ostream& ostr) const {
		ostr << year << "/";
		if (month <= 9) {
			ostr << "0";
		}
		ostr << month << "/";
		if (day <= 9) {
			ostr << "0";
		}
		ostr << day;
		return ostr;
	}

	std::ostream& operator << (std::ostream& out, Date& date) {
		date.write(out);
		return out;
	}

	std::istream& operator >> (std::istream& in, Date& date) {
		date.read(in);
		return in;
	}
}