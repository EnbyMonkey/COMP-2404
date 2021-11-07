#define DEBUG

#include "Podcast.h"

using namespace std;

// 0-2 argument constructor
Podcast::Podcast(const string& title, const string& host) {
  #if defined(DEBUG)
    cout << "Podcast constructor enter" << endl;
  #endif
  this->title = title;
  this->host = host;

  numEps = 0;
  episodes = new Episode[MAX_EPS];

  #if defined(DEBUG)
    cout << "Podcast constructor exit" << endl;
  #endif
}

// copy constructor (makes a deep copy)
Podcast::Podcast(const Podcast& old) {
  #if defined(DEBUG)
    cout << "Podcast copy constructor enter" << endl;
  #endif

  title = old.title;
  host = old.host;
  numEps = old.numEps;
  episodes = new Episode[MAX_EPS];
  for (int i = 0; i < old.numEps; ++i) {
    episodes[i] = Episode(old.episodes[i]);
  }
  #if defined(DEBUG)
    cout << "Podcast copy constructor exit" << endl;
  #endif
}

//destructor
Podcast::~Podcast() {
  #if defined(DEBUG)
    cout << "Podcast destructor enter" << endl;
  #endif

  delete [] episodes;

  #if defined(DEBUG)
    cout << "Podcast denstructor exit" << endl;
  #endif
}


//getters
const string Podcast::getTitle() const {
  #if defined(DEBUG)
    cout << "Podcast getTitle called" << endl;
  #endif

  return title;
}

const string Podcast::getHost() const {
  #if defined(DEBUG)
    cout << "Podcast getHost called" << endl;
  #endif

  return host;
}
const int Podcast::getNumEpisodes() const {
  #if defined(DEBUG)
    cout << "Podcast getNumEpisodes called" << endl;
  #endif

  return numEps;
}

const bool Podcast::getEpisode(int index, Episode** ep) const {
  #if defined(DEBUG)
    cout << "Podcast getEpisode called" << endl;
  #endif
  if (index >= numEps || index < 0) {
    #if defined(DEBUG)
      cout << "Podcast getNumEpisodes returned false" << endl;
    #endif
    return false; // invalid index
  }

  *ep = episodes + index;
  #if defined(DEBUG)
    cout << "Podcast getEpisode returned true" << endl;
  #endif
  return true;
}

//other
const bool Podcast::addEpisode(const string& epName, const string& epContent) {
  #if defined(DEBUG)
    cout << "Podcast addEpisode called" << endl;
  #endif
  if (numEps == MAX_EPS) {
    #if defined(DEBUG)
      cout << "Podcast addEpisode returned false" << endl;
    #endif
    return false; // the array is full, can't add new Episode object
   }

  ++numEps;
  episodes[numEps-1] = Episode(title, numEps, epName, epContent);

  #if defined(DEBUG)
    cout << "Podcast addEpisode returned true" << endl;
  #endif
  return true;
}

const bool Podcast::lessThan(Podcast& pod) const {
  #if defined(DEBUG)
    cout << "Podcast lessThan called" << endl;
  #endif
  return (title < pod.title);
}

const void Podcast::print() {
  cout << "Podcast title: " << title << endl
       << "Podcast host: " << host << endl << endl;

  for (int i = 0; i < numEps; ++i) {
    episodes[i].print();
  }

}
