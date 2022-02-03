/**
 * @file part1.cc
 * @author Jude Shreffler (js467820@ohio.edu)
 * @brief Executes function pretty() 6 times, demonstrates how "static" keyword works
 * @date 2022-02-03
 */
#include <iostream>
using namespace std;

void pretty( ){ 
	static int x = 0;
    x++; 

    for(int i = 0; i < x; ++i){ 
        cout << "*"; 
    } 

    cout << endl;
} 

int main(){
    for(int i = 0; i < 6; i++){
        pretty();
    }
}