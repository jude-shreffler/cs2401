/**
 * @file part2.cc
 * @author Jude Shreffler (js467820@ohio.edu)
 * @brief simple demonstration of how pointers work
 * @date 2022-02-03
 */
#include <iostream>

using namespace std;

int main() {
    int* ptr;
    ptr = new int;
    cout << ptr << endl;
    cout << &ptr << endl;

    *ptr = 2401;

    for (int i = 0; i < 10; i++) {
        ++(ptr);
        cout << *ptr << " is stored at " << ptr << endl;
    }


    return 0;
}