#ifndef DNODE_H
#define DNODE_H

template<class T>
class dNode {
    public:
        /// constructor
        
        /**
         * @brief Construct a new d Node object
         * 
         * @param d gets put in dataField
         * @param p gets put in previousField
         * @param n gets put in nextField
         */
        dNode(T d = T(), dNode* p = NULL, dNode* n = NULL);

        /// setters

        /**
         * @brief Set the Data object
         * 
         * @param d gets put in dataField
         */
        void setData(T d) {dataField = d;}

        /**
         * @brief Set the Next object
         * 
         * @param n gets put in nextField
         */
        void setNext(dNode* n) {nextField = n;}

        /**
         * @brief Set the Previous object
         * 
         * @param p gets put in previousField
         */
        void setPrevious(dNode* p) {previousField = p;}

        /// getters

        /**
         * @brief getter for dataField
         * 
         * @return dataField
         */
        T data() {return dataField;}

        /**
         * @brief getter for nextField
         * 
         * @return nextField
         */
        dNode* next() {return nextField;}

        /**
         * @brief getter for previousField
         * 
         * @return previousField
         */
        dNode* previous() {return previousField;}

    private:
        T dataField;
        dNode* nextField;
        dNode* previousField;

};

#include "dnode.template"

#endif