/**
 * @file checkbook.h
 * @author Jude Shreffler (js467820@ohio.edu)
 * @brief header file for a checkbook class. basically a container class for "check" objects
 * @date 2022-02-02
 */
#ifndef CHECKBOOK
#define CHECKBOOK

#include <iostream>
#include <fstream>
#include <string>
#include "check.h"

class Checkbook {
    static const int NUM_CHECKS = 200;

    public:
    /**
     * @brief Construct a new Checkbook object
     * 
     * @param u gets assigned to used
     * @param bal gets assigned to balance
     * @param cNum gets assigned to checkNum
     */
    Checkbook(int u = 0, int bal = 0, int cNum = 1);

    /// file handling
    /**
     * @brief loads your data from a file
     * 
     * @param ifs the file stream to load from
     */
    void load_from_file(std::ifstream &ifs);

    /**
     * @brief saves your data to a file
     * 
     * @param ofs the file stream to save to
     */
    void save(std::ofstream &ofs)const;

    /// other functions
    /**
     * @brief deposits money into balance
     * 
     * @param depamount amount to be added to balance
     */
    void deposit(double depamount);

    /**
     * @brief lets the application user write a check
     * 
     * @param cin standard input stream
     */
    void write_check(std::istream &cin);

    /**
     * @brief Get the balance object
     * 
     * @return double balance
     */
    double get_balance()const;

    /**
     * @brief displays all checks in the checkbook
     * 
     * @param cout standard output stream
     */
    void show_all(std::ostream &cout)const;

    /**
     * @brief removes a cancelled check
     * 
     * @param rmnum the check number of the check that needs removed
     */
    void remove(int rmnum);

    /**
     * @brief sorts checkList by check number, using bubble sort
     * 
     */
    void number_sort();

    /**
     * @brief sorts checkList by payto, using bubble sort
     * 
     */
    void payto_sort();

    /**
     * @brief sorts checkList by date, using bubble sort
     * 
     */
    void date_sort();

    /**
     * @brief shows all checks written to payto_find
     * 
     * @param payto_find the payto to look for
     */
    void show(std::string payto_find)const;

    /**
     * @brief finds the average amount in a check
     * 
     * @return double the average of all amounts in checkList
     */
    double average()const;
    

    private:
    Check checkList[NUM_CHECKS];
    int used; /// starts at 0, keeps track of how many array indices have been used, 
              /// doubles as the next available index
    int balance; /// starts at 0, just the total balance
    int checkNum; /// starts at 1, increments every time a new check is created

};

#endif