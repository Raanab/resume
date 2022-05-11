#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "Flight.h"
#include <vector>

class AirPlane{
private:
    int Seats;
    string SerialNo;
    vector <Flight> vFlight;

public:
    AirPlane();
    AirPlane(int, string);
    AirPlane(int, string, Flight&);

    void setSeats(int);
    int getSeats();

    void setSerialNo(string);
    string getSerialNo() const;

    void addFlightToAirplane( const Flight&);

    void getvFlight() const;
    int getvFlightSize() const;
};
#endif // AIRPLANE_H
