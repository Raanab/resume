#ifndef TIME_H
#define TIME_H

class Time{
public:
    Time(int = 0, int = 0);
    void setTime(int, int);
    void setHour(int);
    void setMinute(int);

    int getHour() const;
    int getMinute() const;

    void printUniversal() const;
    void printStandard() const;
private:
    int hour;
    int minute;
};
#endif

