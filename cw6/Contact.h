// Workshop <Workshop #6>
// Name: <doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <contact.h>
#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H_
#include <iostream>
namespace sict {


	const int MAX_CHAR = 20;

	class Contact {
	private:
		char name[MAX_CHAR+1];
		long long* phonenum;
		int nophonenum;
	public:
		void display() const;
		bool isEmpty() const;
		Contact();
		Contact(const char Name[], long long PhoneNum[], int NoPhone);
		~Contact();

		Contact(const Contact&);
		Contact& operator=(const Contact&);
		Contact& operator+=(const long long phoneNumber);
	};
}
#endif