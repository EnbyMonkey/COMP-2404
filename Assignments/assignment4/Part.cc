#include "Part.h"

using namespace std;

/** class Part **/

// ctor & dtor
Part::Part(const string& partName) : partName(partName), flightHours(0) { }
Part::~Part() { }


// getters
const string Part::getPartName() const { return partName; }

// other
void Part::addFlightHours(int fh) { flightHours += fh; }
void Part::install(const Date& date) { installationDate = date; }

// overload operator<<
ostream& operator<<(ostream& output, const Part& part) {
  output << part.partName << ", installed on: " << part.installationDate << "total flight hours: " << part.flightHours << endl;

  return output;
}

/** class FH_Part **/

// ctor
FH_Part::FH_Part(const string& partName, int fh_inspect) : Part(partName), fh_inspect(fh_inspect) { }
FH_Part::~FH_Part() { }

bool FH_Part::inspection(const Date& d) const { return flightHours > fh_inspect; }

// overload operator<<
ostream& operator<<(ostream& output, const FH_Part& part) {
  output << part.partName << ", installed on: " << part.installationDate << ", total flight hours: " << part.flightHours
         << ", inspections should occur every " << part.fh_inspect << " flight hours" << endl;

  return output;
}

/** class IT_Part **/

// ctor
IT_Part::IT_Part(const string& partName, int it_inspect) : Part(partName), it_inspect(it_inspect) { }
IT_Part::~IT_Part() { }

bool IT_Part::inspection(const Date& d) const { return d - installationDate > it_inspect; }
ostream& operator<<(ostream& output, const IT_Part& part) {
  output << part.partName << ", installed on: " << part.installationDate << ", total flight hours: " << part.flightHours
         << ", inspections should occur after " << part.it_inspect << " days" << endl;

  return output;
}

/** class FHIT_Part **/

// ctor
FHIT_Part::FHIT_Part(const string& partName, int fh_inspect, int it_inspect) : Part(partName),
  FH_Part(partName, fh_inspect), IT_Part(partName, it_inspect) { }
FHIT_Part::~FHIT_Part() { }

bool FHIT_Part::inspection(const Date& d) const { return FH_Part::inspection(d) || IT_Part::inspection(d); }

// overload operator<<
ostream& operator<<(ostream& output, const FHIT_Part& part) {
	output << part.partName << ", installed on: " << part.installationDate << ", total flight hours: " << part.flightHours
         << ", inspections should occur after " << part.it_inspect << " days" << " or after "
         << part.fh_inspect << " flight hours" << endl;

  return output;
}
