#ifndef TLLIST_H
#define TLLIST_H

#include "dnode.h"
#include "diterator.h"

template<class T>
class dlist {
    public:
        typedef diterator<T> iterator;
        /// constructor
        dlist();

        /// big 3
        ~dlist();
        dlist(dlist<T>& d);
        dlist<T> operator = (dlist<T>& d);

        /// inserts
        void front_insert(const T d);
        void rear_insert(const T d);

        void insert_before(const dlist<T>::iterator it, const T d);
        void insert_after(const dlist<T>::iterator it, const T d);

        /// removes
        void front_remove();
        void rear_remove();

        void remove(const dlist<T>::iterator it);

        /// ends
        dlist<T>::iterator begin() {return dlist<T>::iterator(head);}
        dlist<T>::iterator end() {return dlist<T>::iterator();}
        dlist<T>::iterator r_begin() {return dlist<T>::iterator(tail);}
        dlist<T>::iterator r_end() {return dlist<T>::iterator();}


        /// shows
        void reverse_show();
        void show();

        /// helpers
        int size();

    private:
        dNode<T>* head;
        dNode<T>* tail;
};

#include "dlist.template"

#endif