#include "AirPlane.h"
#include "Flight.h"
#include <vector>

AirPlane::AirPlane()
: Seats(10),
SerialNo(NULL),
vFlight()
{
}
AirPlane::AirPlane(int seats, string serialno)
{
    setSeats(seats);
    setSerialNo(serialno);
}

AirPlane::AirPlane(int seats, string serialno, Flight &f)
{
    setSeats(seats);
    setSerialNo(serialno);
    addFlightToAirplane(f);
}

void AirPlane::setSeats(int s){
    Seats = ( s > 10 || s < 300 ) ? s:10;
}
int AirPlane::getSeats(){
    return Seats;
}

void AirPlane::setSerialNo(string serialno){
    if(serialno != ""){
        SerialNo = serialno;
    }
}
string AirPlane::getSerialNo() const{
    return SerialNo;
}

void AirPlane::addFlightToAirplane( const Flight &f){
    vFlight.push_back(f);
}

void AirPlane::getvFlight() const{
    for(int i=0; i<vFlight.size(); i++){
        cout<<vFlight[i];
    }
}
int AirPlane::getvFlightSize() const{
    return vFlight.size();
}
