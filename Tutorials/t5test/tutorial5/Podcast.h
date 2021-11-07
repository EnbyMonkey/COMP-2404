
#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>

#include "defs.h"
#include "Episode.h"


using namespace std;

class Podcast {

	public:
		//constructor
    Podcast(const string& title = "NO TITLE", const string& host = "NO HOST");
    Podcast(const Podcast& old); // deep copy
    ~Podcast();

		//getters
    const string getTitle() const;
    const string getHost() const;
    const int getNumEpisodes() const;
    const bool getEpisode(int index, Episode** ep) const;

    //other
    const bool addEpisode(const string& epName, const string& epContent);
    const bool lessThan(Podcast& pod) const;

		const void print();

	private:
		//variables
		string title; // title of the podcast
		string host; // the name of the person(s) hosting the podcast
    int numEps; // the number of episodes

    Episode* episodes; // the list of all episodes

};
#endif
