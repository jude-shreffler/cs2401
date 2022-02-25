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

int main() {
    node* head = new node;
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

    remove_repeats(head);
    show_list(head);

    return 0;
}