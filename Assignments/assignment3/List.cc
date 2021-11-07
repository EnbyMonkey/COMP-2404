#include <iostream>
#include <string>
#include "List.h"

using namespace std;


List::List() : head(nullptr) { }

List::~List()
{
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != nullptr) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

bool List::isEmpty() const {
  return head == nullptr;
}

void List::findProduct(const std::string& productName, Product** prod) const {
  if (isEmpty()) {
    *prod = nullptr;
    return;
  }

  Node* currNode;

  currNode = head;

  while (currNode != nullptr) {
    if (currNode->data->getName() == productName) {  // product found
      *prod = currNode->data;
      return;
    }

    currNode = currNode->next;
  }

  *prod = nullptr; // product not found
}

// adds product to list in alphabetical order
void List::add(Product* prod)
{
  Node* newNode = new Node;
  newNode->data = prod;
  newNode->next = nullptr;

  Node* currNode = head;
  Node* prevNode = nullptr;

  while (currNode != nullptr) {
    if (newNode->data->getName() < currNode->data->getName()) // add product in alphabetical order
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == nullptr)
    head = newNode;
  else
    prevNode->next = newNode;

  newNode->next = currNode;
}

void List::del(const string& productName, Product** prod)
{
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = nullptr;

  while (currNode != nullptr) {
    if (currNode->data->getName() == productName)
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == nullptr) {  // list is empty
    *prod = nullptr;
    return;
  }

  if (prevNode == nullptr)   // list has 1 node
    head = currNode->next;
  else
    prevNode->next = currNode->next;  // list has 2+ node

  *prod = currNode->data;
  delete currNode;
}

void List::print() const
{
  Node* currNode = head;

  while (currNode != nullptr) {
    currNode->data->print();
    cout << endl;
    currNode = currNode->next;
  }
}
