// Workshop <Workshop 4>
// Name: <Doyeon Kim>
// Student #: <139766166 #>
// Course: OOP244 Fall 2018
// File: <Passenger.cpp>
// TODO: add file header comments here
#include <iostream>
#include <cstring>
#include <string.h>
// TODO: add your headers here
#include "Passenger.h"

// TODO: continue your namespace here
using namespace std;
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		pname[0] = '\0';
		desti[0] = '\0';
	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination) {
		if (name == '\0' || destination == '\0') {
			*pname = '\0';
			*desti = '\0';
		}
		else if (name == nullptr && destination == nullptr) {
			*pname = '\0';
			*desti = '\0';
		}
		else {
			strncpy(pname, name, 18);
			pname[18] = '\0';

			strncpy(desti, destination, 18);
			desti[18] = '\0';
		}	
	}


	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		bool tf;
		if (*pname == '\0' || *desti == '\0' || desti == nullptr || pname == nullptr) {
			tf = true;
		}
		else {
			tf = false;
		}
		return tf;
	}
	// TODO: implement display query here
	void Passenger::display() const {
		if (true == this->isEmpty())
		{
			cout << "No passenger!" << endl;
		}
		else {
			cout << pname << " - " << desti << endl;
		}
	}
}


