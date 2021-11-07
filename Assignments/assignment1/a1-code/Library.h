
#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>

#include "Room.h"
#include "Student.h"
#include "Date.h"
#include "Reservation.h"

using namespace std;

class Library {

	public:
		//constructor
    Library();
    ~Library();

		//getters

		//other
    bool addStudent(const string& name, const string& number);
    bool addRoom(string name, int capacity = 1, int computers = 0, bool whiteboard = false);
    bool getStudent(const string& name, Student** student);
    bool getRoom(const string& roomName, Room** room);
    bool isFree(const string& room, Date&);
    bool makeReservation(const string& student, const string& room, Date&);
    void update(Date&);

		void print();

	private:

		//variables
    typedef Student* StudentPtr;
    StudentPtr *students;
    int size_students;

		typedef Room* RoomPtr;
    RoomPtr *rooms;
    int size_rooms;

    typedef Reservation* ReservationPtr;
    ReservationPtr *reservations;
    int size_reservations;



};
#endif
