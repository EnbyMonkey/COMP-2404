
#ifndef HEAPARRAYS_H
#define HEAPARRAYS_H

#include <iostream>
#include <string>

#include "Episode.h"

using namespace std;

class HeapArrays {

	public:

		//constructor
		HeapArrays();
    ~HeapArrays();

		//getters
    Episode* getObjectArray();
    Episode** getPointerArray();

		//other
		void print();

	private:
		//variables
    Episode* episodeArray; // array of episode objects
    Episode** episodePtrArray; // array of episode pointers


};
#endif
