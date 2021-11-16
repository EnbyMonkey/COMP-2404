#include "FH_Part.h"

using namespace std;

FH_Part::FH_Part(const string& partName, int hoursTillInspection) : Part(partName), fh_inspect(hoursTillInspection) { }
FH_Part~FH_Part() { }

// inherited virtual functions
bool FH_Part::inspection() const {
  return flightHours > fh_inspect;
}
