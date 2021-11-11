#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include "defs.h"

// TODO - class summary
class Location {
  public:
    // constructors
    Location(char code, int nextId); // set id to code concatenated with nextIf
    virtual ~Location();


    // getters
    std::string getId() const;
    std::string getProduct() const;
    int getQuantity() const;

    // setters
    void setProduct(const std::string & productName);
    void setQuantity(int newQuantity);

    // other
    bool isEmpty() const;
    bool isAvailable() const;

    // virtual
    virtual int getCapacity() const = 0;
    virtual bool add(const std::string & productName, int quantityToAdd) = 0;
    virtual bool remove(int quantityToRemove) = 0;
    virtual void print() const = 0;

    // public atribute
    static const std::string NONE;

  protected:
    std::string id;       // label of location
    std::string product;  // name of product stored at this location
    int quantity;         // the quantity of product stored at this location


};

#endif
