// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name    DoyeonKim           Date    2018-11-02             Reason
/////////////////////////////////////////////////////////////////

#ifndef AMA_DATE_H
#define AMA_DATE_H
namespace aid {

	const int min_year = 2018;
	const int max_year = 2038;
	const int min_date = 751098;

	const int NO_ERROR = 0;
	const int CIN_FAILED = 1;
	const int DAY_ERROR = 2;
	const int MON_ERROR = 3;
	const int YEAR_ERROR = 4;
	const int PAST_ERROR = 5;

	class Date {
		
		int year;
		int month;
		int day;
		int mdays(int, int)const;
		void errCode(int);
		int valid;
		int err;

	public:
		
		bool operator==(const Date&) const;
		bool operator!=(const Date&) const;
		bool operator<(const Date&) const;
		bool operator>(const Date&) const;
		bool operator<=(const Date&) const;
		bool operator>=(const Date&) const;

		Date();
		Date(int, int, int);

		int errCode() const;
		bool bad() const;
		
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};

	std::ostream& operator << (std::ostream&, Date&);
	std::istream& operator >> (std::istream&, Date&);
}
#endif