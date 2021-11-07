
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <iomanip>


class Student {

	public:
		//constructor
		Student(const std::string& name, const std::string& number);
		//copy constructor
		Student(Student&);

		//destructor
		~Student();

		//getters
		std::string getName() const;
		std::string getNumber() const;

		//other
		bool lessThan(Student&) const;
		void print() const;

	private:
		std::string name;
		std::string number;

};
#endif
