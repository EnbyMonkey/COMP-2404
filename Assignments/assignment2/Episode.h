#ifndef EPISODE_H
#define EPISODE_H

#include <string>
#include "defs.h"

class Episode {

	public:
		//constructor
		Episode(); // default

    // arguments are: podcast name, episode number, episode name, episode content
    Episode(const std::string& podcast, int number, const std::string& name, const std::string& content);

    Episode(const Episode& old);


		//other
    void play() const;
		void print() const;

	private:
		//variables
		std::string name; // name of the episode
		std::string content; // normally this would be audio :)
		std::string podcast; // name of the podcast
    int number; // number of the episode as it appears in the podcast

};
#endif
