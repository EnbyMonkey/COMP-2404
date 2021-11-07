#include "Client.h"

using namespace std;

Client::Client(const string& name) {
  this->name = name;
  pods = new PodArray;
}

Client::~Client() {
  delete pods;
}

void Client::download(Network* network, const string& podcast) {
  Podcast* temp;
  if (!network->download(name, podcast, &temp)) return;

  Podcast* p = new Podcast(*temp);
  if (!pods->addPodcast(p)) {
    cout << "ERROR: Could not download podcast." << endl;
    return;
  }

  cout << "Successfully downloaded podcast." << endl;

}

void Client::stream(Network* network, const string& podcast, int episode) {
  Episode* e;
  if (!network->stream(name, podcast, episode, &e)) return;

  e->play();
}

void Client::playLocal(const string& podcast, int episode) {
  Podcast* p;
  if (!pods->getPodcast(podcast, &p)) {
    cout << "ERROR: Podcast not found." << endl;
    return;
  }

  Episode* e;
  if (!p->getEpisode(episode, &e)) {
    cout << "ERROR: Episode not found." << endl;
    return;
  }

  e->play();

}
