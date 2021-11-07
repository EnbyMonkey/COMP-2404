#include <iostream>
#include "StoreLocation.h"

using namespace std;


// initialize static attributes;
const char StoreLocation::code = 'A';
const int StoreLocation::capacity = SLOC_CAPACITY;
int StoreLocation::nextId = 0;


// ctor
StoreLocation::StoreLocation() : Location(code, nextId) {
  ++nextId; // each instance of StoreLocation will have a different id (A0, A1, etc)
}


// other
void StoreLocation::setProduct(const string& productName) {
  Location::setProduct(productName);
}

int StoreLocation::getFreeSpace() const {
  return capacity - getQuantity();
}


// print
void StoreLocation::print() const {
  cout << "StoreLocation id: " << getId() << ", Product: " << getProduct() << ", Quantity: " << getQuantity();
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
  if (quantityToAdd <= 0 || quantityToAdd + getQuantity() > capacity) return false;

  if (isEmpty()) {
    setProduct(productName);
  }
  else if (getProduct() != productName) return false;

  setQuantity(getQuantity() + quantityToAdd);
  return true;  // we did it!
}

// cannot remove more product than is currently present
bool StoreLocation::remove(int quantityToRemove) {
  if (quantityToRemove > getQuantity() || quantityToRemove < 0) return false;

  setQuantity(getQuantity() - quantityToRemove);
  return true;
}
