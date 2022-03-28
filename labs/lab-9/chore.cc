#include "chore.h"
#include <iostream>
#include <string>

using namespace std;

chore::chore(string n, int p) {
    name = n;
    priority = p;
}

void chore::set(string n, int p) {
    name = n;
    priority = p;
}

void chore::input(istream& ins) {
    cout << "Enter the name of the chore: ";
    while (iswspace(cin.peek())) {cin.ignore();}
    getline(ins, name);
    cout << "Enter the priority: ";
    ins >> priority;
}

void chore::output(ostream& outs) {
    cout << "Name: " << name << endl;
    cout << "Priority: " << priority << endl;
}

istream& operator >> (istream& ins, chore c) {
    c.input(ins);
    return ins;
}

ostream& operator << (ostream& outs, chore c) {
    c.output(outs);
    return outs;
}