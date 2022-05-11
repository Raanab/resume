#ifndef ATTENDANT_H
#define ATTENDANT_H

#include "Human.h"
#include "Date.h"
#include <vector>
#include "Time.h"

class Attendant: public Human {
    friend ostream& operator <<(ostream&, const Attendant&);
protected:
    string PIDNum; //Personnel ID Number
    Date BirthDate, HireDate;

    vector <int> FlightIndex;

public:
    Attendant();
    Attendant(string, string, string, string);
    Attendant(string, string, string, string, const Date&, const Date&);
    ~Attendant();

    void setPIDNum(string);
    string getPIDNum() const;

    void getBirthDate() const;
    void getHireDate() const;

    void addFlightToAttendant(int);
};
#endif // ATTENDANT_H
