#ifndef TLLIST_H
#define TLLIST_H

#include <iostream>
template<class T>
class TLList{
    public:
        TLList();
        ~TLList();
        TLList(const TLList& other);
        void operator = (const TLLList& other);

        void add(const T& item);
        void display(std::ostream& outs)const;

    private:
        node<T>* head;
        node<T>* tail;
};

#include "tllist.template"

#endif