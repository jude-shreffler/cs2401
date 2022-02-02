#ifndef CHECKBOOK
#define CHECKBOOK

#include <iostream>
#include <fstream>
#include <string>
#include "check.h"

const int NUM_CHECKS = 200;

class Checkbook {
    public:
    Checkbook(int u = 0, int bal = 0, int cNum = 1);

    /// file handling
    void load_from_file(std::ifstream &ifs);
    void save(std::ofstream &ofs)const;

    /// other functions
    void deposit(double depamount);
    void write_check(std::istream &cin);
    double get_balance()const;
    void show_all(std::ostream &cout)const;
    void remove(int rmnum);
    void number_sort();
    void payto_sort();
    void date_sort();
    void show(std::string payto_find)const;
    double average()const;
    

    private:
    Check checkList[NUM_CHECKS];
    int used; /// starts at 0, keeps track of how many array indices have been used, 
              /// doubles as the next available index
    int balance; /// starts at 0, just the total balance
    int checkNum; /// starts at 1, increments every time a new check is created

};

#endif