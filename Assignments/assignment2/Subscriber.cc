#include <iostream>
#include "Subscriber.h"

using namespace std;

//constructor
Subscriber::Subscriber(const string& name, const string& creditcard) {
  this->name = name;
  this->creditcard = creditcard;
}

//other
bool Subscriber::matches(const string& name) const {
  return (this->name == name);
}

void Subscriber::print() const {
  cout << "Subscriber: " << this->name << endl;
}
