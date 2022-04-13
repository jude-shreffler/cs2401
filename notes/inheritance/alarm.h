#ifndef ALARM_H
#define ALARM_H

#include "clock.h"

class Alarm:public Clock { /// this makes Alarm a child of Clock
                           /// children can be passed anywhere a parent is expected,
                           /// but not the other way around
    public:
        Alarm(int h = 0, int m = 0, int aH = 0, int aM = 0) {hour = h; minute = m; alarmHour = aH; alarmMinute = aM;}

        void setAlarm(int aH, int aM) {alarmHour = aH; alarmMinute = aM;}
        bool isRinging();
        void output()const; /// this is OVERRIDDEN, not overloaded
                            /// it has the same exact footprint as the output function in clock
                            /// when Alarm::output is called in main, it will call the output function closest in scope to us

        bool operator == (Alarm other) {return (hour == other.hour) && (minute == other.minute) 
                                        && (alarmHour == other.alarmHour) 
                                        && (alarmMinute == other.alarmMinute);}

    private:
        int alarmHour;
        int alarmMinute;
};

#endif