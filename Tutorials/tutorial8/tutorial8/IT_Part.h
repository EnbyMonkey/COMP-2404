#ifndef IT_PART_H
#define IT_PART_H

#include "Part.h"

class IT_Part : public Part {
  public:

    // ctor & dtor
    IT_Part(const std::string& partName, int hoursTillInspection);
    ~IT_Part();

    // inherited virtual functions
    virtual bool inspection(Date& d) const;


  protected:
    int it_inspect; // the number of flight hours until inspection is required
};


#endif
