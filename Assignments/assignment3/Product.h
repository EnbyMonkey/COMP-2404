
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

#include "defs.h"
#include "Queue.h"
#include "StoreLocation.h"



class Product {

	public:
		//constructor
		Product(const std::string& productName, StoreLocation* sloc);

		//destructor
		~Product();

		//getters and setters
		const std::string& getName() const;
		StoreLocation* getStoreLocation() const;
		void setStoreLocation(StoreLocation* sloc);
		void addWHLocation(WHLocation* whloc);

    // print
    void print();


		//these have been done for you
		void getFromStoreLocation(int& quantity);
		void getFromWHLocations(int& quantity);
		void fillOrder(int& quantity);
		void stockStoreLocation();



	private:
		std::string name;  // product name
		StoreLocation* sloc;
		Queue* whlocQueue; // warehouse locations that contain the product


};
#endif
