// Workshop <Workshop 4>
// Name: <Doyeon Kim>
// Student #: <139766166 #>
// Course: OOP244 Fall 2018
// File: <Passenger.h>
// TODO: add file header comments here
// TODO: add header file guard here
#ifndef PASSENGER_H
#define PASSENGER_H
// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger {
	private:
		char pname[19];
		char desti[19];
	public:
		Passenger();
		Passenger(const char* name, const char* destination);
		bool isEmpty() const;
		void display() const;
	};
}
	
#endif