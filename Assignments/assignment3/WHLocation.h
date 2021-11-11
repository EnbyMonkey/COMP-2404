#ifndef WHLOCATION_H
#define WHLOCATION_H

#include "Location.h"


// TOD) - class summary
class WHLocation : virtual public Location {

  public:
    WHLocation();
    virtual ~WHLocation();

    // getters
    int getQuantity();

    // inherited from Location class
    virtual int getCapacity() const;
    virtual bool add(const std::string& productName, int quantityToAdd);
    virtual bool remove(int quantityToRemove);

    // print
    virtual void print() const;

  private:
    static const char code;
    static const int capacity;
    static int nextId;

};

#endif
