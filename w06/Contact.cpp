#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {

	Contact::Contact() {
		name[0] = '\0';
		phonenum = nullptr;
		nophonenum = 0;
	}

	bool Contact::isEmpty()
		const {
		bool ret = true;
		if (name[0] != '\0') {
			ret = false;
		}
		else if (phonenum != nullptr) {
			ret = false;
		}

		return ret;
	}

	Contact:: ~Contact() {
		delete[] phonenum;
		phonenum = nullptr;
	}

	Contact::Contact(const char Name[], long long PhoneNum[], int NoPhone) {
		if (isEmpty() == false) {
			strncpy(name, Name, 19);
			nophonenum = NoPhone;

			if (nophonenum > 0) {
				long long * p = new long long[nophonenum];
				for (int i = 0; i < nophonenum; i++) {
					p[i] = PhoneNum[i];
				}
				phonenum = p;
			}
			else {
				phonenum = nullptr;
			}
		}
		else {
			for (int i = 0; i < 21; i++) {
				name[i] = '\0';
			}
			phonenum = nullptr;
			nophonenum = 0;
		}

	}

	void Contact::display()
		const {
		if (isEmpty() == true) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << name << endl;
			for (int i = 0; i < nophonenum; i++) {
				long long a = phonenum[i], wholenum;
				int second, b = 10000000, c = int(a / b), d, e;
				if (c > 1001 && c < 99999) {
					e = c % 1000;
					d = c / 1000;
					wholenum = a % 1000000;
					int temp = a / 10000;
					int first = temp % 1000;
					second = wholenum % 10000;
					cout << "(+" << d << ")" << " " << e << " " << first << "-" << second << endl;
				}
			}
		}
	}

	Contact::Contact(const Contact & Phone) {
		if (isEmpty() == false) {
			strncpy(name, Phone.name, 19);
			nophonenum = Phone.nophonenum;

			if (nophonenum > 0) {
				long long * p = new long long[nophonenum];
				for (int i = 0; i < nophonenum; i++) {
					p[i] = Phone.phonenum[i];
				}
				phonenum = p;
			}
			else {
				phonenum = nullptr;
			}
		}
		else {
			for (int i = 0; i < 21; i++) {
				name[i] = '\0';
			}
			phonenum = nullptr;
			nophonenum = 0;
		}
	}

	Contact & Contact::operator = (const Contact & Phone) {
		if (this != &Phone) {
			if (phonenum != nullptr) {
				delete[] phonenum;
				phonenum = nullptr;
			}

			nophonenum = Phone.nophonenum;
			strncpy(name, Phone.name, 19);

			phonenum = new long long[nophonenum];
			for (int i = 0; i < nophonenum; i++) {
				phonenum[i] = Phone.phonenum[i];
			}
		}
		return *this;
	}

	Contact & Contact::operator += (const long long phoneNum) {
		long long * temp;
		temp = new long long[nophonenum + 1];

		for (int i = 0; i < nophonenum; i++) {
			temp[i] = phonenum[i];
		}
		nophonenum++;

		if (phonenum != nullptr) {
			delete[] phonenum;
		}

		phonenum = new long long[nophonenum];
		for (int i = 0; i < nophonenum; i++) {
			phonenum[i] = temp[i];
		}
		phonenum[nophonenum - 1] = phoneNum;

		delete[] temp;
		return *this;
	}
};