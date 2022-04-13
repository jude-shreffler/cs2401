#include "clock.h"
#include "alarm.h"
#include <iostream>

using namespace std;

int main() {
    Clock c, c2;
    c.setTime(9, 53);
    c2.setTime(9, 53);
    cout << (c == c2) << endl << endl;

    c.advance();
    c.advance(5);
    c.output();
    cout << endl;
    

    Alarm a, a2;
    a.setTime(10, 5);
    a.setAlarm(12, 0);
    a.output();
    cout << endl;

    a2.setTime(10, 5);
    a2.setAlarm(12, 0);
    cout << (a == a2) << endl;

    cout << (c == a) << endl; /// works because u can pass an alarm as a clock
    cout << (a == c) << endl; /// doesnt work bc u cant pass a clock as an alarm

    return 0;
}