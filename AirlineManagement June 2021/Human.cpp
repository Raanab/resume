#include "Human.h"
#include <iostream>
using namespace std;

ostream& operator <<(ostream& out, const Human& H){
    //out<<"Human Information"<<endl
    out<<"  First Name: "<<H.getFirstName()<<endl
        <<"  Last Name: "<<H.getLastName()<<endl
        <<"  ID Number: "<<H.getIDNum()<<endl;
    return out;
}
Human::Human(){
    setFirstName("NULL");
    setLastName("NULL");
    setIDNum("NULL");
}

Human::Human(string fn, string ln, string idnum){
    setFirstName(fn);
    setLastName(ln);
    setIDNum(idnum);
}
Human::~Human(){
}

bool Human::checkChar(string s){
    if(s == ""){
        cout<<"Field can not be empty!";
        return false;
    }
    else{
        return true;
    }
}

void Human::setFirstName(string fn){
    if(checkChar(fn)){
        FirstName = fn;
    }
}
string Human::getFirstName() const{
    return FirstName;
}

void Human::setLastName(string ln){
    if(checkChar(ln)){
        LastName = ln;
    }
}
string Human::getLastName() const{
    return LastName;
}

void Human::setIDNum(string idnum){
    if(checkChar(idnum)){
        IDNum = idnum;
    }
}
string Human::getIDNum() const{
    return IDNum;
}
