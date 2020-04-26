// Workshop <Workshop #9>
// Name: <doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <Date.cpp>
#include <iostream>
#include <cstring>
#include "Data.h"
using namespace std;

namespace sict {
    
	/*// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//
	bool readRow(std::istream& input, const char* name, double* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	bool readRow(std::istream& input, const char* name, int* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}*/


	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime, const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		double pp = (max(population, n) - min(population, n));
		pp = pp / 1000000;
		cout << fixed;
		cout.precision(2);
		cout << "Population change from " <<  year[0] << " to " << year[n - 1] << " is "<<  pp << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		auto before = violentCrime[0];
		auto after = violentCrime[n - 1];
		const char *trend = before < after ? "up" : "down";
		cout << "Violent Crime trend is " << trend << endl;

		// Q3 print the GTA number accurate to 0 decimal places
		double gta_de = average(grandTheftAuto, n) / 1000000;
		cout << fixed;
		cout.precision(2);
		cout << "There are " << (gta_de) << " million Grand Theft Auto incidents on average a year" << std::endl;

		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;
	}
}