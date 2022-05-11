#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include "Date.h"
using namespace std;

ostream& operator <<(ostream& out, const Date &d){
    out<<setfill('0')<<setw(2)<<d.year
    <<"/"<<setw(2)<<d.month<<"/"<<setw(2)<<d.day<<endl;

    return out;
}
bool Date::leapYear() const{
    if( (year%4 == 0 && year%100 != 0 ) || year%400 == 0){
        return true;
    }
    else
        return false;
}
int Date::daysMax(int m) const{
    int maxD;
    switch(m){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        maxD = 31;
        break;
    case 2:
        if(leapYear())
            maxD = 29;
        else
            maxD = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxD = 30;
        break;
    }
    return maxD;
}
Date::Date(){
    time_t NOW = time(0);
    tm *lt = localtime(&NOW);
    setMonth(lt->tm_mon+1);
    setDay(lt->tm_mday);
    setYear(lt->tm_year+1900);
}
Date::Date( int y, int m, int d ){
    //setDate(y, m, d);
    setMonth(m);
    setDay(d);
    setYear(y);
}
void Date::printSlash() const{
    cout<<setfill('0')<<setw(2)<<year<<"/"<<setw(2)<<month<<"/"<<setw(2)<<day<<endl;
}
Date::~Date(){
}

void Date::setYear(int y){
    if(y<=0)
        year = 2000;
    else if(y<1900 && y>0)
        year = 1900 + y;
    else
        year = y;
}
void Date::setMonth(int m){
    month = (m>0 && m<13) ? m : 1;
}
void Date::setDay(int d){
    day = (d<=daysMax(month) && d>0) ? d : 1;
}

void Date::setDate(int y, int m, int d){
    setYear(y);
    setMonth(m);
    setDay(d);
}

void Date::setDateFuture(int y, int m, int d){
    time_t NOW = time(0);
    tm *lt = localtime(&NOW);
    if(y < lt->tm_year+1900){
        year = lt->tm_year+1900;

        if(m < lt->tm_mon+1){
            month = lt->tm_mon+1;
            if(d < lt->tm_mday){
                day = lt->tm_mday;
            }
            else if(d == lt->tm_mday){
                day = d;
            }
            else{ //if d>lt->tm_mday
                day = (d<=daysMax(month) && d>0) ? d : 1;
            }
        }
        else{ //if(m > lt->tm_mon+1){
            month = (m<13? m : 1);
            if(d < lt->tm_mday){
                day = lt->tm_mday;
            }
            else if(d == lt->tm_mday){
                day = d;
            }
            else{ //if d>lt->tm_mday
                day = (d<=daysMax(month) && d>0) ? d : 1;
            }
        }
    }
    else if(y == lt->tm_year+1900){
        year = y;
        if(m < lt->tm_mon+1){
            month = lt->tm_mon+1;
            if(d < lt->tm_mday){
                day = lt->tm_mday;
            }
            else if(d == lt->tm_mday){
                day = d;
            }
            else{ //if d>lt->tm_mday
                day = (d<=daysMax(month) && d>0) ? d : 1;
            }
        }
        else if(m == lt->tm_mon+1){
            month = m;
            if(d <= lt->tm_mday){
                day = lt->tm_mday+1;
            }
            else{ //if d>lt->tm_mday
                day = (d<=daysMax(month) && d>0) ? d : 1;
            }
        }
        else{ //if(m > lt->tm_mon+1){
            month = (m<13? m : 1);
            day = (d<=daysMax(month) && d>0) ? d : 1;
        }
    }
    else{ // if y > lt->tm_year+1900
        year = y;
        month = (m<13? m : 1);
        day = (d<=daysMax(month) && d>0) ? d : 1;
    }
}

bool Date::operator < (const Date &d) const{
    if( year < d.year ){
        return true;
    }
    if( year == d.year ){
        if( month < d.month){
            return true;
        }
        if(month == d.month){
            if(day < d.day){
                return true;
            }
            else{
                return false;
            }
        }
        if(month > d.month){
            return false;
        }
    }
    if( year > d.year ){
        return false;
    }
}

bool Date::operator > (const Date &d) const{
    if( year > d.year ){
        return true;
    }
    if( year == d.year ){
        if( month > d.month){
            return true;
        }
        if(month == d.month){
            if(day > d.day){
                return true;
            }
            else{
                return false;
            }
        }
        if(month < d.month){
            return false;
        }
    }
    if( year < d.year ){
        return false;
    }
}

bool Date::operator ==(const Date &d ) const{
    if (year == d.year
        && month == d.month
        && day == d.day)
            return true;
    else
        return false;
}

Date Date::operator +(int y){
    return Date(year+y, month, day);
}
