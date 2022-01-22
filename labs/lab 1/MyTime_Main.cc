#include "MyTime.h"
#include <iostream>

using namespace std;

int main() {
    /// vars
    MyTime time1;
    MyTime time2;
    int scalar;
    
    /// getting the users times and scalar
    cout << "Enter your first time: ";
    cin >> time1;
    cout << "Enter your second time: ";
    cin >> time2;
    cout << "Enter a scalar: ";
    cin >> scalar;

    /// outputing the results

    cout << time1 << " + " << time2 << " = " << (time1 + time2) << endl;
    cout << time1 << " - " << time2 << " = " << (time1 - time2) << endl;
    cout << time1 << " * " << scalar << " = " << (time1 * scalar) << endl;
    cout << time1 << " / " << scalar << " = " << (time1 / scalar) << endl;

    cout << time1 << " == " << time2 << " = " << (time1 == time2) << endl;
    

    return 0;
}