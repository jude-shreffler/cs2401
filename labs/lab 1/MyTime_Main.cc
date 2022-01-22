#include "MyTime.h"
#include <iostream>

using namespace std;

int main() {
    MyTime a = MyTime(4, 30);
    MyTime b = MyTime(4, 15);
    MyTime c = a * 2;

    cout << c;

    return 0;
}