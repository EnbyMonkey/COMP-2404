
#include <sstream>
#include <iostream>
#include "Location.h"

using namespace std;

// initialize static attribute
const string Location::NONE = "Empty";

// ctor and dtor
Location::Location(char code, int nextId) {
  stringstream ss;
  ss << code << nextId;
  id = ss.str();

  product = NONE; // initially a Location (StoreLocation or WHLocation) does not have a product assigned to it
  quantity = 0;
}

Location::~Location() {}


// other

bool Location::isEmpty() const {
  return quantity == 0;
}

// A Location is available if there is no product assigned to it
bool Location::isAvailable() const {
  return product == NONE;
}
