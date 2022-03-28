#ifndef CHORE_H
#define CHORE_H

#include <iostream>
#include <string>

class chore {
    public:
        chore(std::string n = "default", int p = 0);

        std::string getName() const {return name;}
        int getPriority() const {return priority;}

        void setName(std::string n) {name = n;}
        void setPriority(int p) {priority = p;}
        void set(std::string n, int p);

        bool operator < (const chore other) const {return (priority < other.getPriority());}

        void input(std::istream& ins);
        void output(std::ostream& outs);


    private:
        std::string name;
        int priority;
};

std::istream& operator >> (std::istream& ins, chore c);
std::ostream& operator << (std::ostream& outs, chore c);

#endif