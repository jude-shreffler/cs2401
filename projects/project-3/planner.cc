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
    node* cursor = head;
    node* deleter = head;

    while (cursor != NULL) {
        cursor = cursor->link();
        delete deleter;
        deleter = cursor;
    }
}

Planner::Planner(Planner& plannerOld) {
    /// construct
    head = NULL;
    node* cursorNew = head;
    node* cursorOld = plannerOld.head;
    node* deleter = plannerOld.head;

    /// copy & delete
    while (cursorOld != NULL) {
        cursorNew->set_data(cursorOld->data());
        cursorNew = cursorNew->link();
        cursorOld = cursorOld->link();
        delete deleter;
        deleter = cursorOld;
    }
    
    delete plannerOld.head;

}

Planner Planner::operator + (Planner& plannerOld) {
    Planner plannerNew;
    node* cursorNew = plannerNew.head;
    node* cursorOld = plannerOld.head;

    while (cursorOld != NULL) {
        cursorNew->set_data(cursorOld->data());
        cursorNew = cursorNew->link();
        cursorOld = cursorOld->link();
    }

    return plannerNew;
}

/// File I/o

void Planner::load(std::istream& ins) {
    head = new node;
    node* cursor = head;
    Assignment tmp;

    ins >> tmp;
    cursor->set_data(tmp);

    while (ins >> tmp) {
        cursor->set_link(new node);
        cursor = cursor->link();
        cursor->set_data(tmp);
    }

    cursor->set_link(NULL);
}

void Planner::save(std::ostream& outs) {
    node* cursor = head;

    while(cursor != NULL) {
        outs << cursor->data();
        cursor = cursor->link();
    }
}

/// Helpers

void Planner::add(Assignment& assignmentInfo) {
    
}

void Planner::display(std::ostream& cout) {
    node* cursor = head;

    while (cursor != NULL) {
        cout << cursor->data();
        cursor = cursor->link();
    }
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

