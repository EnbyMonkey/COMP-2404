#include <iostream>
#include "WHLocation.h"

using namespace std;


// initialize static attributes
const char WHLocation::code = 'B';
const int WHLocation::capacity = WHLOC_CAPACITY;
int WHLocation::nextId = 0;

// ctor
WHLocation::WHLocation() : Location(code, nextId) {
  ++nextId; // each instance of WHLocation will have a different id (B0, B1, etc)
}

WHLocation::~WHLocation() {}

// getters
int WHLocation::getQuantity() {
  return quantity;
}


/*
**  Inherited
*/

int WHLocation::getCapacity() const {
  return capacity;
}

// to add product, WHLocation must be empty
// return true if full amount of product was added, false otherwise
bool WHLocation::add(const string& productName, int quantityToAdd) {
  if (!isEmpty()) return false;
  if (quantity != 0) return false; // instructions say to check for this but it's redundant since we check isEmpty()
  if (quantityToAdd > capacity || quantityToAdd <= 0) return false;

  product = productName;
  quantity = quantityToAdd;

  return true;
}

// cannot remove more product than is currently present
bool WHLocation::remove(int quantityToRemove) {
  if (quantityToRemove > quantity || quantityToRemove < 0) return false;

  quantity -= quantityToRemove;
  if (quantity == 0) product = NONE;

  return true;
}

// TODO - implement
void WHLocation::print() const {
  cout << "WHLocation id: " << id << ", Product: " << product << ", Quantity: " << quantity;
}
