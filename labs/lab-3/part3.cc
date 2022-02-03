/**
 * @file part3.cc
 * @author Jude Shreffler (js467820@ohio.edu)
 * @brief simple demonstration of how dynamic memory works
 * @date 2022-02-03
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int* ptr;
    int* tmpptr;
    size_t capacity = 5;
    size_t used = 0;

    ptr = new int[capacity];
    for (size_t i = 0; i < 25; i++) {
        ptr[used] = rand();
        /// cout << ptr[used] << endl;
        used++;
        if (used == capacity) {
            tmpptr = new int[capacity + 5];
            for (size_t j = 0; j < capacity; j++) {
                tmpptr[j] = ptr[j];
            }
            capacity += 5;
            delete ptr;
            ptr = tmpptr;
            cout << "Resized." << endl;
        }

    }

    tmpptr[2] = 0;
    for (size_t i = 0; i < used; i++) {
        cout << ptr[i] << endl;
    }

    return 0;
}