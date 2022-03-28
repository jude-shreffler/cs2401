#ifndef NODE_H
#define NODE_H

template<class T>
class node {
    public:
        /// constructor
        node(T& data = T(), node<T>* next = NULL);

        /// setters
        void setData(T d) {dataField = d;}
        void setNext(node<T>* n) {nextField = n;}

        /// getters
        T data() {return dataField;}
        node<T>* next() {return nextField;}

    private:
        T dataField;
        node<T>* nextField;
};

#include "node.template"

#endif