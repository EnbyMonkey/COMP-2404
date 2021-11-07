#ifndef LIST_H
#define LIST_H

#include "Product.h"

class List
{
  class Node
  {
    public:
      Product* data;
      Node*    next;
  };

  public:
    List();
    ~List();

    bool isEmpty() const;
    void findProduct(const std::string& productName, Product** prod) const;
    void add(Product* prod);
    void del(const std::string& productName, Product** prod);

    // print
    void print() const;

  private:
    Node* head;

};

#endif
