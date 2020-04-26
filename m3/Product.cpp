#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Product.h"
#include "ErrorState.h"
using namespace std;
using namespace AMA;
namespace AMA {
	Product::Product(char type) {
		type_product = type;
		sku_product[0] = '\0';
		unit_product[0] = '\0';
		ad_name_product = nullptr;
		quantity_pro_hand = 0;
		quantity_pro_need = 0;
		beforetax_single_pro = 0.0;
		taxable_pro = false;
	}
	Product::Product(const char *sku, const char *address, const char *unit, int onHand, bool taxable, double beforeTax, int needed) {
		name(address);
		strncpy(sku_product, sku, max_sku_length);
		sku_product[max_sku_length] = '\0';
		strncpy(unit_product, unit, max_unit_length);
		unit_product[max_unit_length] = '\0';
		quantity_pro_hand = onHand;
		quantity_pro_need = needed;
		beforetax_single_pro = beforeTax;
		taxable_pro = taxable;
	}
	Product::~Product() {
		delete[] ad_name_product;
	}
	Product::Product(const Product &second) {
		int length = strlen(second.ad_name_product);
		type_product = second.type_product;
		strncpy(sku_product, second.sku_product, max_sku_length);
		sku_product[max_sku_length] = '\0';
		strncpy(unit_product, second.unit_product, max_unit_length);
		unit_product[max_unit_length] = '\0';
		quantity_pro_hand = second.quantity_pro_hand;
		quantity_pro_need = second.quantity_pro_need;
		beforetax_single_pro = second.beforetax_single_pro;
		taxable_pro = second.taxable_pro;
		if (second.ad_name_product != nullptr) {
			ad_name_product = nullptr;
			ad_name_product = new char[length];
			for (int i = 0; i < length; ++i) {
				ad_name_product[i] = second.ad_name_product[i];
			}
			ad_name_product[length] = '\0';
		}
		else {
			ad_name_product = nullptr;
		}
	}
	void Product::name(const char *nameAddress) {
		if (nameAddress != nullptr) {
			int length = strlen(nameAddress);
			ad_name_product = new char[length];
			for (int i = 0; i < length; ++i) {
				ad_name_product[i] = nameAddress[i];
			}
			ad_name_product[length] = '\0';
		}
	}
	const char *Product::name() const {
		return (ad_name_product[0] == '\0') ? nullptr : ad_name_product;
	}
	const char *Product::sku() const {
		return sku_product;
	}
	const char *Product::unit() const {
		return unit_product;
	}
	bool Product::taxed() const {
		return taxable_pro;
	}
	double Product::price() const {
		return beforetax_single_pro;
	}
	double Product::cost() const {
		return (taxable_pro) ? price() * (TAX_RATE + 1) : price();
	}
	void Product::message(const char *addressError) {
		errorst.message(addressError);
	}
	bool Product::isClear() const {
		return errorst.isClear();
	}
	Product &Product::operator=(const Product &second) {
		if (this != &second) {
			type_product = second.type_product;
			strncpy(sku_product, second.sku(), max_sku_length);
			strncpy(unit_product, second.unit(), max_unit_length);
			quantity_pro_hand = second.quantity_pro_hand;
			quantity_pro_need = second.quantity_pro_need;
			beforetax_single_pro = second.beforetax_single_pro;
			taxable_pro = second.taxable_pro;
			delete[] ad_name_product;
			if (second.ad_name_product != nullptr) {
				int length = strlen(second.ad_name_product);
				ad_name_product = new char[length];
				for (int i = 0; i < length; ++i) {
					ad_name_product[i] = second.ad_name_product[i];
				}
				ad_name_product[length] = '\0';
			}
			else {
				ad_name_product = nullptr;
			}
		}
		return *this;
	}
	std::fstream &Product::store(std::fstream &file, bool newLine) const {
		file << type_product << ',' << sku_product << ',' << unit_product << ',' << ad_name_product << ',' << quantity_pro_hand << "," << taxable_pro << "," << beforetax_single_pro << "," << quantity_pro_need;
		if (newLine)
			file << endl;
		return file;
	}
	std::fstream &Product::load(std::fstream &file) {
		Product temp;
		temp.ad_name_product = new char[MAX_NAME + 1];
		if (file.is_open()) {
			file >> temp.type_product >> temp.sku_product >> temp.unit_product >> temp.ad_name_product >> temp.quantity_pro_hand >> temp.taxable_pro >> temp.beforetax_single_pro >> temp.quantity_pro_need;
			*this = temp;
		}
		delete[] temp.ad_name_product;
		temp.ad_name_product = nullptr;
		return file;
	}
	std::ostream &Product::write(std::ostream &os, bool linear) const {
		if (linear) {
			os << setw(MAX_SKU) << left << sku_product << '|'
				<< setw(20) << left << ad_name_product << '|'
				<< setw(7) << right << fixed << setprecision(2) << cost() << '|'
				<< setw(4) << right << quantity_pro_hand << '|'
				<< setw(10) << left << unit_product << '|'
				<< setw(4) << right << quantity_pro_need << '|';
		}
		else {
			os << "Sku: " << sku_product << "|" << endl
				<< "Name: " << ad_name_product << "|" << endl
				<< "Price: " << beforetax_single_pro << "|" << endl;
			if (taxable_pro) {
				os << "Price after tax: " << cost() << "|" << endl;
			}
			else {
				os << "N/A"
					<< "|" << endl;
			}
			os << "Quantity On hand: " << quantity_pro_hand << "|" << endl
				<< "Quantity needeed: " << quantity_pro_need << "|" << endl;
		}
		return os;
	}
	std::istream &Product::read(std::istream &is) {
		char sku[MAX_SKU + 1];
		char *address = new char[MAX_NAME + 1];
		char unit[MAX_UNIT + 1];
		int onHand;
		int needed;
		double beforeTax;
		char tax;
		bool taxable;
		ErrorState error;
		cout << " Sku: ";
		is >> sku;
		cout << " Name (no spaces): ";
		is >> address;
		cout << " Unit: ";
		is >> unit;
		cout << " Taxed? (y/n): ";
		is >> tax;
		if (tax == 'Y' || tax == 'y') {
			taxable = true;
		}
		else if (tax == 'N' || tax == 'n') {
			taxable = false;
		}
		else {
			is.setstate(std::ios::failbit);
			error.message("Only(Y)es or (N)o are acceptable");
		}
		if (!is.fail()) {
			cout << " Price: ";
			is >> beforeTax;
			if (is.fail())
				error.message("Invalid Price Entry");
		}
		if (!is.fail()) {
			cout << " Quantity on hand: ";
			is >> onHand;
			if (is.fail())
				error.message("Invalid Quantity Entry");
		}
		if (!is.fail()) {
			cout << " Quantity needed: ";
			is >> needed;
			if (is.fail())
				error.message("Invalid Quantity Needed Entry");
		}
		
		if (!is.fail()) {
			Product temp = Product(sku, address, unit, onHand, taxable, beforeTax, needed);
			*this = temp;
		}
		delete[] address;
		address = nullptr;
		return is;
	}
	
