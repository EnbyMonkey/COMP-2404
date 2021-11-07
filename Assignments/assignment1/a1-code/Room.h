
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room {

	public:
		//constructor
    Room(string name, int capacity, int computers, bool whiteboard);
    Room(const Room&);

		//setters
    void setName(string name);
    void setCapacity(int capacity);
    void setComputers(int computers);
    void setWhiteboards(bool whiteboard);


		//getters
    string getName();
    int getCapacity();
    int getComputers();
    bool hasWhiteboard();


		//other
    bool meetsCriteria(int capacity, int computers, bool whiteboard);
    bool lessThan(Room& room);

		void print();

	private:
		//functions


		//variables
    string name;
		int capacity;
		int computers;
		bool whiteboard;


};
#endif
