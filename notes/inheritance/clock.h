#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <iomanip>

class Clock{
    public:
        /// constructor
        Clock(int h = 0, int m = 0) {hour = h; minute = m;}

        /// getters
        int getHour()const {return hour;}
        int getMinute()const {return minute;}

        /// helpers

        void output()const {std::cout << hour << ":" << std::setw(2) << std::setfill('0') << minute << std::endl;}
        
        void setTime(int h, int m) {hour = h; minute = m;}
        void advance(int amt = 1) {minute += amt;}
        void simplify();

        /// operators
        bool operator == (Clock other) {return (hour == other.hour) && (minute == other.minute);}

    protected: /// inaccessible to main, but accessible to classes that inherit clock
        int hour;
        int minute;
};

#endif