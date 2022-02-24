#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* next;
};

class Lilist {
    public:
        Lilist(){head = NULL;}
        void add(std::string item);
        void show();
        Node* search(std::string &target)const;
        void move_front_to_back();

    private:
        Node* head;
};

void Lilist::add(std::string item){
    Node* tmp;
    if (head == NULL) {
        head = new Node;
        head -> data = item;
        head -> next = NULL;
    } else {
        for(tmp = head; tmp -> next != NULL; tmp = tmp -> next); 
        // this loop simply advances the pointer to last node in
        //the list

        tmp -> next = new Node;
        tmp = tmp -> next;
        tmp -> data = item;
        tmp -> next = NULL;
    }
}

void Lilist::show(){
    for(Node *tmp = head; tmp != NULL; tmp = tmp -> next) std::cout << tmp -> data << " ";
}

Node* Lilist::search(std::string &target)const {
    Node* cursor;
    for (cursor = head; cursor != NULL; cursor = cursor -> next) {
        if (cursor -> data == target) {
            return cursor;
        }
    }
    
    return cursor;
}   

void Lilist::move_front_to_back() {
    Node* cursor;
    for (cursor = head; cursor -> next != NULL; cursor = cursor -> next);

    Node* tmp = head;
    head = head -> next;
    cursor -> next = tmp;
    tmp -> next = NULL;
}