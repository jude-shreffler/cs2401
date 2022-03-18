#ifndef DNODE_H
#define DNODE_H

template<class T>
class dNode {
    public:
        /// constructor
        dNode(T d = T(), dNode* n = NULL, dNode* p = NULL);

        /// setters
        void setData(T d) {dataField = d;}
        void setNext(dNode* n) {nextField = n;}
        void setPrevious(dNode* p) {previousField = p;}

        /// getters
        T data() {return dataField;}
        dNode* next() {return nextField;}
        dNode* previous() {return previousField;}

    private:
        T dataField;
        dNode* nextField;
        dNode* previousField;

};

#include "dnode.template"

#endif