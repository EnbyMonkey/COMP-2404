#include "FHIT_Part.h"

using namespace std;

FHIT_Part::FHIT_Part(const string& partName, int fh_hoursTillInspection, int it_hoursTillInspection) :
  FH_Part(partName, fh_hoursTillInspection), IT_Part(partName, it_hoursTillInspection) { }
IT_Part~IT_Part() { }

// inherited virtual functions
bool FHIT_Part::inspection() const {
  return FH_Part::inspection() && IT_Part::inspection();
}