	bool Product::operator==(const char *address) const {
		return strcmp(address, this->sku_product) == 0;
	}
	double Product::total_cost() const {
		double taxed = beforetax_single_pro * TAX_RATE;
		double withTax = beforetax_single_pro + taxed;
		return static_cast<double>(quantity_pro_hand * withTax);
	}
	void Product::quantity(int units) {
		quantity_pro_hand = units;
	}
	bool Product::isEmpty() const {
		return (ad_name_product == nullptr) ? true : false;
	}
	int Product::qtyNeeded() const {
		return quantity_pro_need;
	}
	int Product::quantity() const {
		return quantity_pro_hand;
	}
	bool Product::operator>(const char *address) const {
		return (strcmp(sku_product, address) > 0) ? true : false;
	}
	bool Product::operator>(const Product &second) const {
		return (strcmp(ad_name_product, second.ad_name_product) > 0) ? true : false;
	}
	int Product::operator+=(int unitsToBeAdded) {
		if (unitsToBeAdded > 0) {
			quantity_pro_hand += unitsToBeAdded;
			return quantity_pro_hand;
		}
		else
			return quantity_pro_hand;
	}
	std::ostream &operator<<(std::ostream &os, const Product &second) {
		return second.write(os, true);
	}
	std::istream &operator>>(std::istream &is, Product &second) {
		second.read(is);
		return is;
	}
	double operator+=(double &total, const Product &second) {
		return total + second.total_cost();
	}
}