#ifndef TLLIST_H
#define TLLIST_H

#include "dnode.h"

template<class T>
class dlist {
    public:
        /// constructors
        dlist();

        void rear_insert(const T d);
        void show();

    private:
        dNode<T>* head;
        dNode<T>* tail;
};

#include "dlist.template"

#endif