// Workshop <Workshop #5>
// Name: <Doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <fraction.cpp>
// TODO: insert header files
#include <iostream>
#include "Fraction.h"
// TODO: continue the namespace
using namespace std;
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		den = -1;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int n, int d) {
		if (n >= 0 && d >= 0) {
			num = n;
			den = d;
			reduce();
		}
		else {
			den = -1;
			}
	}
	// TODO: implement the max query
	int Fraction::max() const {
		return (num > den) ? num : den;
	}
	// TODO: implement the min query
	int Fraction::min() const {
		return (num > den) ? den : num;
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  
		int mx = max();  

		for (int x = mn; x > 0; x--) 
		{ 
			if (mx % x == 0 && mn % x == 0) 
			{
				return x;
			}
		}
		return 1;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int tmp = gcd();
		num /= tmp;
		den /= tmp;

	}
	// TODO: implement the display query
	void Fraction::display() const {
		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else {
			if (den == 1) {
				cout << num;
			}
			else {
				cout << num << "/" << den;
			}
		}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		return (den == -1) ? true : false;
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction emp;
		if (!(isEmpty() || rhs.isEmpty())) {
			emp.num = den * rhs.num + num * rhs.den;
			emp.den = den * rhs.den;
		}
		return emp;
	}
	Fraction Fraction::operator*(const Fraction& rhs) const {
		Fraction emp;
		if (!(isEmpty() || rhs.isEmpty())) {
			emp.num = num * rhs.num;
			emp.den = den * rhs.den;
		}
		return emp;
	}

	bool Fraction::operator==(const Fraction& rhs) const {
		bool ft = false;
		if (!isEmpty()) {
			if ((num*rhs.den) == (den*rhs.num)) {
				ft = true;
			}
		}
		else 
		{
			ft = false;
		}
		return ft;
	}

	bool Fraction::operator!=(const Fraction& rhs) const {
		bool ft = false;
		if (!isEmpty()) {
			if ((num*rhs.den) != (den*rhs.num)) {
				ft = true;
			}
		}
		else 
		{
			ft = false;
		}
		return ft;
	}

	Fraction Fraction::operator+=(Fraction rhs) {
		*this = *this +rhs;
		reduce();
		return  *this;
	}
}
