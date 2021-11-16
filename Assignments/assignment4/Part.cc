#include "Part.h"

using namespace std;


// ctor & dtor
Part::Part(const & string productName) : name(partName), installationDate(new Date), flighthours(0) { }
Part::~Part() {
  delete installationDate;
}


// getters
const string Part::getPartName() const {
  return name;
}


// other
void Part::addFlightHours(int fh) {
  flightHours += fh;
}

void Part::install(Date& d) {
  installationDate = *d;
}
