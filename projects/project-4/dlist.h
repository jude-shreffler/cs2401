#ifndef TLLIST_H
#define TLLIST_H

#include "dnode.h"
#include "diterator.h"

template<class T>
class dlist {
    public:
        typedef diterator<T> iterator;
        /// constructor

        /**
         * @brief Construct a new dlist object
         * 
         */
        dlist();

        /// big 3

        /**
         * @brief Destroy the dlist object
         * 
         */
        ~dlist();

        /**
         * @brief Copy construct a new dlist object
         * 
         * @param d the object to copy from
         */
        dlist(dlist<T>& d);

        /**
         * @brief assignment operator for dlist
         * 
         * @param d the object to copy from
         * @return the copied list
         */
        dlist<T> operator = (dlist<T>& d);

        /// inserts

        /**
         * @brief inserts an object at the front of the list
         * 
         * @param d the object to be inserted
         */
        void front_insert(const T d);

        /**
         * @brief inserts an object at the rear of the list
         * 
         * @param d the object to be inserted
         */
        void rear_insert(const T d);


        /**
         * @brief inserts an object before the node marked by an iterator
         * 
         * @param it the iterator marking a node
         * @param d the object to be inserted
         */
        void insert_before(const dlist<T>::iterator it, const T d);

        /**
         * @brief inserts an object after the node marked by an iterator
         * 
         * @param it the iterator marking a node
         * @param d the object to be inserted
         */
        void insert_after(const dlist<T>::iterator it, const T d);

        /// removes

        /**
         * @brief removes the first node in the list
         * 
         */
        void front_remove();

        /**
         * @brief removes the last node in the list
         * 
         */
        void rear_remove();


        /**
         * @brief removes a node marked by an iterator
         * 
         * @param it the iterator marking the node to be removed
         */
        void remove(const dlist<T>::iterator it);

        /// ends

        /**
         * @brief begin function for the iterator
         * 
         * @return returns an iterator pointing at the head of the list
         */
        dlist<T>::iterator begin() {return dlist<T>::iterator(head);}

        /**
         * @brief end function for the iterator
         * 
         * @return returns an iterator pointing at NULL
         */
        dlist<T>::iterator end() {return dlist<T>::iterator();}

        /**
         * @brief reverse begin function for the iterator
         * 
         * @return returns an iterator pointing at the tail of the list
         */
        dlist<T>::iterator r_begin() {return dlist<T>::iterator(tail);}

        /**
         * @brief reverse end function for the iterator
         * 
         * @return returns an iterator pointing at NULL
         */
        dlist<T>::iterator r_end() {return dlist<T>::iterator();}


        /// shows

        /**
         * @brief shows the list in reverse
         * 
         */
        void reverse_show();

        /**
         * @brief shows the list forwards
         * 
         */
        void show();

        /// helpers
        
        /**
         * @brief function used to get the size of the list
         * 
         * @return the size of the list
         */
        int size();

    private:
        dNode<T>* head;
        dNode<T>* tail;
};

#include "dlist.template"

#endif