
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
		T operator[](int index);


	private:
		int size;
		T elements[MAX_ARR];

};

template<class T> Array<T>::Array() : size(0) { }
template<class T> Array<T>::~Array() { }

// other
template<class T>
void Array<T>::add(T t) { if (size < MAX_ARR) elements[size++] = t; }

template<class T>
int Array<T>::getSize() const {	return size; }

template<class T>
bool Array<T>::isFull() const {	return size >= MAX_ARR; }

// overload [] operator
template<class T>
T Array<T>::operator[](int index) {
  if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

// overload << operator
template<class T>
ostream& operator<<(ostream& output, const Array<T> arr) {
  output << arr.print();
  return output;
}

#endif
