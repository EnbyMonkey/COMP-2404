
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "defs.h"

template <class T>

class Array {

	public:
		// ctor & dtor
		Array();
		~Array();

		//other
		void add(T t);
		int getSize() const;
		bool isFull() const;

		// operator overloading
		T operator[](int index) const;

	private:
		int size;
		T elements [MAX_ARR];

};


template<class T> Array<T>::Array() : size(0) { }
template<class T> Array<T>::~Array() { }

// other
template<class T>
void Array<T>::add(T t) {	if (size < MAX_ARR) elements[size++] = t; }

template<class T>
int Array<T>::getSize() const {	return size; }

template<class T>
bool Array<T>::isFull() const {	return size >= MAX_ARR; }

// overload [] operator
template<class T>
T Array<T>::operator[](int index) const {
  if (index < 0 || index >= size) {
		std::cerr << "Array index out of bounds" << std::endl;
		exit(1);
	}
	return elements[index];
}

// overload << operator
template<class T>
std::ostream& operator<<(std::ostream& output, const Array<T>& arr) {
	output << "Array of size " << arr.getSize() << std::endl;
	output << "Elements in the array:" << std::endl;
	for (int i = 0; i < arr.getSize(); ++i) output << arr[i] << std::endl;

  return output;
}


#endif
