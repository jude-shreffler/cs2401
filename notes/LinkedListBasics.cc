#include <iostream>

using namespace std;

/// double node
struct Node{
    double data;
    Node* next;
};

int main() {
    Node* head = new Node;
    Node* ptr;
    ptr = head;

    /// put pi in the 0th element and e in the second element
    ptr -> data = 3.14;
    ptr -> next = new Node;
    ptr = ptr -> next;

    ptr -> data = 2.72;
    ptr -> next = NULL;

    Node* cursor = head;
    int i = 0;
    while (cursor != NULL) {
        cout << i << "th element: " << cursor -> data << endl;
        cursor = cursor -> next;
        i++;
    }

    


    return 0;
}