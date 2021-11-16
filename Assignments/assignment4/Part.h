#ifndef PART_H
#define PART_H

#include <string>
#include "Date.h"

class Part {

  public:

    // ctor & dtor
    Part(const& std::string partName);
    ~Part();


    // getters
    const string getPartName() const;


    // other
    void addFlightHours(int fh);
    void install(Date& d);


    // print
    // overload << instead of print()


    // pure virtual
    virtual bool inspection() const;


  protected:
    std::string name; // The name and unique identifier of the Part
    Date installationDate; // The date this part was installed on an aircraft
    int flightHours; // The number of hours this part has own installed on an aircraft

};


#endif
