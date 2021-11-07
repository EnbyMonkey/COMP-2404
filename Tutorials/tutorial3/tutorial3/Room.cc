
#include "Room.h"

// constructors
Room::Room(string name, int capacity, int computers, bool whiteboard) {
  this->name = name;
  this->capacity = capacity;
  this->computers = computers;
  this->whiteboard = whiteboard;
}


Room::Room(const Room &room) {
  this->name = room.name;
  this->capacity = room.capacity;
  this->computers = room.computers;
  this->whiteboard = room.whiteboard;
}


//setters
void Room::setName(string name) {
  this->name = name;
}

void Room::setCapacity(int capacity) {
  this->capacity = capacity;
}

void Room::setComputers(int computers) {
  this->computers = computers;
}

void Room::setWhiteboards(bool whiteboard) {
  this->whiteboard = whiteboard;
}


//getters
string Room::getName() {
  return this->name;
}

int Room::getCapacity() {
  return this->capacity;
}

int Room::getComputers() {
  return this->computers;
}

bool Room::hasWhiteboard() {
  return this->whiteboard;
}


//other
bool Room::meetsCriteria(int capacity, int computers = 0, bool whiteboard = false) {
  if (this->capacity >= capacity
      && this->computers >= computers
      && this->whiteboard >= whiteboard) {
    return true;
  }
  else return false;
}

bool Room::lessThan(Room& room) {
  if (this->name <= room.name) return true;
  else return false;
}

void Room::print() {
  cout << "Room name: " << this->name << ", capacity: " << this->capacity
       << ", computers: " << this->computers << ", whiteboard: "
       << this->whiteboard << endl;
}
