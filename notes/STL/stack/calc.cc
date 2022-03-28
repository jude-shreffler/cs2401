#include <iostream>
#include <cctype>
#include "stack.h"

using namespace std;

bool isop(char d);
int evaluate(int n1, int n2, char op);

int main() {
    STACK<int> nums;
    STACK<char> ops;
    char tmp;
    int n1, n2, n3;

    tmp = cin.get();
    while (tmp != '\n' && tmp != '\r') {
        if(isdigit(tmp)) {
            cin.putback(tmp);
            cin >> n1;
            nums.push(n1);
        } else if (isop(tmp)) {
            ops.push(tmp);
        } else if (tmp == ')') {
            /// do some error checking to make sure your stack isnt empty
            if(!nums.empty()) {
                n2 = nums.top(); /// taking the second "right" number off first
                nums.pop();

                n1 = nums.top();
                nums.pop();

                n3 = evaluate(n1, n2, ops.top());
                ops.pop();

                nums.push(n3);
            }
            
        }
        tmp = cin.get(); 
        cout << "nums: ";
        nums.output(cout);
        cout << endl << "ops: ";
        ops.output(cout);
        cout << endl;

    }

    if(!nums.empty()) {
        cout << "Answer = " << nums.top() << endl;
        nums.pop();
    }

    return 0;
}

bool isop(char d) {
    return (d == '+' || d == '-' || d == '*' || d == '/' || d == '%');
}

int evaluate(int n1, int n2, char op) {
    switch (op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        case '%':
            return n1 % n2;
    }
}