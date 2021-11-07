#include "Episode.h"

//constructor
Episode::Episode() {
  this->name = "Talking about things and stuff";
  this->content = "Hi podcast words and things bla bla bla.";
  this->podcast = "World's Most Podcasty Podcast";
  this->number = 1;
}

Episode::Episode(const string& podcast, int number, const string& name, const string& content) {
  this->name = name;
  this->content = content;
  this->podcast = podcast;
  this->number = number;
}

//other
void Episode::play() {
  cout << "Podcast: " << this->podcast << endl
       << "Episode: " << this->name << endl
       << "Episode #" << this->number << endl
       << content << endl;
}

void Episode::print() {
  this->play();
}
