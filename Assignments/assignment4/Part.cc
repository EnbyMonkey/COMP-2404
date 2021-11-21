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

/** class FH_Part **/

// ctor
FH_Part::FH_Part(const string& partName, int fh_inspect) : Part(partName), fh_inspect(fh_inspect) { }
FH_Part::~FH_Part() { }

bool FH_Part::inspection(const Date& d) const { return flightHours >= fh_inspect; }

void FH_Part::print(std::ostream& os) const {
  os << left << setw(20) << "Part:" << partName << endl;
  os << setw(4) << "" << setw(20) << "Flight hours: " << flightHours << " hours" << endl;
  os << setw(4) << "" << setw(20) << "Installation date:";
  if (installationDate.toDays() == 1) {
    os << "Not installed in any aircraft." << endl;
    return;
  }
  else os << installationDate << endl;
  os << setw(4) << "" << setw(20) << "Inspection:" << "every " + to_string(fh_inspect) + " flight hours" << endl;
}

/** class IT_Part **/

// ctor
IT_Part::IT_Part(const string& partName, int it_inspect) : Part(partName), it_inspect(it_inspect) { }
IT_Part::~IT_Part() { }

bool IT_Part::inspection(const Date& d) const { return d - installationDate > it_inspect; }

void IT_Part::print(std::ostream& os) const {
  os << left << setw(20) << "Part:" << partName << endl;
  os << setw(4) << "" << setw(20) << "Flight hours: " << flightHours << " hours" << endl;
  os << setw(4) << "" << setw(20) << "Installation date:";
  if (installationDate.toDays() == 1) {
    os << "Not installed in any aircraft." << endl;
    return;
  }
  else os << installationDate << endl;
  os << setw(4) << "" << setw(20) << "Inspection:" << to_string(it_inspect) + " days after installation" << endl;
}

/** class FHIT_Part **/

// ctor
FHIT_Part::FHIT_Part(const string& partName, int fh_inspect, int it_inspect) : Part(partName),
  FH_Part(partName, fh_inspect), IT_Part(partName, it_inspect) { }

FHIT_Part::~FHIT_Part() { }

bool FHIT_Part::inspection(const Date& d) const { return FH_Part::inspection(d) || IT_Part::inspection(d); }

void FHIT_Part::print(std::ostream& os) const {
  os << left << setw(20) << "Part:" << partName << endl;
  os << setw(4) << "" << setw(20) << "Flight hours: " << flightHours << " hours" << endl;
  os << setw(4) << "" << setw(20) << "Installation date:";
  if (installationDate.toDays() == 1) {
    os << "Not installed in any aircraft." << endl;
    return;
  }
  else os << installationDate << endl;
  os << setw(4) << "" << setw(20) << "Inspection:" << "every " + to_string(fh_inspect) + " flight hours" << endl;
  os << setw(4) << "" << setw(20) << "Inspection:" << to_string(it_inspect) + " days after installation" << endl;
}
