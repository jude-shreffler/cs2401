#include "STACK.h"
#include <iostream>

using namespace std;

int main() {
    STACK<char> s;
    char tmp;

    tmp = cin.get();
    while (tmp != '\n') {
        if (tmp == '(') {
            s.push('(');
        } else {
            cout << "ERROR: too many )" << endl;
        }
    }
    

    return 0;
}