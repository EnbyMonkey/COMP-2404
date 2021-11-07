#include "Student.h"

using namespace std;


Student::Student(const string& name, const string& number):name(name),number(number){ }

Student::Student(Student& student){
	name = student.name;
	number = student.number;
}


Student::~Student(){
}

string Student::getName() const {
	return name;
}

string Student::getNumber() const {
	return number;
}

bool Student::lessThan(Student& s) const {
	return number < s.number;
}

void Student::print() const {
	cout << "Student name:" << setw(15) << name << setw(30) << "Student Number: " << number << endl;
}
