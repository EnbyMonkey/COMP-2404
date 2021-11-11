#ifndef STORELOCATION_H
#define STORELOCATION_H

#include "Location.h"


// TODO - class summary
class StoreLocation : virtual public Location {

  public:
    StoreLocation();
    virtual ~StoreLocation();

    // setter
    void setProduct(const std::string& productName);

    // other
    int getFreeSpace() const;

    // print function
    virtual void print() const;

    // inherited from Location
    virtual int getCapacity() const;
    virtual bool add(const std::string& productName, int quantityToAdd);
    virtual bool remove(int quantityToRemove);

  private:
    static const char code;
    static const int capacity;
    static int nextId;

};

#endif
