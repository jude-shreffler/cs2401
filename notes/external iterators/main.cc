#include <iostream>
#include "tllist.h"

using namespace std;

int main() {
    TLList<double> list;
    list.add(3.14);
    list.add(1.59);
    list.add(2.78);

    list.display(cout);

    return 0;
}