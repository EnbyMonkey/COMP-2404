#include "Library.h"

// constructors
Library::Library(){
  this->size_students = 20;
  this->students = new StudentPtr[this->size_students];
  for (int i = 0; i < this->size_students; i++) {
    this->students[i] = NULL;
  }

  this->size_rooms = 20;
  this->rooms = new RoomPtr[this->size_rooms];
  for (int i = 0; i < this->size_rooms; i++) {
    this->rooms[i] = NULL;
  }

  this->size_reservations = 20;
  this->reservations = new ReservationPtr[this->size_reservations];
  for (int i = 0; i < this->size_reservations; i++) {
    this->reservations[i] = NULL;
  }
}

Library::~Library() {
  for (int i = 0; i < this->size_students; i++) {
    delete this->students[i];
  }
  delete[] this->students;

  for (int i = 0; i < this->size_rooms; i++) {
    delete this->rooms[i];
  }
  delete[] this->rooms;

  for (int i = 0; i < this->size_reservations; i++) {
    delete this->reservations[i];
  }
  delete[] this->reservations;
}


//other
bool Library::addStudent(const string& name, const string& number) {
  Student* temp_student = new Student(name, number);

  int index = 0;
  while (this->students[index] != NULL && index < this->size_students) { index++; }

  if (index < this->size_students) {
    this->students[index] = temp_student;
    return true;
  }
  else return false;
}

bool Library::addRoom(string name, int capacity, int computers, bool whiteboard) {
  Room* temp_room = new Room(name, capacity, computers, whiteboard);

  int index = 0;
  while (this->rooms[index] != NULL && index < this->size_rooms) { index++; }

  if (index < this->size_rooms) {
    this->rooms[index] = temp_room;
    return true;
  }
  else return false;
}

bool Library::getStudent(const string& name, Student** student) {
  for (int i = 0; i < this->size_students; i++) {
    if (this->students[i] != NULL)
      if (this->students[i]->getName() == name) {
        *student = this->students[i];
        return true;
      }
  }
  return false;
}

bool Library::getRoom(const string& roomName, Room** room) {
  for (int i = 0; i < this->size_rooms; i++) {
    if (this->rooms[i] == NULL) break;

    if (this->rooms[i]->getName() == roomName) {
      *room = this->rooms[i];
      return true;
    }
  }
  return false;
}

bool Library::isFree(const string& room, Date& date) {
  Room* temp_room = NULL;

  if (!this->getRoom(room, &temp_room)) {
    return false; // no such room
  }

  for (int i = 0; i < this->size_reservations; i++) {
    if (this->reservations[i] == NULL) {
      return true; // no reservations for that room
    }

    if (this->reservations[i]->getRoom()->getName() == room) {
      if (reservations[i]->getDate()->overlaps(date)) {
        return false;
      }
      else return true;
    }
  }
  return true;
}

bool Library::makeReservation(const string& student, const string& room, Date& date) {
  Room* temp_room = NULL;
  if (!this->getRoom(room, &temp_room)) return false; // room doesn't exist

  Student* temp_student = NULL;
  if (!this->getStudent(student, &temp_student)) return false; // student doesn't exist

  if (!this->isFree(room, date)) return false; // room is not available

  if (this->reservations[this->size_reservations-1] != NULL) return false; // reservation array is full

  for (int i = 0; i < this->size_reservations; i++) {
    if (this->reservations[i] != NULL) continue;
    else {
      this->reservations[i] = new Reservation(temp_student, temp_room, date);
      return true;
    }
  }
  return false;
}

void Library::update(Date& date) {
  int index = 0;

  for (int i = 0; i < this->size_reservations; i++) {
    if (this->reservations[i] == NULL) break;

    if (this->reservations[i]->getDate()->lessThan(date)) {
      delete this->reservations[i];
    }
    else if (index < i) {
      this->reservations[index] = this->reservations[i];
      this->reservations[i] = NULL;
      index++;
    }
  }
}

void Library::print() {
  cout << "The library has the following reservations: " << endl;

  for (int i = 0; i < this->size_reservations; i++) {
    if (this->reservations[i] == NULL) break;

    cout << "Reservation " << i+1 << ": ";
    this->reservations[i]->print();
  }
  cout << endl;
}
