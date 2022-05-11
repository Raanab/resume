#ifndef PILOT_H
#define PILOT_H

#include "Attendant.h"

class Pilot : public Attendant{
    friend ostream& operator <<(ostream&, const Pilot&);
private:
    int Rank;

public:
    Pilot();
    Pilot(string, string, string, string,
          const Date&, const Date&, int);

    void setRank(int);
    int getRank() const;
};
#endif // PILOT_H
