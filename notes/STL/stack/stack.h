#ifndef STACK_H
#define STACK_H

#include "node.h"
#include <iostream>

template <class T>
class STACK{
    public:
        /// constructor
        STACK() {topPtr = NULL;}

        /// big 3
        ~STACK();
        STACK(STACK<T>& other);
        void operator = (STACK<T>& other);

        /// add something to top of stack
        void push(T& d);
        void pop();

        /// look at the data on the top of the stack
        T top() const {return topPtr->data();}

        /// check to see if its empty
        bool empty() const {return topPtr == NULL;}

        void output(std::ostream& outs); /// for debugging

    private:
        node<T>* topPtr;
};

template<class T>
std::ostream operator << (std::ostream& outs, STACK<T> s);

#include "stack.template"

#endif