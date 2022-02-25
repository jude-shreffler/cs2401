#include <iostream>
#include "planner.h"
#include "node.h"
#include "assignment.h"
#include "date_time.h"

using namespace std;

/// Constructor

Planner::Planner() {
    head = NULL;
}

/// The Big 3

Planner::~Planner() {

}

Planner::Planner(Planner& planner2) {

}

Planner Planner::operator + (Planner& planner2) {

}

/// File I/o

void Planner::load(std::istream& ins) {

}

void Planner::save(std::ostream& outs) {

}

/// Helpers

void Planner::add(Assignment& assignmentInfo) {

}

void Planner::display(std::ostream& cout) {

}

Assignment Planner::find(std::string assignmentName) {

    return Assignment();
}

void Planner::remove(std::string assignmentName) {

}

int Planner::waiting() {

    return 1;
}

int Planner::due_next() {

    return 1;
}

int Planner::average_wait() {

    return 1;
}

int Planner::oldest() {

    return 1;
}

int Planner::newest() {

    return 1;
}

void Planner::find_all(DateTime& due_by) {

}

