#ifndef TLLIST_H
#define TLLIST_H

#include "dnode.h"

template<class T>
class dlist {
    public:
        /// constructors
        dlist();

        void front_insert(const T d);
        void rear_insert(const T d);

        void front_remove();
        void rear_remove();

        void reverse_show();
        void show();

    private:
        dNode<T>* head;
        dNode<T>* tail;
};

#include "dlist.template"

#endif