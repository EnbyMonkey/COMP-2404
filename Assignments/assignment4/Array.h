
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

template <class T>

class Array {

	public:
		// ctor & dtor
		Array();
		~Array();

		//other
		void add(T* t);
		int get(int index);
		int getSize();
		bool isFull();

	private:
		int size;
		T* elements;

};

#endif
