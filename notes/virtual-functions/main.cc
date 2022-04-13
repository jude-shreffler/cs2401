#include <iostream>

#include "shape.h"

using namespace std;

int main() {
    Rectangle r(3,5);
    cout << r.area() << endl;

    // Shape s; // this CANT be done bc Shape is abstract now

    Shape* s; // this can still be done bc its just an address
    s = new Circle();
    s->area();
    
    return 0;
}