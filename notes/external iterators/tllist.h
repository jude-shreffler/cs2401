#ifndef TLLIST_H
#define TLLIST_H

#include <iostream>
#include "node_iterator.h"
#include "node.h"

template<class T>
class TLList{
    public:
        typedef node_iterator<T> iterator;
        TLList();
        ~TLList();
        TLList(const TLList& other);
        void operator = (const TLList& other);

        iterator begin()const {return iterator(head);}
        iterator end()const {return iterator(NULL);}

        void add(const T& item);
        void display(std::ostream& outs)const;

    private:
        node<T>* head;
        node<T>* tail;
};

#include "tllist.template"

#endif