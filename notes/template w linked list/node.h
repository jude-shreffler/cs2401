#ifndef NODE_H
#define NODE_H

template <class T>
class node {
    public:
        node(T d = T(), node* n = NULL);

        T data()const {return data_field;}
        node* link()const {return link_field;}

        void set_data(T data) {data_field = data;}
        void set_link(node* n) {link_field = n;}

    private:
        T data_field;
        node* link_field;
};

#include "node.template"

#endif