#include <iostream>
#include <fstream>
#include <string>
#include "check.h"
#include "checkbook.h"

using namespace std;

Checkbook::Checkbook(int u, int bal, int cNum) {
    used = u;
    balance = bal;
    checkNum = cNum;
}

void Checkbook::load_from_file(std::ifstream &ifs) {
    /// input the first two lines
    ifs >> balance;
    ifs >> checkNum;

    /// input the checks
    used = 0;
    while (!ifs.eof()) { 
        ifs >> checkList[used];
        used++;
        /// this will ignore any end of line characters, correctly triggering ifs.eof()
        while(ifs.peek() == '\n' || ifs.peek() == '\r') ifs.ignore();
    }
}

void Checkbook::save(std::ofstream &ofs)const {
    /// output the first two lines
    ofs << balance << endl;
    ofs << checkNum << endl;

    /// output all the checks
    for (int i = 0; i < used; i++) {
        ofs << checkList[i];
    }
}

void Checkbook::deposit(double depamount) {
    balance += depamount;
}

void Checkbook::write_check(std::istream &cin) {
    /// input the data for the check, then insert the check num and increment used and checkNum
    checkList[used].write_check(cin);
    checkList[used].set_check_num(checkNum);
    used++;
    checkNum++;
}

double Checkbook::get_balance()const {
    return balance;
}

void Checkbook::show_all(std::ostream &cout)const {
    for (int i = 0; i < used; i++) {
        cout << checkList[i];
    }
}
