#ifndef DITERATOR_H
#define DITERATOR_H

#include "dlist.h"
#include "dnode.h"

template<class T>
class dlist;

template <class T>
class diterator{
    public:
        friend class dlist<T>;

        diterator(dNode<T>* initial = NULL){current = initial;}

        T operator * () const{return current->data();}

        diterator<T>& operator ++ (); /// Prefix ++

        diterator<T>& operator ++ (int); /// Postfix ++

        diterator<T>& operator -- (); /// Prefix --

        diterator<T>& operator -- (int); /// Postfix --

        bool operator == (const diterator<T> other) const{return current->data() == other.current->data();}

        bool operator != (const diterator<T> other) const; 
    private:
        dNode<T>* current;
};

#include "diterator.template"

#endif