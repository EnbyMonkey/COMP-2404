
#include "Date.h"

Date::Date(){
	setDate(1901,1,1,0,1);

}

Date::Date(int y, int m, int d, int h, int dur){
	setDate(y,m,d,h,dur);
}

Date::Date(const Date& d) {
  setDate(d);
}


//setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setHour(int h){
	if (h < 0) h = 0;
	if (h > 23) h = 23;
	hour = h;
}

void Date::setDuration(int d) {
	if (d < 0) d = 0;
	else if (d > maxDuration) d = maxDuration;
	duration = d;
}

void Date::setDate(int y, int m, int d, int h, int dur){
	setMonth(m);
	setDay(d);
	setYear(y);
	setHour(h);
	setDuration(dur);
}

void Date::setDate(const Date& d){
	setDate(d.year, d.month, d.day, d.hour, d.duration);
}


//getters
int Date::getDay(){ return this->day; }
int Date::getMonth(){ return this->month; }
int Date::getYear(){ return this->year; }
const string& Date::getMonthName(){return months[month-1];}
int Date::getHour() { return this->hour; }
int Date::getDuration() { return this->duration; }


//other

bool Date::lessThan(Date& d){
	if (year == d.year){
		if (month == d.month){
			if (day == d.day) {
				return hour < d.hour;
			} else {
				return day < d.day;
			}
		} else {
			return month  < d.month;
		}
	} else {
		return year < d.year;
	}
}

bool Date::overlaps(Date& d) {
	if (year != d.year) {
			return false;
	} else if (month != d.month) {
			return false;
	} else if (day != d.day) {
			return false;
	} else {
		if (hour <= d.hour && hour+duration <= d.hour) return false;
		if (hour >= d.hour && hour >= d.hour+d.duration) return false;
	} return true;
}


void Date::print(){
	cout << "the " << this->getDay() << " of " <<this->getMonthName()
       << ", " << this->getYear() << " at " << this->getHour()
       << " for " << this->getDuration() << "h" << endl;
}

int Date::getMaxDay(){
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}
