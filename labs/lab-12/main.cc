#include "functions.h"
#include <iostream>

using namespace std;

int main(){ 
    int num; 
    cout << "Please input an int decimal number: "; 
  
    cin >> num; 
    cout << "\nThis number in base 2 is: "; 
    convert_to_base(num, 2); // shows the number to base 2 
    cout << "\nThis number in base 3 is: "; 
    convert_to_base(num, 3); // shows the number to base 3 
    cout << "\nThis number in base 7 is: "; 
    convert_to_base(num, 7); 
    cout << "\n\n";

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
