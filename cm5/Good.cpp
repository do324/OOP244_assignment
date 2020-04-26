// milestone5
// Name: <doyeon kim>
// Student #: <Your Student #139766166>
// Course: OOP244 Fall 2018
// File: <Good.cpp>
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Good.h"
using namespace std;
namespace aid {
	Good::Good(char type) {
		type_pro = type;
		sku_pro[0] = '\0';
		unit_pro[0] = '\0';
		name_pro = nullptr;
		qty_pro = 0;
		needed_pro = 0;
		price_pro = 0.0;
		taxable_pro = false;
	}
	Good::Good(const char * sku, const char * name, const char * unit, int quantity, bool taxable, double price, int needed) {
		bool notNull = sku != nullptr && name != nullptr && unit != nullptr;
		if (notNull) {
			strncpy(sku_pro, sku, strlen(sku));
			sku_pro[strlen(sku)] = '\0';
			Good::name(name);
			strncpy(unit_pro, unit, strlen(unit));
			unit_pro[strlen(unit)] = '\0';
		}
		qty_pro = quantity;
		taxable_pro = taxable;
		price_pro = price;
		needed_pro = needed;
	}
	Good::Good(const Good & other) {
		*this = other;
	}
	Good & Good::operator=(const Good & other) {
		if (this != &other) {
			int sku_l = strlen(other.sku_pro);
			int unit_l = strlen(other.unit_pro);
			type_pro = other.type_pro;
			qty_pro = other.qty_pro;
			needed_pro = other.needed_pro;
			price_pro = other.price_pro;
			taxable_pro = other.taxable_pro;
			name(other.name_pro);
			strncpy(sku_pro, other.sku_pro, sku_l);
			sku_pro[sku_l] = '\0';
			strncpy(unit_pro, other.unit_pro, unit_l);
			unit_pro[unit_l] = '\0';
		}
		return *this;
	}
	Good::~Good() {
		delete[] name_pro;
	}
	std::fstream & Good::store(std::fstream & file, bool newLine) const {
		file << type_pro << ',' << sku_pro << ',' << name_pro << ',' << unit_pro << ',' << taxable_pro << ',' << price_pro << ',' << qty_pro << ',' << needed_pro;
		if (newLine)
			file << endl;
		return file;
	}
	std::fstream & Good::load(std::fstream & file) {
		char the_sku[MAX_SKU];
		char the_name[MAX_NAME];
		char the_unit[MAX_UNIT];
		char tax;
		double price;
		bool taxable;
		int qty, needed;
		if (file.is_open()) {
			file.getline(the_sku, MAX_SKU, ',');
			the_sku[strlen(the_sku)] = '\0';
			file.getline(the_name, MAX_NAME, ',');
			the_name[strlen(the_name)] = '\0';
			file.getline(the_unit, MAX_UNIT, ',');
			the_unit[strlen(the_unit)] = '\0';
			file >> tax;
			if (tax == '1')
				taxable = true; else if (tax == '0')
				taxable = false;
			file.ignore();
			file >> price;
			file.ignore();
			file >> qty;
			file.ignore();
			file >> needed;
			file.ignore();
			*this = Good(the_sku, the_name, the_unit, qty, taxable, price, needed);
		}
		return file;
	}
	std::ostream & Good::write(std::ostream & os, bool linear) const {
		if (!(er.isClear())) {
			os << er.message();
		}
		else if (linear) {
			os << setw(MAX_SKU) << left << sku_pro << '|'
				<< setw(20) << left << name_pro << '|'
				<< setw(7) << right << fixed << setprecision(2) << cost() << '|'
				<< setw(4) << right << qty_pro << '|'
				<< setw(10) << left << unit_pro << '|'
				<< setw(4) << right << needed_pro << '|';
		}
		else {
			os << " Sku: " << sku_pro << endl
				<< " Name (no spaces): " << name_pro << endl
				<< " Price: " << price_pro << endl;
			if (taxable_pro)
				os << " Price after tax: " << cost() << endl; else {
				os << " Price after tax:  N/A" << endl;
			}
			os << " Quantity on Hand: " << qty_pro << ' ' << unit_pro << endl
				<< " Quantity needed: " << needed_pro;
		}
		return os;
	}
	std::istream & Good::read(std::istream & is) {
		char taxed;
		char * address = new char[MAX_NAME + 1];
		int qty, need;
		double _price;
		if (!is.fail()) {
			cout << " Sku: ";
			is >> sku_pro;
			cin.ignore();
			cout << " Name (no spaces): ";
			is >> address;
			name(address);
			cout << " Unit: ";
			is >> unit_pro;
			cout << " Taxed? (y/n): ";
			is >> taxed;
			if (!is.fail()) {
				er.clear();
				if (taxed) {
					bool y_valid = taxed == 'y' || taxed == 'Y';
					bool n_valid = taxed == 'n' || taxed == 'N';
					if (y_valid)
						taxable_pro = true;
					if (n_valid)
						taxable_pro = false;
					if (!(y_valid || n_valid)) {
						is.setstate(std::ios::failbit);
						er.message("Only (Y)es or (N)o are acceptable");
						return is;
					}
				}
			}
			else {
				is.setstate(std::ios::failbit);
				er.message("Only (Y)es or (N)o are acceptable");
				return is;
			}
			cout << " Price: ";
			is >> _price;
			if (is.fail()) {
				er.clear();
				is.setstate(ios::failbit);
				er.message("Invalid Price Entry");
				return is;
			}
			else
				price(_price);
			cout << " Quantity on hand: ";
			is >> qty;
			if (is.fail()) {
				er.clear();
				er.message("Invalid Quantity Entry");
				is.setstate(ios::failbit);
				return is;
			}
			else
				quantity(qty);
			cout << " Quantity needed: ";
			is >> need;
			cin.ignore();
			if (is.fail()) {
				er.clear();
				er.message("Invalid Quantity Needed Entry");
				is.setstate(ios::failbit);
				return is;
			}
			else
				needed(need);
			if (!is.fail()) {
				er.clear();
			}
		}
		return is;
	}
	bool Good::operator==(const char * rhs) const {
		if (rhs == sku())
			return true; else
			return false;
	}
	double Good::total_cost() const {
		return qty_pro * cost();
	}
	void Good::quantity(int quantity) {
		qty_pro = quantity;
	}
	void Good::price(double price) {
		price_pro = price;
	}
	void Good::needed(int needed) {
		needed_pro = needed;
	}
	bool Good::isEmpty() const {
		if (name_pro == nullptr)
			return true; else
			return false;
	}
	char Good::type() const {
		return type_pro;
	}
	int Good::qtyNeeded() const {
		return needed_pro;
	}
	int Good::quantity() const {
		return qty_pro;
	}
	bool Good::operator>(const char * rhs) const {
		if (strcmp(sku_pro, rhs) > 0)
			return true; else
			return false;
	}
	bool Good::operator>(const iGood & rhs) const {
		if (strcmp(name_pro, rhs.name()) > 0)
			return true; else
			return false;
	}
	int Good::operator+=(int units) {
		if (units > 0) {
			qty_pro += units;
			return qty_pro;
		}
		else
			return qty_pro;
	}
	void Good::name(const char * name) {
		if (name != nullptr) {
			int length = strlen(name);
			name_pro = new char[length + 1];
			for (int i = 0; i < length; i++) {
				name_pro[i] = name[i];
			}
			name_pro[length] = '\0';
		}
		else if (name == nullptr) {
			delete[] name_pro;
			name_pro = nullptr;
		}
	}
	const char * Good::name() const {
		if (name_pro != nullptr)
			return name_pro; else
			return nullptr;
	}
	const char * Good::sku() const {
		return sku_pro;
	}
	const char * Good::unit() const {
		return unit_pro;
	}
	bool Good::taxed() const {
		return taxable_pro;
	}
	double Good::price() const {
		return price_pro;
	}
	double Good::cost() const {
		if (taxable_pro)
			return price() * (TAX_RATE + 1); else
			return price();
	}
	void Good::message(const char * err_message) {
		if (err_message != nullptr)
			er.message(err_message);
	}
	bool Good::isClear() const {
		return er.isClear();
	}
	std::ostream& operator<<(std::ostream& os, const iGood& other) {
		return other.write(os, true);
	}
	std::istream& operator>>(std::istream& is, iGood& other) {
		return other.read(is);
	}
	

	double operator+= (double& total, const iGood& other)
	{
		return other.total_cost() + total;
	}
}

