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
    void install(const Date& date);

    //friend ostream& operator<<(ostream& out, const Part& part);

    // pure virtual
    virtual bool inspection(const Date& d) const = 0;
    virtual void print(std::ostream& os) const = 0;


  protected:
    std::string partName;
    Date installationDate;
    int flightHours;

};

class FH_Part : virtual public Part {
  public:

    // ctor & dtor
    FH_Part(const std::string& partName, int fh_inspect);
    virtual ~FH_Part();

    //friend ostream& operator<<(ostream& out, const FH_Part& part);
    virtual bool inspection(const Date& d) const;
    virtual void print(std::ostream& os) const;

  protected:
    int fh_inspect; // the number of flight hours until inspection is required
};

class IT_Part : virtual public Part {
  public:

    // ctor & dtor
    IT_Part(const std::string& partName, int it_inspect);
    virtual ~IT_Part();

    //friend ostream& operator<<(ostream& out, const IT_Part& part);
    virtual bool inspection(const Date& d) const;
    virtual void print(std::ostream& os) const;

  protected:
    int it_inspect; // the number of days installed until inspection is required
};

class FHIT_Part : virtual public FH_Part, virtual public IT_Part {
  public:

    // ctor & dtor
    FHIT_Part(const std::string& partName, int fh_inspect, int it_inspect);
    ~FHIT_Part();

    //friend ostream& operator<<(ostream& out, const FHIT_Part& part);
    virtual bool inspection(const Date& d) const;
    virtual void print(std::ostream& os) const;

};

// overload operator<<
inline ostream& operator<<(ostream& os, const Part& p) {
    p.print(os);
    return os;
}

#endif
