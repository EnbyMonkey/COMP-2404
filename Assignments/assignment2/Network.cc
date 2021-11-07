#include <iostream>
#include "Network.h"

using namespace std;

// default constructor
Network::Network(const string& name) {
 this->name = name;
 pods = new PodArray;
}

// destructor
Network::~Network() {
  delete pods;
  for (int i = 0; i < numSubs; ++i) {
    delete subs[i];
  }
}

// getters
bool Network::getPodcast(const string& podcast, Podcast** pod) const {
  return pods->getPodcast(podcast, pod);
}

bool Network::getSubscriber(const string& name, Subscriber** sub) const {
  for (int i = 0; i < numSubs; ++i) {
    if (subs[i]->matches(name)) {
      *sub = subs[i];
      return true;
    }
  }
  return false;
}

// add and remove
bool Network::addPodcast(const string& podcast, const string& host) {
  Podcast* p = new Podcast(podcast, host);
  return pods->addPodcast(p);
}

bool Network::removePodcast(const string& podcast) {
  Podcast* p;
  if (pods->removePodcast(podcast, &p)) {
    delete p;
    return true;
  }
  return false;
}

bool Network::addEpisode(const string& podcast, const string& title, const string content) {
  Podcast* p;
  if (!pods->getPodcast(podcast, &p)) return false;

  return p->addEpisode(title, content);
}

bool Network::addSubscriber(const string& name, const string& creditcard) {
  if (numSubs >= MAX_SUBS) return false;

  subs[numSubs] = new Subscriber(name, creditcard);
  ++numSubs;
  return true;
}

// client services
bool Network::download(const string& subscriber, const string& podcast, Podcast** pod) {
  if (!hasSubscriber(subscriber)) {
    cout << "ERROR: Subscriber not found." << endl;
    return false;
  }

  Podcast* p;
  if (!getPodcast(podcast, &p)) {
    cout << "ERROR: Podcast not found." << endl;
    return false;
  }

  *pod = p;
  return true;
}

bool Network::stream(const string& subscriber, const string& podcast, int episode, Episode** ep) {
  Podcast* p;
  if (!download(subscriber, podcast, &p)) {
    return false;
  }

  Episode* e;
  if (!p->getEpisode(episode, &e)) {
    cout << "ERROR: The given episode does not exist." << endl;
    return false;
  }

  *ep = e;
  return true;
}

// other
bool Network::hasSubscriber(const string& name) const {
  for (int i = 0; i < numSubs; ++i) {
    if (subs[i]->matches(name)) return true;
  }
  return false;
}

void Network::print() const {
  cout << "Subscribers on " << name << " Network:" << endl;
  for (int i = 0; i < numSubs; ++i) subs[i]->print();

  cout << "Podcasts on " << name << " Network:" << endl;
  pods->print();
}
