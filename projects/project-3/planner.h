#ifndef PLANNER_H
#define PLANNER_H

#include "assignment.h"
#include "node.h"
#include "date_time.h"

class Planner {
    public:
        /// The Big 3
        ~Planner();
        Planner(Planner& plannerOld);
        Planner operator + (Planner& plannerOld);

        Planner();
        void add(Assignment& assignmentInfo);
        void display(std::ostream& cout);
        Assignment find(std::string assignmentName);
        void remove(std::string assignmentName);
        int waiting();
        unsigned int due_next();
        int average_wait();
        int oldest();
        int newest();
        void find_all(DateTime& due_by);

        void load(std::istream& ins);
        void save(std::ostream& outs);

    private:
        node* head;
};

#endif