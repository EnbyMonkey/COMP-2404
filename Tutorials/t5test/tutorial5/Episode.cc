#define DEBUG

#include "Episode.h"

//constructor
Episode::Episode() {
  name = "Talking about things and stuff";
  content = "Hi podcast words and things bla bla bla.";
  podcast = "World's Most Podcasty Podcast";
  number = 1;
}

Episode::Episode(const string& podcast, int number, const string& name, const string& content) {
  this->name = name;
  this->content = content;
  this->podcast = podcast;
  this->number = number;
}

Episode::Episode(const Episode& old) {
  #if defined(DEBUG)
    cout << "Episode copy constructor called" << endl;
  #endif

  name = old.name;
  content = old.content;
  podcast = old.podcast;
  number = old.number;
}

//other
void Episode::play() {
  #if defined(DEBUG)
    cout << "Episode play called" << endl;
  #endif
  cout << "Podcast: " << podcast << endl
       << "Episode: " << name << endl
       << "Episode #" << number << endl
       << content << endl;
}

void Episode::print() {
  #if defined(DEBUG)
    cout << "Episode print called" << endl;
  #endif
  cout << "Episode " << number << endl
       << name << endl;
//       << content << endl << endl;
}
