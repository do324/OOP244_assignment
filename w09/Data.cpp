#include <iostream>
#include <cstring>
#include "Data.h"
using namespace std;

namespace sict {
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