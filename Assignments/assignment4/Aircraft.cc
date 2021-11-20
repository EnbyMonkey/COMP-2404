#include <typeinfo>
#include "Aircraft.h"

using namespace std;

Aircraft::Aircraft(const string& aircraftType, const string& aircraftRegistration) : type(aircraftType),
  registration(aircraftRegistration), flightHours(0) { }

// getters
const string& Aircraft::getRegistration() const {
  return registration;
}

// other
void Aircraft::install(Part* part, Date& date) {
  part->install(date);
  parts.add(part);
}

void Aircraft::takeFlight(int hours) {
  flightHours += hours;
  for (int i = 0; i < parts.getSize(); ++i) {
    parts[i]->addFlightHours(hours);
  }
}

void Aircraft::inspectionReport(Date& date, Array<Part*>* partsToInspect) {
  for (int i = 0; i < parts.getSize(); ++i) {
    if (parts[i]->inspection(date)) {
      partsToInspect->add(parts[i]);
    }
  }
}

ostream& operator<<(ostream& out, const Aircraft& a) {
  out << a.type << ", registration: " << a.registration << ", flight hours: " << a.flightHours << ", parts:" << endl;
  for (int i = 0; i < a.parts.getSize(); ++i) {
    out << "   " << a.parts[i];
  }
  return out;
}
