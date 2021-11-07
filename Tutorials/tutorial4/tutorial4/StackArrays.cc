#include "StackArrays.h"

//constructor
StackArrays::StackArrays() {
//  for (int i = 0; i < ARR_SIZE; i++) {
//    this->episodeArray[i] = new Episode();
//  }

  for (int i = 0; i < ARR_SIZE; i++) {
    this->episodePtrArray[i] = new Episode;
  }
}

StackArrays::~StackArrays() {
//  for (int i = 0; i < ARR_SIZE; i++) {
//    delete this->episodeArray[i];
//  }

  for (int i = 0; i < ARR_SIZE; i++) {
    delete this->episodePtrArray[i];
  }
}

//getters
Episode* StackArrays::getObjectArray() {
  return this->episodeArray;
}

Episode** StackArrays::getPointerArray() {
  return this->episodePtrArray;
}

//other
void StackArrays::print() {

}
