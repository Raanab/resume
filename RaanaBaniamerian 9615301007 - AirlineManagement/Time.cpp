#include <iostream>
#include <iomanip>
#include "Time.h"
using namespace std;

Time::Time(int hr, int min){
    setTime(hr, min);
}
void Time::setTime(int h, int m){
    setHour(h);
    setMinute(m);
}
void Time::setHour(int h){
    //hour = (h>=0 && h<24)? h:0;
    if(h>=0 && h<24){
        hour = h;
    }
    else{
        hour = 0;
    }
}
void Time::setMinute(int m){
    //minute = (m>=0 && m<60)? m:0;
    if(m>=0 && m<60){
        minute = m;
    }
    else{
        minute = 0;
    }
}
int Time::getHour() const{
    return hour;
}
int Time::getMinute() const{
    return minute;
}
void Time:: printUniversal() const{
   cout << setfill( '0' ) << setw( 2 ) << getHour() << ":"
      << setw( 2 ) << getMinute()<<endl;
}
void Time::printStandard() const{
   cout << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
      << ":" << setfill( '0' ) << setw( 2 ) << getMinute()
      << ( hour < 12 ? " AM" : " PM" );
}
