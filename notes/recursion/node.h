#ifndef NODE_H
#define NODE_H

template <class T>
class node {
    public:
        node(T d = T(), node* n = NULL);

        T data()const {return data_field;}
        node* next()const {return next_field;}

        void set_data(T data) {data_field = data;}
        void set_next(node* n) {next_field = n;}

    private:
        T data_field;
        node* next_field;
};

#include "node.template"

#endif