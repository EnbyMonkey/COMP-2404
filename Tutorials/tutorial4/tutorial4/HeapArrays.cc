#include "HeapArrays.h"

//constructor
HeapArrays::HeapArrays() {
  this->episodeArray = new Episode[ARR_SIZE];
  for (int i = 0; i < ARR_SIZE; i++) {
    this->episodeArray[i] = Episode();
  }

  this->episodePtrArray = new Episode*[ARR_SIZE];
  for (int i = 0; i < ARR_SIZE; i++) {
    this->episodePtrArray[i] = new Episode();
  }

}

HeapArrays::~HeapArrays() {
  delete[] this->episodeArray;

  for (int i = 0; i < ARR_SIZE; i++) {
    delete this->episodePtrArray[i];
  }
  delete []this->episodePtrArray;
}

//getters
Episode* HeapArrays::getObjectArray() {
  return this->episodeArray;
}

HeapArrays::EpisodePtr* HeapArrays::getPointerArray() {
  return this->episodePtrArray;
}

//other
void HeapArrays::print() {
  cout << "BLAH";
}
