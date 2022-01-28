#include <iostream>
#include <fstream>
#include <string>
#include "numlist.h"

using namespace std;

int main() {
    /// var declarations
    NumList nums;
    string fileName = "";
    ifstream ins;
    ofstream outs;
    int int1, int2, int3;


    /// opening the file
    cout << "Enter your file name: ";
    cin >> fileName;

    ins.open(fileName.c_str());
    if (ins.fail()) {
        cout << "Could not open file. Exiting program." << endl;
        return 1;
    }

    /// load file into nums
    nums.load_from_file(ins);

    /// have the user insert 3 numbers of their own
    cout << "Input 3 ints: ";
    cin >> int1 >> int2 >> int3;
    nums.insert(int1);
    nums.insert(int2);
    nums.insert(int3);
    
    /// sort these numbers and save to file
    nums.b_sort();
    
    fileName.insert(fileName.find("."), "sorted");
    outs.open(fileName);
    if (outs.fail()) {
        cout << "Could not open file. Exiting program." << endl;
        return 2;
    }

    nums.save_to_file(outs);
    cout << "Sorted list writtien to " << fileName << endl;
    nums.see_all();

    /// close relevant streams
    ins.close();
    outs.close();

    return 0;
}