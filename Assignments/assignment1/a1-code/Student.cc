#include "Student.h"

// constructors
Student::Student(string name, string number) {
  this->name = name;
  this->number = number;
}


Student::Student(const Student &s) {
  this->name = s.name;
  this->number = s.number;
}


//setters
void Student::setName(string name) {
  this->name = name;
}

void Student::setNumber(string number) {
  this->number = number;
}


//getters
string Student::getName() {
  return this->name;
}

string Student::getNumber() {
  return this->number;
}


//other
bool Student::lessThan(Student& s) {
  if (this->name <= s.name) return true;
  else return false;
}

void Student::print() {
  cout << "Student name: " << this->name << ", number: " << this->number << endl;
}
