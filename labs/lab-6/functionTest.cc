#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node{
     int data;
     node* next;
};

bool search(node*& head, int data) {
    node* cursor = head;
     
    while (cursor != NULL) {
        if (data == cursor -> data) {
            return true;
        }

        cursor = cursor -> next;
    }

    return false;
}

void remove_repeats(node*& head) {
    node* cursor = head;
    node* checkCursor = head;
	node* deleter = head;

    while (cursor != NULL) {
		while (checkCursor != cursor) {
			if (checkCursor -> data == cursor -> data) {
				/// delete cursor and move to next element
				deleter = head;
				while (deleter -> next != cursor) {
					deleter = deleter -> next;
				}

				deleter -> next = cursor -> next;
				break;
			}
			checkCursor = checkCursor -> next;	
		}
		cursor = cursor -> next;
		checkCursor = head;
    }
}

void show_list(const node* head){
     const node* cursor = head;

     while(cursor != NULL){
          cout << cursor -> data << "  ";
          cursor = cursor -> next;
     }
     cout << endl;
}

void build_list(node*& head){
     node* cursor;

     head = new node;
     head -> data = rand()%10 + 1;

     cursor = head;
     for(int i = 0; i < 40; ++i){
	     cursor -> next = new node;
          cursor = cursor -> next;
          cursor -> data = rand()%10 + 1;
     }
     cursor -> next = NULL;
}

void splitList(node*& head, node*& lesser, node*& greater, int splitPoint) {
    node* cursor = head;
    node* lesserCursor;
    node* greaterCursor;
	bool lesserStarted = false;
	bool greaterStarted = false;

    while (cursor != NULL) {
        if (cursor -> data < splitPoint) {
			if (lesserStarted == false) {
				lesser = new node;
				lesserCursor = lesser;
				lesserStarted = true;
			} else {
				lesserCursor -> next = new node;
				lesserCursor = lesserCursor -> next;
			}
            
			lesserCursor -> data = cursor -> data;

        } else if (cursor -> data > splitPoint) {
			if (greaterStarted == false) {
				greater = new node;
				greaterCursor = greater;
				greaterStarted = true;
			} else {
				greaterCursor -> next = new node;
				greaterCursor = greaterCursor -> next;
			}

            greaterCursor -> data = cursor -> data;
    
        }

        cursor = cursor -> next;
    }
    
    greaterCursor -> next = NULL;
    lesserCursor -> next = NULL;
}

int main() {
    node* head = new node;
	node* lesser;
	node* greater;
	///node* cursor = head;

	build_list(head);
	// head -> data = 25;
	// head -> next = new node;
	// cursor = head -> next;
	
	// cursor -> data = 26;
	// cursor -> next = new node;
	// cursor = cursor -> next;

	// cursor -> data = 25;
	// cursor -> next = NULL;

	show_list(head);
	cout << endl;

    remove_repeats(head);
    show_list(head);

	splitList(head, lesser, greater, 5);

	show_list(lesser);
	show_list(greater);

    return 0;
}