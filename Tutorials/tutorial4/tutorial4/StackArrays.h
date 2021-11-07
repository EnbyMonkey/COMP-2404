
#ifndef STACKARRAYS_H
#define STACKARRAYS_H

#include <iostream>
#include <string>

#include "Episode.h"

using namespace std;

class StackArrays {

	public:
		//constructor
		StackArrays();
    ~StackArrays();

		//setters


		//getters
    Episode* getObjectArray();
    Episode** getPointerArray();

		//other
		void print();

	private:
		//variables
    Episode episodeArray[ARR_SIZE];

    Episode *episodePtrArray[ARR_SIZE];
};
#endif
