#include "alarm.h"
#include <iostream>

using namespace std;

bool Alarm::isRinging() {
    /// getHour()            getMinute()               for if u did not use protected
    return hour == alarmHour && minute == alarmMinute;
}

void Alarm::output()const {
    Clock::output();
    cout << alarmHour << ":" << setw(2) << setfill('0') << alarmMinute << endl;
}