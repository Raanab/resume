#ifndef PASSENGER_H
#define PASSENGER_H

#include "Human.h"

class Passenger : public Human {
    friend ostream& operator <<(ostream&, const Passenger&);

public:
    Passenger();
    Passenger(string, string, string);
    ~Passenger();
};

#endif // PASSENGER_H
