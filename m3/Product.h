#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include "ErrorState.h"
namespace AMA {
	const int MAX_SKU = 7;
	const int MAX_UNIT = 10;
	const int MAX_NAME = 75;
	const double TAX_RATE = 0.13;
	const int max_sku_length = MAX_SKU;
	const int max_name_length = MAX_NAME;
	const int max_unit_length = MAX_UNIT;
	class Product {
	private:
		char type_product;
		char sku_product[MAX_SKU + 1];
		char unit_product[MAX_UNIT + 1];
		char* ad_name_product;
		int quantity_pro_hand;
		int quantity_pro_need;
		double beforetax_single_pro;
		bool taxable_pro;
		ErrorState errorst;
	protected:
		void name(const char* nameAddress);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
	public:
		Product(char type = 'N');
		Product(const char* sku, const char* address, const char * unit, int onHand = 0, bool taxable = true, double beforeTax = 0.0, int needed = 0);
		Product(const Product& other);
		~Product();
		Product& operator=(const Product & other);
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char* address) const;
		double total_cost() const;
		void quantity(int units);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char* address) const;
		bool operator>(const Product& other) const;
		int operator+=(int unitsToBeAdded);
	};
	std::ostream& operator<<(std::ostream& os, const Product& other);
	std::istream& operator>>(std::istream& is, Product& other);
	double operator+=(double& total, const Product& other);
}
#endif
