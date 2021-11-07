#include <iostream>
#include <iomanip>
#include "PodArray.h"

using namespace std;

PodArray::PodArray(){
	numPods = 0;
	podcasts = new Podcast*[MAX_PODS];
}

PodArray::PodArray(PodArray& pa){
	podcasts = new Podcast*[MAX_PODS];
	for (int i =0 ; i < pa.numPods; ++i){
		podcasts[i] = new Podcast(*pa.podcasts[i]);
	}
	numPods = pa.numPods;

}


PodArray::~PodArray(){
	for (int i = 0; i < numPods; ++i){
		delete podcasts[i];
	}
	delete [] podcasts;
}

bool PodArray::addPodcast(Podcast* p){
	if (numPods >= MAX_PODS) return false;
	for (int i = numPods; i > 0; --i){
		if (p->lessThan(*podcasts[i-1])){
			podcasts[i] = podcasts[i-1];
		}else{
			podcasts[i] = p;
			++numPods;
			return true;
		}
	}
	podcasts[0] = p;
	++numPods;
	return true;
}

bool PodArray::removePodcast(const string& title, Podcast** pod){
  int index = -1;
  for (int i = 0; i < numPods; ++i) {
    if (podcasts[i]->getTitle() == title) {
      index = i;
      break;
    }
  }

  if (index < 0) {
    return false; // podcast not in array
  }

  *pod = podcasts[index];
  while (index < numPods) {
    podcasts[index] = podcasts[index + 1];
    ++index;
  }
  podcasts[index] = NULL; // I guess it's not really necessary, but it seems weird to have garbage values instead
  --numPods;
  return true;
}

bool PodArray::getPodcast(const string& title, Podcast** pod) const {
  int index = -1;
  for (int i = 0; i < numPods; ++i) {
    if (podcasts[i]->getTitle() == title) {
      index = i;
      break;
    }
  }

  if (index < 0) return false; // podcast not in array

  *pod = podcasts[index];
  return true; // yay!
}

bool PodArray::isFull() const {
	return numPods >= MAX_PODS;
}

int PodArray::size() const {
	return numPods;
}

void PodArray::print() const {
	for (int i = 0; i < numPods; ++i){
		podcasts[i]->print();
	}
}
