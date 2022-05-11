#include "Human.h"
#include "Passenger.h"
#include <iostream>
using namespace std;

ostream& operator <<(ostream& out, const Passenger& P){
    //out<<endl<<"Passenger Information"<<endl
    out<<"  First Name: "<<P.getFirstName()<<endl
        <<"  Last Name: "<<P.getLastName()<<endl
        <<"  ID Number: "<<P.getIDNum()<<endl;
    return out;
}
Passenger::Passenger()
: Human("NULL", "NULL", "NULL")
{}

Passenger::Passenger(string fn, string ln, string idnum)
: Human(fn, ln, idnum)
{}

Passenger::~Passenger(){
}
