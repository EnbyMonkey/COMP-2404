#ifndef FHIT_PART_H
#define FHIT_PART_H

#include "FH_Part.h"
#include "IT_Part.h"

class FHIT_Part : public FH_Part, public IT_Part {
  public:

    // ctor & dtor
    FHIT_Part(const std::string& partName, int fh_hoursTillInspection, int it_hoursTillInspections);
    ~FHIT_Part();

    // inherited virtual functions
    virtual bool inspection(Date&) const;

};


#endif
