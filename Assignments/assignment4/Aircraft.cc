#include "Aircraft.h"

using namespace std;

Aircraft::Aircraft(const string& aircraftType, const string& aircraftRegistration) : type(aircraftType),
  registration(aircraftRegistration), flightHours(0), parts(new Array<Part* p>) { }
Aircraft::~Aircraft() {
  delete parts;
}

// getters
const string& getRegistration() const {
  return registration;
}

// other
void install(Part* part, Date& date) {
  part->install(date);
  parts.add(part);
}

void takeFlight(int hours) {
  flightHours += hours;
  for (int i = 0; i < parts.size(); ++i) {
    parts[i]->addFlightHours(hours);
  }
}

void inspectionReport(Date& date, Array<Part*> partsToInspect) {
  flightHours += hours;
  for (int i = 0; i < parts.size(); ++i) {
    if (parts[i]->inspection(hours)) partsToInspect.add(parts[i]);
  }
}
