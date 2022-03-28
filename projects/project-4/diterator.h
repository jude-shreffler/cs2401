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

        /**
         * @brief Construct a new diterator object
         * 
         * @param initial the initial location of the iterator
         */
        diterator(dNode<T>* initial = NULL){current = initial;}

        /**
         * @brief dereferencing operator to access the data in an iterator
         * 
         * @return current->dataField
         */
        T operator * () const{return current->data();}

        /**
         * @brief preincrement for the iterator, moves it to the next element in the list
         * 
         * @return the new location of the iterator
         */
        diterator<T>& operator ++ (); /// Prefix ++

        /**
         * @brief postincrement for the iterator, moves it to the next element in the list
         * 
         * @return the location of the iterator before moving it
         */
        diterator<T>& operator ++ (int); /// Postfix ++
        
        /**
         * @brief predecrement for the iterator, moves it to the previous element in the list
         * 
         * @return the new location of the iterator
         */
        diterator<T>& operator -- (); /// Prefix --

        /**
         * @brief postdecrement for the iterator, moves it to the previous element in the list
         * 
         * @return the location of the iterator before moving it
         */
        diterator<T>& operator -- (int); /// Postfix --

        /**
         * @brief == operator for the iterator
         * 
         * @param other the rvalue of the expression
         * @return true if current == other.current
         * @return false otherwise
         */
        bool operator == (const diterator<T> other) const{return current == other.current;}
        
        /**
         * @brief != operator for the iterator
         * 
         * @param other the rvalue of the expression
         * @return true if current != other.current
         * @return false otherwise
         */
        bool operator != (const diterator<T> other) const{return current != other.current;}
        
    private:
        dNode<T>* current;
};

#include "diterator.template"

#endif