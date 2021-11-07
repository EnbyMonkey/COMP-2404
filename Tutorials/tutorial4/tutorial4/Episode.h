
#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>

#include "defs.h"

using namespace std;

class Episode {

	public:
		//constructor
		Episode();
    Episode(const string& podcast, int number, const string& name, const string& content);


		//other
    void play();
		void print();

	private:
		//variables
		string name;
		string content;
		string podcast;
    int number;

};
#endif
