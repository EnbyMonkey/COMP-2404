#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "WHLocation.h"

using namespace std;

class Queue
{
  class Node
  {
    public:
      WHLocation* data;
      Node*    next;
  };

  public:

    // ctor & dtor
    Queue();
    ~Queue();

    // other
    bool isEmpty() const;
    void peekFirst(WHLocation** whloc) const;
    void popFirst(WHLocation** whloc);
    void addLast(WHLocation* whloc);

    void print() const;

  private:
    Node* head;
    Node* tail;

};

#endif
