#ifndef AIRCRAFT_H
#define  AIRCRAFT_H

#include "Part.h"
#include "Date.h"
#include "Array.h"

class Aircraft {
  public:

    // ctor and dtor
    Aircraft(const std::string& aircraftType, const std::string& aircraftRegistration);

    // getters
    const std::string& getRegistration() const;

    // other
    void install(Part* part, Date& date);
    void takeFlight(int hours);
    void inspectionReport(Date& date, Array<Part*>* partsToInspect);

    // print
    friend std::ostream& operator<<(std::ostream& out, const Aircraft& a);

  private:
    std::string type; // the aircraft type
    const std::string registration; // This is the unique identifier of the aircraft
    int flightHours;
    Array<Part*> parts; // these ptrs are shared with Airline, which is responsible for (de)allocation

};

#endif
