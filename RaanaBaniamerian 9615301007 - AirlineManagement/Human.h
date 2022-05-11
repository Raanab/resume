#include <iostream>
using namespace std;

#ifndef HUMAN_H
#define HUMAN_H

class Human{
    friend ostream& operator <<(ostream&, const Human&);

protected:
    string FirstName, LastName, IDNum;

public:
    Human();
    Human(string, string, string );
    ~Human();

    bool checkChar(string);

    void setFirstName(string);
    string getFirstName() const;

    void setLastName(string);
    string getLastName() const;

    void setIDNum(string);
    string getIDNum() const;
};

#endif
