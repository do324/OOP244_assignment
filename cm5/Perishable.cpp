// milestone5
// Name: <doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <perishable.cpp>
#include <iostream>
#include <fstream>
#include "Perishable.h"

using namespace std;

namespace aid {
	Perishable::Perishable() : Good('P') {
		er.clear();
	}


	std::fstream& Perishable::store(std::fstream& file, bool newLine) const
	{
		Good::store(file, false);
		file << ',';
		ex_date.write(file);

		if (newLine)
		{
			file << std::endl;
		}

		return file;
	}



	std::fstream& Perishable::load(std::fstream& file)
	{
		Good::load(file);
		ex_date.read(file);

		file.ignore();

		return file;
	}

	std::ostream & Perishable::write(std::ostream & os, bool linear) const {
		Good::write(os, linear);
		if (isClear() && !isEmpty()) {
			if (linear)
				ex_date.write(os); 
		else {
				os << "\n Expiry date: ";
				ex_date.write(os);
			}
		}
		return os;
	}



	std::istream& Perishable::read(std::istream& is)
	{
		Good::read(is);

		if (!is.fail())
		{
			std::cout << " Expiry date (YYYY/MM/DD): ";

			Date tempDate;
			tempDate.read(is);

			int errCode = tempDate.errCode();

			if (errCode)
			{
				is.setstate(std::ios::failbit);

				if (errCode == CIN_FAILED)
				{
					er.message("Invalid Date Entry");
				}

				else if (errCode == YEAR_ERROR)
				{
					er.message("Invalid Year in Date Entry");
				}

				else if (errCode == MON_ERROR)
				{
					er.message("Invalid Month in Date Entry");
				}

				else if (errCode == DAY_ERROR)
				{
					
					er.message("Invalid Day in Date Entry");
				}
				else 
				{
					er.message("Invalid Expiry in Date Entry");
				}
			}

			else
			{
				er.clear();
				ex_date = tempDate;
			}
		}



		return is;
	}

	const Date& Perishable::expiry() const
	{
		return ex_date;
	}

}