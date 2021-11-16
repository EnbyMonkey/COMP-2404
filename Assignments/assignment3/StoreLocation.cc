#include <iostream>
#include "StoreLocation.h"

using namespace std;


// initialize static attributes;
const char StoreLocation::code = 'A';
const int StoreLocation::capacity = SLOC_CAPACITY;
int StoreLocation::nextId = 1;


// ctor & dtor
StoreLocation::StoreLocation() : Location(code, nextId++) { }
StoreLocation::~StoreLocation() {}


// other
void StoreLocation::setProduct(const string& productName) {
  product = productName;
}

int StoreLocation::getFreeSpace() const {
  return capacity - quantity;
}

int StoreLocation::getQuantity() const {
  return quantity;
}


/*
**  Inherited
*/

int StoreLocation::getCapacity() const {
  return capacity;
}

// to add product to StoreLocation, current product must either be empty or the same as new product
// return true if full amount of product was added, false otherwise
bool StoreLocation::add(const string& productName, int quantityToAdd) {
  if (quantityToAdd <= 0 || quantityToAdd + quantity > capacity) return false;

  if (isEmpty()) {
    product = productName;
  }
  else if (product != productName) return false;

  quantity += quantityToAdd;
  return true;  // we did it!
}

// cannot remove more product than is currently present
bool StoreLocation::remove(int quantityToRemove) {
  if (quantityToRemove > quantity || quantityToRemove < 0) return false;

  quantity -= quantityToRemove;
  return true;
}


// print
void StoreLocation::print() const {
  cout << "StoreLocation id: " << id << ", Product: " << product << ", Quantity: " << quantity;
}
