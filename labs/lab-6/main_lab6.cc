/*************************************************************************
     Lab Assignment 6: This is another lab assignment in working with 
     linked lists. We will be using a struct node, for its simplicity,
     and working with non-member functions here. The main point is to 
     work with the logic of a linked list. Do not be afraid to make 
     drawings on scrap paper.
     The prototypes for the functions that you are to implement are
     included. You should uncomment them when you are ready to write 
     the implementation.
           John Dolan				Spring 2014
           Patricia Lindner             Fall 2021
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node{
     int data;
     node* next;
};


// These are the three I have implemented for you
void build_list(node*& head);  // note that we are passing by reference
void show_list(const node* head);
int size(const node* head);
void removeRepeats(node*& head);
void splitList(node*& head, node*& lesser, node*& greater, int splitPoint);

bool search(node*& head, int data);
void push(node*& head, int data);

int main(){
    int start, stop;
    int split;
    node* head = NULL;
    node* lesser;
    node* greater;

    start = time(NULL);
    build_list(head);
    stop = time(NULL);
    cout << "Time to build list = " << stop - start << "seconds.\n";

    start = time(NULL);
    show_list(head);
    stop = time(NULL);
    cout << "Time to print list = " << stop - start << "seconds.\n";
    cout << "Size of the list = " << size(head) << endl;

    start = time(NULL);
    removeRepeats(head);
    stop = time(NULL);
    cout << "Time to remove repeats = " << stop - start << "seconds." << endl;

    start = time(NULL);
    show_list(head);
    stop = time(NULL);
    cout << "Time to print list = " << stop - start << " seconds." << endl;
    cout << "Size of the list = " << size(head) << endl;

    cout << "Enter a split value: ";
    cin >> split;

    start = time(NULL);
    splitList(head, lesser, greater, split);
    stop = time(NULL);
    
    show_list(lesser);
    cout << "Size of the list of numbers from the main list that are less than split = " << size(lesser) << endl;

    show_list(greater);
    cout << "Size of the list of numbers from the main list that are greater than split = " << size(greater) << endl;

    cout << "Time to split the original list into two parts = " << stop - start << " seconds." << endl;
    return 0;
}

// builds a linked list of 2000 random integers, all in the range 1 - 500
void build_list(node*& head){
    node* cursor;

    head = new node;
    head -> data = rand()%500 + 1;

    cursor = head;
    for(int i = 0; i < 2000; ++i){
	    cursor -> next = new node;
        cursor = cursor -> next;
        cursor -> data = rand()%500 + 1;
    }
    cursor -> next = NULL;
}

// outputs the contents of a linked list to the screen
void show_list(const node* head){
    const node* cursor = head;

    while(cursor != NULL){
        cout << cursor -> data << "  ";
        cursor = cursor -> next;
    }
    cout << endl;
}

// returns the number of nodes in a linked list
int size(const node* head){
	const node* cursor = head;
	int count = 0;
	while(cursor != NULL){
  	    count++;
	    cursor = cursor -> next;
	}
	return count;
}

void removeRepeats(node*& head) {
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

void push(node*& head, int data) {
    node* cursor = head;

    while (cursor -> next != NULL) {
        cursor = cursor -> next;
    }

    cursor -> next = new node;
    cursor = cursor -> next;

    cursor -> data = data;
    cursor -> next = NULL;
}