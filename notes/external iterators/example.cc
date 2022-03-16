#include <iostream>
#include <list>

using namespace std;

int main() {
    list<string> names; // makes a linked list of strings
    list<string>::iterator it; // makes an external iterator for this list

    it = names.begin(); 
    while (it != names.end()) {
        cout << *it << endl;
        ++it;
    }

    return 0;
}


