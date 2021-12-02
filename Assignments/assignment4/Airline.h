#ifndef AIRLINE_H
#define AIRLINE_H

#include "Part.h"
#include "Aircraft.h"

class Airline {
  public:
    //  ctor & dtor
    Airline(const std::string& airlineName);
    ~Airline();

    // other
    bool addAircraft(const std::string& type, const std::string registration);
    bool addPart(const std::string& partName, int fh_inspect, int it_inspect);
    bool takeFlight(const std::string& registration, int flightHours);
    void inspectionReport(const std::string& registration, Date& d);
    bool install(const std::string& aircraftRegistration, const std::string& partName, Date& d);

    // printing
    void printAircraft() const;
    void printParts() const;




  private:

    // getters
    Aircraft* getAircraft(const std::string& registration);
    Part* getPart(const std::string& name);


    std::string airlineName;
    Array<Part*> parts;
    Array<Aircraft*> aircraft;

};

#endif
