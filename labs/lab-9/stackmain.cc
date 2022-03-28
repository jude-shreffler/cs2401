/*************************************************************************
	Lab Assignment 9 - working with a stack
	It's sometimes tricky to set up the loop that reads the expression 
	from the keyboard, so I am giving that to you. You have to fill in 
	the rest of the main.

	John Dolan	Fall 2016	Ohio University		Home of the Bobcats
*************************************************************************/
#include <stack>
#include <iostream>
#include <cstdlib>

#include "calc_useful.h"
using namespace std;

int main(){
	char c;
	char tmp;
	int onenum, twonum;
	bool continu = true;
	bool brokeEarlier = false;
	// declare an STL stack called nums right here:
	stack<int> nums;

	cout << "Please enter your expression:\n";

	c = cin.get(); // priming read for the sentinel loop.
	while(continu == true){
		while(c != '\n'){
			if(isdigit(c)){
				cin.putback(c);
				cin >> onenum;
				// stack operation here.
				nums.push(onenum);

			}
			else if(isop(c)){
				if(nums.size() > 1){
					
					// pop two numbers from the stack
					int b = nums.top();
					nums.pop();
					//cout << "b = " << b << endl;
					int a = nums.top();
					nums.pop();
					//cout << "a = " << a << endl;

					// evaluate them using the evaluate from stack_useful
					int result = evaluate(a, b, c);

					// push result onto the stack
					nums.push(result);

				}
				else{
					cout << "Error:";
					cout << " You entered too many operators" << endl; // what did this error tell us about the user's expression?
					
					brokeEarlier = true;
					break;
				}
			}

			c = cin.get(); // reading at the bottom of the sentinel loop
		} // bottom of the loop that reads a single expression from the keyboard

		// output the final result from the top of the stack
		// but only after you check to make sure there's something on the stack
		if (brokeEarlier) {
			brokeEarlier = false;
			/// clear the stack
			while (!nums.empty()) {
				nums.pop();
			}
		} else if (nums.size() == 1) {
			cout << "Result: " << nums.top() << endl;
			nums.pop();
		} else {
			cout << "Error: You entered too many numbers" << endl;
			/// clear the stack
			while (!nums.empty()) {
				nums.pop();
			}
		}


		cout << "Enter another equation?(y or n) ";
		cin >> tmp;
		
		cin.ignore();
		
		if(tmp == 'y' || tmp == 'Y') {
			continu = true;
			c = cin.get();
		} else {
			continu = false;
		}	

	}
	return 0;
}