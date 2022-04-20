#include <stdio.h>
#include <time.h>
#include <iostream>

using namespace std;

const int ITERATIONS = 750;

int main() {
    srand(time(NULL));
    for (int i = 0; i < ITERATIONS; ++i) {
        char column = char(rand() % 8 + 'a');
        char row = char(rand() % 8 + '1');
        cout << column << row << "\n";
    }


    flush(cout);

    return 0;
}