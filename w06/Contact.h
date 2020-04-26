#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
namespace sict {

	class Contact {
	private:
		char name[20];
		long long* phonenum;
		int nophonenum;
	public:
		void display() const;
		bool isEmpty() const;
		Contact();
		Contact(const char Name[], long long PhoneNum[], int NoPhone);
		~Contact();

		Contact(const Contact& P);
		Contact& operator=(const Contact&);
		Contact& operator+=(const long long phoneNumber);
	};
}
#endif