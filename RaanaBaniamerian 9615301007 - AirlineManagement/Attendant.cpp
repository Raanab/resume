#include "Attendant.h"
#include "Human.h"
#include "Date.h"
#include <vector>
#include "Time.h"

ostream& operator <<(ostream& out, const Attendant& A){
    //out<<endl<<"Attendant Information"<<endl
    out<<"  First Name: "<<A.getFirstName()<<endl
        <<"  Last Name: "<<A.getLastName()<<endl
        <<"  ID Number: "<<A.getIDNum()<<endl
        <<"  Personnel No: "<<A.getPIDNum()<<endl
        <<"  BirthDate: ";
    A.getBirthDate();
    out<<"  HireDate: ";
    A.getHireDate();

    return out;
}

Attendant::Attendant()
    : Human(NULL, NULL, NULL),
    BirthDate(),
    HireDate()
{
    setPIDNum(NULL);
}

Attendant::Attendant(string fn, string ln, string idnum, string pidnum)
    : Human(fn, ln, idnum),
    BirthDate(),
    HireDate()
{
    setPIDNum(pidnum);
}

Attendant::Attendant(string fn, string ln, string idnum, string pidnum, const Date& birthdate, const Date& hiredate)
    : Human(fn, ln, idnum),
    BirthDate(birthdate),
    HireDate(hiredate)
{
    setPIDNum(pidnum);
}

Attendant::~Attendant(){
}

void Attendant::setPIDNum(string pidnum){
    if(checkChar(pidnum)){
        PIDNum = pidnum;
    }
}
string Attendant::getPIDNum() const{
    return PIDNum;
}

void Attendant::getBirthDate() const{
    BirthDate.printSlash();
}

void Attendant::getHireDate() const{
    HireDate.printSlash();
}
