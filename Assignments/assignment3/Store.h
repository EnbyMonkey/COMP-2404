
#ifndef STORE_H
#define STORE_H

#include <iomanip>
#include "List.h"


class Store {

	public:
		//constructor
		Store(const std::string& storeName);

		//destructor
		~Store();

		//other
		void findAvailableSLoc(StoreLocation** sloc);
		void findAvailableWHLoc(WHLocation** whloc);
    void findProduct(const std::string& productName, Product** prod);

		// various print functions
		void printStoreStock() const;
		void printWareHouseStock() const;
		void printProducts() const;
		void print() const;


		//these are done for you
		void receiveProduct(const std::string& pname, int quantity);
		void fillOrder(const std::string& pame, int& quantity);

	private:
		std::string storeName;
    List* products;

    StoreLocation slocs[SLOCS];
    WHLocation whlocs[WHLOCS];


};
#endif
