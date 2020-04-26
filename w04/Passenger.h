//Doyeon Kim 139766166
// TODO: add file header comments here
// TODO: add header file guard here
#ifndef PASSENGER_H
#define PASSENGER_H
// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger {
	private:
		char pname[32];
		char desti[32];
		int deyear, demonth, deday;
	public:
		Passenger();
		Passenger(const char *name, const char *destination, int years, int months, int days);
		Passenger(const char *name, const char* destination);
		bool canTravelWith(const Passenger&) const;
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		
	};
}

#endif
