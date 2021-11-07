#include <iostream>
#include "Podcast.h"

using namespace std;

// 0-2 argument constructor
Podcast::Podcast(const string& title, const string& host) {
  this->title = title;
  this->host = host;

  numEps = 0;
  episodes = new Episode[MAX_EPS];
}

// copy constructor (makes a deep copy)
Podcast::Podcast(const Podcast& old) {
  title = old.title;
  host = old.host;
  numEps = old.numEps;
  episodes = new Episode[MAX_EPS];
  for (int i = 0; i < old.numEps; ++i) {
    episodes[i] = Episode(old.episodes[i]);
  }
}

//destructor
Podcast::~Podcast() {
  delete [] episodes;
}


//getters
const string Podcast::getTitle() const {
  return title;
}

const string Podcast::getHost() const {
  return host;
}

int Podcast::getNumEpisodes() const {
  return numEps;
}

bool Podcast::getEpisode(int index, Episode** ep) const {
  if (index >= numEps || index < 0) {
    return false; // invalid index
  }

  *ep = episodes + index;
  return true;
}

//other
bool Podcast::addEpisode(const string& epName, const string& epContent) {
  if (numEps >= MAX_EPS) {
    return false; // the array is full, can't add new Episode object
   }

  ++numEps;
  episodes[numEps-1] = Episode(title, numEps, epName, epContent);
  return true;
}

bool Podcast::lessThan(Podcast& pod) const {
  return (title < pod.title);
}

void Podcast::print() const {
  cout << "Podcast title: " << title << endl
       << "Podcast host: " << host << endl << endl;

  for (int i = 0; i < numEps; ++i) {
    episodes[i].print();
  }

}
