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
    node* cursor = head;

    if (head == NULL) {
        head = new node;
        head->set_data(assignmentInfo);
        head->set_link(NULL);
        return;
    }

    while (cursor->link() != NULL && cursor->link()->data().get_due() < assignmentInfo.get_due()) cursor = cursor->link(); /// this sets the cursor to the node before where we want to insert our node

    if (cursor->link() == NULL) {
        cursor->set_link(new node);
        cursor = cursor->link();
        cursor->set_data(assignmentInfo);
        cursor->set_link(NULL);
    } else {
        node* nextElement = cursor->link();
        cursor->set_link(new node);
        cursor = cursor->link();
        cursor->set_data(assignmentInfo);
        cursor->set_link(nextElement);
    }
}

void Planner::display(std::ostream& cout) {
    node* cursor = head;

    while (cursor != NULL) {
        cout << cursor->data();
        cursor = cursor->link();
    }
}

Assignment Planner::find(std::string assignmentName) {
    node* cursor = head;

    ///moves cursor to the node we want
    while(cursor != NULL && cursor->data().get_name() != assignmentName) cursor = cursor->link();
    
    if (cursor == NULL) {
        return Assignment();
    } else {
        return cursor->data();
    }
}

void Planner::remove(std::string assignmentName) {
    node* cursor = head;

    /// moves the cursor to the node before the one that we want to remove
    while(cursor != NULL && cursor->link()->data().get_name() != assignmentName) cursor = cursor->link(); 
    node* deleter = cursor->link();

    cursor->set_link(deleter->link());
    delete deleter;
}

int Planner::waiting() {
    node* cursor = head;
    int counter = 0;

    while (cursor != NULL) {
        cursor = cursor->link();
        counter++;
    }

    return counter;
}

unsigned int Planner::due_next() {
    DateTime temp;
    temp.make_now();

    unsigned int dueTime = head->data().get_due().minutes_since_1970();
    unsigned int nowTime = temp.minutes_since_1970();
    
    if (nowTime < dueTime) {
        return dueTime - nowTime;
    } else {
        return 0;
    }
}

int Planner::average_wait() {
    node* cursor = head;
    int counter = 0;
    int totalWait = 0;
    DateTime temp;
    temp.make_now();

    while (cursor != NULL) {
        counter++;
        totalWait += temp.minutes_since_1970() - cursor->data().get_entered().minutes_since_1970();

        cursor = cursor->link();
    }
    return (totalWait / counter);
}

int Planner::oldest() {
    node* cursor = head;
    DateTime temp;
    temp.make_now();

    

    return 1;
}

int Planner::newest() {

    return 1;
}

void Planner::find_all(DateTime& due_by) {

}

