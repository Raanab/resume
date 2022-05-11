#include <iostream>
#include "Pilot.h"
#include "Attendant.h"

ostream& operator <<(ostream& out, const Pilot& P){
    //out<<endl<<"Pilot Information"<<endl
    out<<"  First Name: "<<P.getFirstName()<<endl
        <<"  Last Name: "<<P.getLastName()<<endl
        <<"  ID Number: "<<P.getIDNum()<<endl
        <<"  Personnel No: "<<P.getPIDNum()<<endl
        <<"  Rank: "<<P.getRank()<<endl
        <<"  BirthDate: ";
    P.getBirthDate();
    out<<"  HireDate: ";
    P.getHireDate();

    return out;
}

Pilot::Pilot()
: Attendant("NULL", "NULL", "NULL", "NULL")
{
    setRank(10);
}
Pilot::Pilot(string fn, string ln, string idnum, string pidnum,
       const Date& birthdate, const Date& hiredate,
        int rank)
: Attendant(fn, ln, idnum, pidnum, birthdate, hiredate)
{
    setRank(rank);
}
void Pilot::setRank(int rank){
    Rank = ( rank > 0 || rank < 10) ? rank : 10;
}
int Pilot::getRank() const{
    return Rank;
}
