
#include <sstream>
#include <iostream>
#include "Location.h"

using namespace std;

// initialize static attribute
const string Location::NONE = "Empty";

// ctor & dtor
Location::Location(char code, int nextId) : product{NONE}, quantity{0} {
  stringstream ss;
  ss << code << nextId;
  id = ss.str();
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
