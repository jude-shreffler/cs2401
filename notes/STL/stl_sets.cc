#include <set> /// like a vector, but elements can only be stored once eg (1,3,5) is a set but (1,5,5) isnt
               /// also orders them
#include <string>
#include <iostream>

using namespace std;

int main() {
    multiset<string> names;

    names.insert("Zack");
    names.insert("Bob");
    names.insert("Fred");

    multiset<string>::iterator it;
    it = names.begin();
    while(it != names.end()) {
        cout << *it << endl;
        ++it;
    }
}