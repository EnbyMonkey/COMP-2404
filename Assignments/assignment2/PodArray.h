#ifndef PODARRAY_H
#define PODARRAY_H

#include <string>
#include "Podcast.h"


class PodArray {

	public:
		//constructor
		PodArray();
		//copy constructor
		PodArray(PodArray& pa);

		//destructor
		~PodArray();

		//other
		bool addPodcast(Podcast* p);
		bool getPodcast(const std::string& title, Podcast** p) const;
		bool removePodcast(const std::string& title, Podcast** p);
		int size() const;
		bool isFull() const;
		void print() const;

	private:
		int numPods;
		Podcast** podcasts;
};
#endif
