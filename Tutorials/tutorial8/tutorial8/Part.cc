#include "Part.h"

using namespace std;


// ctor & dtor
Part::Part(const string& productName) : partName(partName), flightHours(0) { }
Part::~Part() { }


// getters
const string Part::getPartName() const { return partName; }


// other
void Part::addFlightHours(int fh) { flightHours += fh; }
void Part::install(const Date& d) { installationDate = d; }



FH_Part::FH_Part(const string& partName, int hoursTillInspection) : Part(partName), fh_inspect(hoursTillInspection) { }
FH_Part::~FH_Part() { }

// inherited virtual functions
bool FH_Part::inspection(const Date& d) const { return flightHours > fh_inspect; }

IT_Part::IT_Part(const string& partName, int hoursTillInspection) : Part(partName), it_inspect(hoursTillInspection) { }
IT_Part::~IT_Part() { }

// inherited virtual functions
bool IT_Part::inspection(const Date& d) const { return d - installationDate > it_inspect; }

FHIT_Part::FHIT_Part(const string& partName, int fh_hoursTillInspection, int it_hoursTillInspection) : Part(partName),
  FH_Part(partName, fh_hoursTillInspection), IT_Part(partName, it_hoursTillInspection) { }
FHIT_Part::~FHIT_Part() { }

// inherited virtual functions
bool FHIT_Part::inspection(const Date& d) const { return FH_Part::inspection(d) || IT_Part::inspection(d); }
