#ifndef FLIGHT_H
#define FLIGHT_H

#include "Ticket.h"
#include "Passenger.h"
#include "Pilot.h"
#include <vector>
#include "Attendant.h"

class Flight : public Ticket{
protected:

private:
    string FlightNo, AirplaneNo;
    //Date FlightDate;
    Pilot pilot;
    vector <Passenger> vPassenger;
    vector <Attendant> vAttendant;
    unsigned int vPassSize, vAttSize;

public:
    Flight();
    Flight(string, string, string, string, Date&, Time&, Pilot&);
    Flight(string, string, string, string, Date&, Time&, Pilot&,
           Passenger&, Attendant&);

    //passenger
    void addPassengerToFlight(const Passenger&);
    unsigned int getvPassengerSize();
    void printvPassenger() const;

    //attendant
    void addAttendantToFlight(const Attendant &);
    unsigned int getvAttendantSize();
    void printvAttendant() const;

    void setFlightNo(string);
    string getFlightNo() const;

    void setAirplaneNo(string);
    string getAirplaneNo() const;

    Date getFlightDate() const;
    void printPilot() const;
    Pilot getPilot() const;

    friend std::ostream& operator <<(std::ostream&, const Flight&);
};
#endif // FLIGHT_H
