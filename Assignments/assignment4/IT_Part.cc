#include "IT_Part.h"

using namespace std;

IT_Part::IT_Part(const string& partName, int hoursTillInspection) : Part(partName), it_inspect(hoursTillInspection) { }
IT_Part~IT_Part() { }

// inherited virtual functions
bool IT_Part::inspection() const {
  return flightHours > it_inspect;
}
