#include "piece.h"
#include <iostream>
#include "colors.h"

using namespace std;

void Piece::output() const {
    if (occupied == 0) {
        cout << "-";
    } else if (occupied == 1) {
        cout << RED << "X" << RESET;
    } else if (occupied == 2) {
        cout << BLUE << "O" << RESET;
    }
}