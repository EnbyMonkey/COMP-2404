
#ifndef DATE_H
#define DATE_H

const int maxDuration = 3; // maximum duration of a reservation (hours)

#include <iostream>
#include <string>

using namespace std;

class Date {

	public:
		//constructor
		Date();
		Date(int year, int month, int day, int hour, int duration);
		Date(const Date&);


		//setters
		void setDay(int);
		void setMonth(int);
		void setYear(int);
		void setHour(int);
		void setDuration(int);
		void setDate(int, int, int, int, int);
		void setDate(const Date&);


		//getters
		int getDay();
		int getMonth();
		int getYear();
		const string& getMonthName();
    int getHour();
    int getDuration();

		//other
		bool lessThan(Date& d);
		bool overlaps(Date& d);

		void print();

	private:
		//functions
		int getMaxDay();


		//variables
		int day;
		int month;
		int year;
		int hour;
		int duration;

		const string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		const string smonths[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};

};
#endif
