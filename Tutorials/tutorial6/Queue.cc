#define DEBUG

#include "Queue.h"

using namespace std;


// constructor
Queue::Queue() {
  head = NULL;
  tail = NULL;
}

// destructor
Queue::~Queue() {
  Node* iterate = NULL; // to point to the next node
  if (!isEmpty()) {
    iterate = head;
  }

  while (iterate != NULL) {
    Node* temp = iterate;
    iterate = iterate->next;
    delete temp;
  }

}


// other
bool Queue::isEmpty() const {
  return head == NULL; // if head is NULL then queue is empty
}

void Queue::peekFirst(Student** student) const {
  if (isEmpty()) *student = NULL;
  else *student = head->data;
}

void Queue::popFirst(Student** student) {
  if (isEmpty()) *student = NULL;
  else {
    Node* temp = head;  // to delete current head node after reassigning head to the next node in the queue
    head = head->next;

    *student = temp->data;

    delete temp;
  }
}

void Queue::addLast(Student* student) {
  Node* temp = new Node;
  temp->data = student;
  temp->next = NULL;

  if (isEmpty()) {
    head = temp;
    tail = temp;
  }
  else {
    tail->next = temp;
    tail = temp;
  }
}

void Queue::print() const {
  if (isEmpty()) cout << "The queue is empty!" << endl;
  else if (head == tail) {
    cout << "There is only one student in the queue:" << endl;
    head->data->print();
    cout << endl;
  }
  else {
    Node* iterate = head;

    cout << "The students in the queue are:" << endl << endl;
    while (iterate != NULL) {
      iterate->data->print();
      iterate = iterate->next;
    }
    cout << endl;
  }
}
