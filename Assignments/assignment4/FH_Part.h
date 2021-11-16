#ifndef FH_PART_H
#define FH_PART_H

class FH_Part : public Part {
  public:

    // ctor & dtor
    FH_Part(const std::string& partName, int hoursTillInspection);
    ~FH_Part();

    // inherited virtual functions
    virtual bool inspection() const;


  protected:
    int fh_inspect; // the number of flight hours until inspection is required
};


#endif
