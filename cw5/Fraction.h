// Workshop <Workshop #5>
// Name: <Doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <fraction.h>
// TODO: header file guard
#ifndef FRACTION_H
#define FRACTION_H
// TODO: create namespace
namespace sict {
	    // TODO: define the Fraction class
	class Fraction {
	private:
        // TODO: declare instance variables
		int num;
		int den;
	   // TODO: declare private member functions
		int gcd() const; 
		int max() const; 
		int min() const; 
		
    public:
		// TODO: declare public member functions
		void reduce(); 
		Fraction();
		Fraction(int n, int d);

		bool isEmpty() const;
		void display() const;
		
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction operator+=(Fraction s);
     };
}
#endif

