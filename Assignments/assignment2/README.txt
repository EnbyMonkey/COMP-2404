Emile Greer
100914184

To compile, run make in terminal.
The executable is named a2.

This program contains the following files:
Episode.h, Episode.cc: definition of Episode class, which is responsible to episode metadata (episode title, number)
Podcast.h, Podcast.cc: definition of Podcast class, which is responsible for managing all episodes of a given podcast
PodArray.h, PodArray.cc: definition of PodArray class, which is responsible for managing a list of podcasts 
	(e.g. all podcasts available in a given network, or all podcasts downloaded by a client)
Network.h, Network.cc: definition of Network class, which is responsible for managing the podcasts available for 
	the given network, as well as keeping track of subscribers to that network. Note that to access (and listen to)
	a podcast, one must first subscribe to the network which hosts that podcast.
Subscriber.h, Subscriber.cc: definition of Subscriber class, which keeps track of the personal information of the
	subscriber, including payment information
Client.h, Client.cc: definition of Client class, responsible for managing the streaming experience of the user, as
	well as keeping track of all podcasts that have been downloaded for offline listening

TestControl.h, TestControl.cc, TestView.h, TestView.cc, main.cc: these files were provided by the instructor and have
	not been modified (except in TestControl.cc, the following line was added "#include <sstream>", otherwise it
	wouldn't have compiled).