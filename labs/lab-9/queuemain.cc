#include "chore.h"
#include <queue>
#include <iostream>

using namespace std;

int main() {
    priority_queue<chore> list;
    chore temp;
    
    for (int i = 0; i < 5; i++) {
        temp.input(cin);
        list.push(temp);
    }

    cout << endl;

    while (!list.empty()) {
        cout << list.top();
        list.pop();
    }

    return 0;
}