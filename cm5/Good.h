// milestone5
// Name: <doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <Good.h>
#ifndef aid_GOOD_H
#define aid_GOOD_H

#include <iostream>
#include "Error.h"
#include "iGood.h"

namespace aid {
	const int MAX_SKU = 7;
	const int MAX_UNIT = 10;
	const int MAX_NAME = 75;
	const double TAX_RATE = 0.13;
	const int max_sku_length = MAX_SKU;
	const int max_name_length = MAX_NAME;
	const int max_unit_length = MAX_UNIT;

	class Good : public iGood
	{

		char type_pro;
		char sku_pro[MAX_SKU+1];
		char unit_pro[MAX_UNIT+1];
		char* name_pro;
		int qty_pro;
		int needed_pro;
		double price_pro;
		bool taxable_pro;
		//Error errorst;

	protected:
		Error er;
		void name(const char* nameAddress);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char* str);
		bool isClear() const;

	public:
		Good(char type = 'N');
		Good(const char* sku, const char* address, const char * unit, int onHand = 0, bool taxable = true, double beforeTax = 0.0, int needed = 0);
		Good(const Good& other);
		~Good();
		Good& operator=(const Good & other);
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char* address) const;
		double total_cost() const;
		void quantity(int units);
		void price(double price);
		void needed(int needed);
		bool isEmpty() const;
		char type() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char* address) const;
		bool operator>(const iGood& rhs) const;
		int operator+=(int units);
	};

	std::ostream& operator<<(std::ostream& os, const iGood& other);
	std::istream& operator>>(std::istream& is, iGood& other);
	double operator+=(double& total, const iGood& other);
	iGood* CreateGood();
}
#endif
