#include "Array.h"

using namespace std;


Array::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

Array::~Array(){
	delete [] elements;
}

void Array::add(T* t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

int Array::getSize(){
	return size;
}

bool Array::isFull(){
	return size >= MAX_ARR;
}

// overload [] operator
T& operator[](int index) {
  if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

/*
T* Array::get(int index){
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
} */

// overload << operator
friend ostream &operator<<( ostream &output, const T& t ) {
  output << "print something here";
  return output;
}
