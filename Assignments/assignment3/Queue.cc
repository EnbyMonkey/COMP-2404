
#include "Queue.h"

using namespace std;


// ctor & dtor
Queue::Queue() : head{nullptr}, tail{nullptr} { }

Queue::~Queue() {
  Node* iterate = nullptr;
  if (!isEmpty()) {
    iterate = head;
  }

  while (iterate != nullptr) {
    Node* temp = iterate;
    iterate = iterate->next;
    delete temp;
  }
}


// other
bool Queue::isEmpty() const {
  return head == nullptr;
}

void Queue::peekFirst(WHLocation** whloc) const {
  if (isEmpty()) *whloc = nullptr;
  else *whloc = head->data;
}

void Queue::popFirst(WHLocation** whloc) {
  if (isEmpty()) *whloc = nullptr;
  else {
    Node* temp = head;
    head = head->next;

    *whloc = temp->data;

    delete temp;
  }
}

void Queue::addLast(WHLocation* whloc) {
  Node* temp = new Node;
  temp->data = whloc;
  temp->next = nullptr;

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
    cout << "There warehocation in the queue is:" << endl;
    head->data->print();
  }

  else {
    Node* iterate = head;

    cout << "The warehouse locations in the queue are:" << endl;
    while (iterate != nullptr) {
      iterate->data->print();
      cout << endl;
      iterate = iterate->next;
    }
  }

  cout << endl;
}
