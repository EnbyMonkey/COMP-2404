#include "Airline.h"

using namespace std;

Airline::Airline(const std::string& airlineName) : airlineName(airlineName) { }
Airline::~Airline() {
  for (int i = 0; i < aircraft.getSize(); ++i) {
    delete aircraft[i];
  }

  for (int i = 0; i < parts.getSize(); ++i) {
    delete parts[i];
  }
}

// getters
Aircraft* Airline::getAircraft(const std::string& registration) {
  for (int i = 0; i < aircraft.getSize(); ++i) {
    if (aircraft[i]->getRegistration() == registration) {
      return aircraft[i];
    }
  }
  return nullptr;
}

Part* Airline::getPart(const std::string& name) {
  for (int i = 0; i < parts.getSize(); ++i) {
    if (parts[i]->getPartName() == name) {
      return parts[i];
    }
  }
  return nullptr;
}

// other
bool Airline::addAircraft(const std::string& type, const std::string registration) {
  if (aircraft.getSize() == MAX_ARR) return true;

  aircraft.add(new Aircraft(type, registration));
  return true;
}

bool Airline::addPart(const std::string& partName, int fh_inspect, int it_inspect) {
  if (parts.getSize() == MAX_ARR) return false;
  if (fh_inspect == 0 && it_inspect == 0) return false;

  if (fh_inspect == 0) parts.add(new IT_Part(partName, it_inspect));
  else if (it_inspect == 0) parts.add(new FH_Part(partName, fh_inspect));
  else parts.add(new FHIT_Part(partName, fh_inspect, it_inspect));

  return true;
}

bool Airline::takeFlight(const std::string& registration, int flightHours) {
  Aircraft* aircraft = getAircraft(registration);
  if (aircraft == nullptr) return false;

  aircraft->takeFlight(flightHours);
  return true;
}

void Airline::inspectionReport(const string& registration, Date& date) {
  Aircraft* aircraft = getAircraft(registration);
  if (aircraft == nullptr) return;

  cout  << endl << endl;
  Array<Part*> partsToInspect;
  aircraft->inspectionReport(date, &partsToInspect);

  if (partsToInspect.getSize() == 0) {
    cout << aircraft->getRegistration() << " has no parts requiring inspection." << endl;
    return;
  }

  cout << "The following parts in " << aircraft->getRegistration() << " require inspection:" << endl;
  for (int i = 0; i < partsToInspect.getSize(); ++i) {
    cout << left << setw(4) << to_string(i+1) + ". " << *partsToInspect[i] << endl;
  }
}

bool Airline::install(const string& registration, const string& partName, Date& date) {
  Aircraft* aircraftPtr = getAircraft(registration);
  if (aircraftPtr == nullptr) return false;

  Part* partToInstall = getPart(partName);
  if (partToInstall == nullptr) return false;

  aircraftPtr->install(partToInstall, date);
  return true;
}

void Airline::printAircraft() const {
  cout << endl << endl << "Aircraft in " << airlineName << ":" << endl << endl;
  for (int i = 0; i < aircraft.getSize(); ++i) {
    cout << left << i+1 << setw(3) << ". " << *aircraft[i] << endl;
  }
  cout << endl;
}

void Airline::printParts() const {
  cout << endl << endl << "Parts in " << airlineName << ":" << endl << endl;
  for (int i = 0; i < parts.getSize(); ++i) {
    cout << left << setw(4) << to_string(i+1) + ". " << *parts[i] << endl;
  }
  cout << endl;
}
