/// queue is first in, first out, like waiting in line
#include <queue>
#include <iostream>

using namespace std;

int main() {
    queue<double> q;

    q.push(3.14);
    q.push(1.25);
    q.push(99.99);

    while(q.empty() == false) {
        cout << q.front() << endl;
        q.pop();
    }
}