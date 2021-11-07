
#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>

#include "defs.h"

using namespace std;

class Episode {

	public:
		//constructor
		Episode(); // default

    // arguments are: podcast name, episode number, episode name, episode content
    Episode(const string& podcast, int number, const string& name, const string& content);

    Episode(const Episode& old);


		//other
    void play();
		void print();

	private:
		//variables
		string name; // name of the episode
		string content; // normally this would be audio :)
		string podcast; // name of the podcast
    int number; // number of the episode as it appears in the podcast

};
#endif
