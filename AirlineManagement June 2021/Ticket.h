#include <iostream>
#ifndef TICKET_H
#define TICKET_H

#include "Date.h"
#include "Passenger.h"
#include "Time.h"

class Ticket{
    friend std::ostream& operator <<(std::ostream&, const Ticket&);

protected:
    Date FlightDate;
    Passenger p;
    Time time;
    string Origin, Destination;

public:
    Ticket();
    Ticket(string, string, Date&, Time&);
    Ticket(string, string, Passenger&, Date&, Time&);
    ~Ticket();

    void setOrigin(string);
    string getOrigin() const;

    void setDestination(string);
    string getDestination() const;

    void printDate() const;
    Date getDate() const;

    void getPassenger() const;

    void printTime() const;
    Time getTime() const;

    void print() const;
};
#endif // TICKET_H
