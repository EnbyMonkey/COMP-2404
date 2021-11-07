#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include "PodArray.h"
#include "Subscriber.h"


class Network {

  public:
    // constructors
    Network(const std::string& name = "Exactly Right");
    ~Network();

    // getters
    bool getPodcast(const std::string& podcast, Podcast** pod) const;
    bool getSubscriber(const std::string& name, Subscriber** sub) const;

    // add and remove
    bool addPodcast(const std::string& podcast, const std::string& host);
    bool removePodcast(const std::string& podcast);
    bool addEpisode(const std::string& podcast, const std::string& title, const std::string content);
    bool addSubscriber(const std::string& name, const std::string& creditcard);

    // client services
    bool download(const std::string& subscriber, const std::string& podcast, Podcast** pod);
    bool stream(const std::string& subscriber, const std::string& podcast, int episode, Episode** ep);

    // other
    bool hasSubscriber(const std::string& name) const;
    void print() const;

  private:
    std::string name; // the name of the network
    PodArray* pods;
    int numSubs = 0; // number of subscribers in subs array
    Subscriber* subs[MAX_SUBS];

};


#endif
