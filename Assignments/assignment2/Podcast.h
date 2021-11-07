#ifndef PODCAST_H
#define PODCAST_H

#include <string>
#include "Episode.h"


class Podcast {

	public:
		//constructor
    Podcast(const std::string& title = "NO TITLE", const std::string& host = "NO HOST");
    Podcast(const Podcast& old); // deep copy
    ~Podcast();

		//getters
    const std::string getTitle() const;
    const std::string getHost() const;
    int getNumEpisodes() const;
    bool getEpisode(int index, Episode** ep) const;

    //other
    bool addEpisode(const std::string& epName, const std::string& epContent);
    bool lessThan(Podcast& pod) const;

		void print() const;

	private:
		//variables
		std::string title; // title of the podcast
		std::string host; // the name of the person(s) hosting the podcast
    int numEps; // the number of episodes

    Episode* episodes; // the list of all episodes

};
#endif
