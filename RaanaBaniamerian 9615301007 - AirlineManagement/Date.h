
#ifndef DATE_H
#define DATE_H
// p 269
#include <ctime>
#include <iostream>

class Date{
    friend std::ostream& operator <<(std::ostream& out, const Date &d);
protected:
    int year, month, day;

    bool leapYear() const;
    int daysMax(int) const;

public:
    // constructors
    Date();
    Date(int, int, int);
    ~Date();

    //print
    void printSlash() const;

    //setters
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    void setDate(int, int, int);
    void setDateFuture(int, int, int);

    bool operator <( const Date &d ) const;
    bool operator >( const Date &d ) const;
    bool operator ==(const Date &d ) const;
    Date operator +(int);

};

#endif // DATE_H


