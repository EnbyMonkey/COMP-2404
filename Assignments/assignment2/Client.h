#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "Network.h"


class Client {

  public:
    //constructors
    Client(const std::string& name = "Mr. Milo Gruntlebottom"); // that's my cat 
    ~Client();

    // client services
    void download(Network* network, const std::string& podcast);
    void stream(Network* network, const std::string& podcast, int episode);
    void playLocal(const std::string& podcast, int episode);


  private:
    std::string name;
    PodArray* pods;

};

#endif
