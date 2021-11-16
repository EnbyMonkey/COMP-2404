#ifndef AIRCRAFT_H
#define  AIRCRAFT_H


class Aircraft {
  public:

    // ctor and dtor
    Aircraft(const std::string& aircraftType, const std::string& aircraftRegistration);
    ~Aircraft();

    // getters
    const std::string& getRegistration() const;

    // other
    void install(Part* part, Date& date);
    void takeFlight(int hours);
    void inspectionReport(Date& date, Array<Part*> partsToInspect);

  private:
    std::string type; // the aircraft type
    const std::string registration; // This is the unique identifier of the aircraft
    int flightHours;
    Array<Part*> parts;

};

#endif
