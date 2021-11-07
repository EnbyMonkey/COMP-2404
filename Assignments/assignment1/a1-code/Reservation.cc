#include "Reservation.h"

// constructors
Reservation::Reservation(Student* s, Room* r, Date& d) {
  this->student = new Student(*s);
  this->room = new Room(*r);
  this->date = new Date(d);
}

Reservation::~Reservation() {
  delete this->student;
  delete this->room;
  delete this->date;
}


//getters
Student* Reservation::getStudent() {
  return this->student;
}

Room* Reservation::getRoom() {
  return this->room;
}

Date* Reservation::getDate() {
  return this->date;
}


//other
bool Reservation::lessThan(Reservation& res) {
  return (this->date->getYear() < res.date->getYear()
      || this->date->getMonth() < res.date->getMonth()
      || this->date->getDay() < res.date->getDay());
}

bool Reservation::overlaps(string r, Date& d) {
  return (this->room->getName() == r && this->date->overlaps(d));
}

void Reservation::print() {
  cout << this->student->getName() << " is reserving the "
       << this->room->getName() << " room on ";
  this->date->print();
  cout << endl;
}
