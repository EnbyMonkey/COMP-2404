#ifndef PART_H
#define PART_H

#include <string>
#include "Date.h"

class Part {

  public:

    // ctor & dtor
    Part(const std::string& partName);
    virtual ~Part();


    // getters
    const string getPartName() const;


    // other
    void addFlightHours(int fh);
    void install(const Date& d);


    // print
    // overload << instead of print()


    // pure virtual
    virtual bool inspection(const Date& d) const = 0;


  protected:
    std::string partName;
    Date installationDate;
    int flightHours;

};

class FH_Part : virtual public Part {
  public:

    // ctor & dtor
    FH_Part(const std::string& partName, int hoursTillInspection);
    ~FH_Part();

    // inherited virtual functions
    virtual bool inspection(const Date& d) const;


  protected:
    int fh_inspect; // the number of flight hours until inspection is required
};

class IT_Part : virtual public Part {
  public:

    // ctor & dtor
    IT_Part(const std::string& partName, int hoursTillInspection);
    ~IT_Part();

    // inherited virtual functions
    virtual bool inspection(const Date& d) const;


  protected:
    int it_inspect; // the number of flight hours until inspection is required
};

class FHIT_Part : virtual public FH_Part, virtual public IT_Part {
  public:

    // ctor & dtor
    FHIT_Part(const std::string& partName, int fh_hoursTillInspection, int it_hoursTillInspections);
    ~FHIT_Part();

    // inherited virtual functions
    virtual bool inspection(const Date& d) const;

};


#endif
