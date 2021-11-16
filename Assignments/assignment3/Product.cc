
#include "Product.h"

using namespace std;


// ctor & dtor
Product::Product(const string& productName, StoreLocation* sloc) :
  name{productName}, sloc{sloc}, whlocQueue(new Queue) { }

Product::~Product() {
  delete whlocQueue;
}

// getters
const std::string& Product::getName() const {
  return name;
}

StoreLocation* Product::getStoreLocation() const {
  return sloc;
}

void Product::setStoreLocation(StoreLocation* sloc) {
  this->sloc = sloc;
}

void Product::addWHLocation(WHLocation* whloc) {
  whlocQueue->addLast(whloc);
}

// print
void Product::print(){
	cout << "Product: " << name;
}


// fucntions implemented by instructor

/* We take as much as we can from the storeLocation.
   The input-output parameter quantity returns
   the amount left to fill in the order
*/
void Product::getFromStoreLocation(int& quantity){
	if (quantity > sloc->getQuantity()){
		quantity -= sloc->getQuantity();
		sloc->remove(sloc->getQuantity());
	}else{
		sloc->remove(quantity);
		quantity = 0;
	}

}

/* We try to fill the order with whatever is in
   the warehouse locations.
   The input-output parameter "quantity" returns
   the amount left to fill in the order
*/
void Product::getFromWHLocations(int& quantity){
	WHLocation* loc;
	while(quantity>0){
		//there are no more warehouse locations storing
		//this product - so break
		if (whlocQueue->isEmpty())break;

		//otherwise get the first whlocation
		whlocQueue->peekFirst(&loc);

		//if we empty the location, remove from the queue
		if (quantity > loc->getQuantity()){
			quantity -= loc->getQuantity();
			loc->remove(loc->getQuantity());
			whlocQueue->popFirst(&loc);
		}else{
			// we are not emptying the location,
			// but we have finished filling the order
			loc->remove(quantity);
			quantity = 0;
		}
	}
}

void Product::fillOrder(int& quantity){
	while (quantity > 0 && !sloc->isEmpty()){
		if (quantity < sloc->getQuantity()){
			sloc->remove(quantity);
			quantity = 0;
		}else{
			quantity -= sloc->getQuantity();
			sloc->remove(sloc->getQuantity());
			stockStoreLocation();
		}
	}

}

void Product::stockStoreLocation(){
	int q = sloc->getFreeSpace();
	int toAdd = q;
	getFromWHLocations(q);
	toAdd -= q;
	sloc->add(name, toAdd);
}
