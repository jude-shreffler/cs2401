#include "reverse.h"
#include <iostream>

using namespace std;

int main(){
    string s; 
    int start, end; 
    cout << "Enter a string: "; 
    while (cin.peek() == '\n') {cin.get();}
    getline(cin,s); 
    cout << "Enter two numbers that are within the bounds of the string.\n"; 
    cin >> start >> end; 
    cout << "This is how your string looks now:\n"; 
    reversing(s, start, end); 
    cout << s << endl;

    return 0;
}