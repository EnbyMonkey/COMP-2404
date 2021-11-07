
#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>

#include "Room.h"
#include "Student.h"
#include "Date.h"

using namespace std;

class Reservation {

	public:
		//constructor
    Reservation(Student*, Room*, Date&);
    ~Reservation();

		//getters
    Student* getStudent();
    Room* getRoom();
    Date* getDate();


		//other
    bool lessThan(Reservation& res);
    bool overlaps(string r, Date& d);

		void print();

	private:

		//variables
    Student* student;
		Room* room;
    Date* date;



};
#endif
