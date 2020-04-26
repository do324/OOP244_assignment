//Doyeon Kim 139766166
// TODO: add file header comments here
#include <iostream>
#include <cstring>
// TODO: add your headers here
#include "Passenger.h"

// TODO: continue your namespace here
using namespace std;
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		pname[0] = '\0';
		desti[0] = '\0';
		deyear = 0;
		demonth = 0;
		deday= 0;
	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination) {
		if (name == '\0' || destination == '\0') {
			*pname = '\0';
			*desti = '\0';
			deyear = 0;
			demonth = 0;
			deday = 0;

		}
		else if (name == nullptr && destination == nullptr) {
			*pname = '\0';
			*desti = '\0';
		}
		else {
			strcpy(pname, name);
			strcpy(desti, destination);
			deyear = 2017;
			demonth = 7;
			deday = 1;
		}
	}
	Passenger::Passenger(const char *name, const char *destination, int years, int months, int days) {
		if (name != nullptr && strlen(name) > 0 
			&&destination != nullptr && strlen(destination) > 0 
			&&years > 2016 && years < 2021 && months > 0 && months < 13 && days > 0 && days < 32) {
			strcpy(pname, name);
			strcpy(desti, destination);
			deyear = years;
			demonth = months;
			deday = days;
		}
		else {
			*pname = '\0';
			*desti = '\0';
			deyear = 0;
			demonth = 0;
			deday = 0;
		}
	}
	
	bool Passenger::canTravelWith(const Passenger& together) const {
		return ( std::strcmp( this->desti, together.desti ) == 0 ) 
                && this->deyear == together.deyear 
                && this->demonth == together.demonth 
                && this->deday == together.deday ;
	}
	
	const char* Passenger::name() const {
		if (this->isEmpty())
		{
			string empty_str;
		}
		return pname;
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
	/*void Passenger::display() const {
		if (true == this->isEmpty())
		{
			cout << "No passenger!" << endl;
		}
		else {
			cout << pname << " - " << desti << endl;
		}
	}*/
	void Passenger::display() const {
		cout << pname << " - " << desti << " on " << deyear << "/";
		if (demonth < 10) {
			cout << "0" << demonth << "/";
			if (deday < 10) 
			{
				cout << deday << endl;
			}
			else {
				cout << deday << endl;
			}
		}
		else {
			cout << demonth << deday << endl;
		}
	}
}



