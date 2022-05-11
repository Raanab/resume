#include "Flight.h"
#include "Ticket.h"
#include "Passenger.h"
#include "Pilot.h"
#include <vector>
#include "Attendant.h"

Flight::Flight()
:
FlightNo(NULL),
AirplaneNo(NULL),
Ticket(),
vPassenger(),
vAttendant()
{
}

Flight::Flight(string flightno, string airplaneno,
       string origin, string destination,
       Date &flightdate, Time &t, Pilot &p)
:
pilot(p),
vPassenger(),
vAttendant(),
Ticket(origin, destination, flightdate, t)
{
    setFlightNo(flightno);
    setAirplaneNo(airplaneno);
}

Flight::Flight(string flightno, string airplaneno,
               string origin, string destination,
               Date &flightdate, Time &t, Pilot &p,
       Passenger &pass, Attendant &a)
:Ticket(origin, destination, flightdate, t),
pilot(p)
{
    setFlightNo(flightno);
    setAirplaneNo(airplaneno);
    addPassengerToFlight(pass);
    addAttendantToFlight(a);
}

//passenger
void Flight::addPassengerToFlight(const Passenger &p){
    vPassenger.push_back(p);
}
unsigned int Flight::getvPassengerSize(){
    vPassSize = vPassenger.size();
    return vPassSize;
}
void Flight::printvPassenger() const{
    for(int i=0; i<vPassenger.size(); i++){
        cout<<vPassenger[i]<<endl;
    }
}
//attendant
void Flight::addAttendantToFlight(const Attendant &a){
    vAttendant.push_back(a);
}
unsigned int Flight::getvAttendantSize(){
    vAttSize = vAttendant.size();
    return vAttSize;
}
void Flight::printvAttendant() const{
    for(int i=0; i<vAttendant.size(); i++){
        cout<<vAttendant[i]<<endl;
    }
}

void Flight::setFlightNo(string flightno){
    if(flightno != ""){
        FlightNo = flightno;
    }
}
string Flight::getFlightNo() const{
    return FlightNo;
}

void Flight::setAirplaneNo(string airplaneno){
    if(airplaneno != ""){
        AirplaneNo = airplaneno;
    }
}
string Flight::getAirplaneNo() const{
    return AirplaneNo;
}

Date Flight::getFlightDate() const{
    return FlightDate;
}

void Flight::printPilot() const{
    cout<<pilot;
}
Pilot Flight::getPilot() const{
    return pilot;
}

std::ostream& operator <<(std::ostream& out, const Flight &f){
    //out<<std::endl<<"Flight Information"<<std::endl
    out <<"  Flight No: "<<f.getFlightNo()<<std::endl
        <<"  Airplane No: "<<f.getAirplaneNo()<<std::endl
        <<"  Origin: "<<f.getOrigin()<<std::endl
        <<"  Destination: "<<f.getDestination()<<std::endl
        <<"  Date: ";
    f.printDate();
    out<<"  Time: ";
    f.printTime();
    f.printvPassenger();
    f.printvAttendant();
    return out;
}
