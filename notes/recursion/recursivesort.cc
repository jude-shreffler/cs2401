#include <iostream>
#include "node.h"

using namespace std;

int find_min(int a[], int size);

void selection_sort(int a[], int size);

void print_vertical(int n);

node<int>* search(node<int>* head, int target);

int main() {
    print_vertical(12345);

    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    selection_sort(a, 10);

    cout << endl << "[" << a[0];
    for (int i = 1; i < 10; ++i) {
        cout << ", " << a[i];
    }
    cout << "]" << endl;

    return 0;
}

int find_min(int a[], int size) {
    int min = a[0];
    for(int i = 1; i < size; i++) {
        if(a[i] < min) {
            min = a[i];
        }
    }

    return min;
}

void selection_sort(int a[], int size) {
    if (size <= 1) {
        return;
    } else {
        int smallsp = find_min(a, size); /// finds index of smallest element
        int tmp = a[0];
        a[0] = a[smallsp];
        a[smallsp] = tmp;

        selection_sort(a+1, size - 1); /// pointer math, since a is a pointer we can add one and it 
                                       /// will move the pointer one element further
        /// you might see this called tail recursion, because it calls the recursive function at the
        /// end of it's else
    }
}

void print_vertical(int n) {
    if (n < 10) {
        cout << n << endl;
    } else {
        print_vertical(n / 10);
        cout << n % 10 << endl;
    }
}

node<int>* search(node<int>* head, int target) {
    if(head == NULL) {
        return NULL;
    } else if (head->data() == target){
        return head;
    } else {
        return search(head->next(), target);
        cout << "still working" << endl;
    }
}