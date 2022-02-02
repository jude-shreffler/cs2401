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
    balance -= checkList[used - 1].get_amount();
}

double Checkbook::get_balance()const {
    return balance;
}

void Checkbook::show_all(std::ostream &cout)const {
    for (int i = 0; i < used; i++) {
        cout << checkList[i] << endl;
    }
}

void Checkbook::remove(int rmnum) {
    /// loop through checkList checking checknum
    for (int i = 0; i < used; i++) {
        if (checkList[i].get_num() == rmnum) {
            /// add the amount of the check being deleted back to balance
            balance += checkList[i].get_amount();
            checkList[i] = checkList[used - 1];
            i = used;
            used--;
        }
    }
}

void Checkbook::number_sort() {
    /// sort the numbers by check number, using bubble sort
    Check temp;
    bool done = false;

    while(!done) {
        done = true;
        for (int i = 0; i < used - 1; i++) {
            if(checkList[i].get_num() > checkList[i + 1].get_num()) {
                temp = checkList[i];
                checkList[i] = checkList[i + 1];
                checkList[i + 1] = temp;
                done = false;
            }
        }
    }
}

void Checkbook::payto_sort() {
    /// sort the numbers alphabetically by payto, using bubble sort
    Check temp;
    bool done = false;

    while(!done) {
        done = true;
        for (int i = 0; i < used - 1; i++) {
            /// if compare returns positive, str1 is "greater"
            if(checkList[i].get_payto().compare(checkList[i+1].get_payto()) > 0) {
                temp = checkList[i];
                checkList[i] = checkList[i + 1];
                checkList[i + 1] = temp;
                done = false;
            }
        }
    }
}

void Checkbook::date_sort() {
    /// sort the numbers by date, using bubble sort
    Check temp;
    bool done = false;

    while(!done) {
        done = true;
        for (int i = 0; i < used - 1; i++) {
            if(checkList[i].get_date() > checkList[i + 1].get_date()) {
                temp = checkList[i];
                checkList[i] = checkList[i + 1];
                checkList[i + 1] = temp;
                done = false;
            }
        }
    }
}

void Checkbook::show(std::string payto_find)const{
    double total = 0;
    cout << endl;

    for (int i = 0; i < used; i++) {
        if (checkList[i].get_payto() == payto_find) {
            cout << checkList[i] << endl;
            total += checkList[i].get_amount();
        }
    }
    
    cout << "Total: $" << total << endl << endl;
}

double Checkbook::average()const{
    double total = 0;
    for (int i = 0; i < used; i++) {
        total += checkList[i].get_amount();
    }

    return total / used;
}