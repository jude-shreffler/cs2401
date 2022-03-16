#ifndef NODE_ITERATOR_H
#define NODE_ITERATOR_H

#include "node.h"

template<class T> class TLList;

template<class T>
class node_iterator{
    public:
        friend class TLList<T>;

        node_iterator(node<T>* c = NULL){current = c;}

        bool operator != (node_iterator<T> other)const;
        T operator * ()const;
        node_iterator<T> operator ++ (); // prefix operator
        node_iterator operator ++ (int); // postfix THIS IS HOW YOU DO THIS ALWAYS!!! THIS IS JUST HOW IT IS

    private:
        node<T>* current;
};

#include "node_iterator.template"

#endif