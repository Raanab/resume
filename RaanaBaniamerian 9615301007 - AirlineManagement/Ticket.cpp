#include "Ticket.h"

#include <iostream>
#include "Date.h"
#include "Passenger.h"
#include "Time.h"


Ticket::Ticket()
: FlightDate(),
p(),
time()
{
    setOrigin("NULL");
    setDestination("NULL");
}
Ticket::Ticket(string origin, string destination,
       Date &fdate, Time &t)
: FlightDate(fdate),
time(t)
{
    setOrigin(origin);
    setDestination(destination);
}
Ticket::Ticket(string origin, string destination,
       Passenger &pass,
       Date &fdate, Time &t)
: FlightDate(fdate),
p(pass),
time(t)
{
    setOrigin(origin);
    setDestination(destination);
}

Ticket::~Ticket(){
}

void Ticket::setOrigin(string origin){
    if(origin != ""){
        Origin = origin;
    }
}
string Ticket::getOrigin() const{
    return Origin;
}

void Ticket::setDestination(string destination){
    if(destination != ""){
        Destination = destination;
    }
}
string Ticket::getDestination() const{
    return Destination;
}

void Ticket::printDate() const{
    FlightDate.printSlash();
}
Date Ticket::getDate() const{
    return FlightDate;
}

void Ticket::getPassenger() const{
    cout<<p;
}

void Ticket::printTime() const{
    time.printUniversal();
}
Time Ticket::getTime() const{
    return time;
}

std::ostream& operator <<(std::ostream& out, const Ticket &t){
    out<<std::endl<<"     Ticket Information"<<std::endl<<std::endl
        <<"  Origin: "<<t.getOrigin()<<std::endl
        <<"  Destination: "<<t.getDestination()<<std::endl
        <<"  Date: ";
    t.printDate();
    out<<"  Time: ";
    t.printTime();
    t.getPassenger();

    return out;
}

void Ticket::print() const{
    cout<<this;
}
