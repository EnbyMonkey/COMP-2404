#ifndef QUEUE_H
#define QUEUE_H

#include "Student.h"

class Queue
{
  class Node
  {
    public:
      Student* data;
      Node*    next;
  };

  public:
    // constructors
    Queue();
    ~Queue();

    // other
    bool isEmpty() const;
    void peekFirst(Student** student) const;
    void popFirst(Student** student);
    void addLast(Student* student);

    void print() const;

  private:
    Node* head;
    Node* tail;

};

#endif
