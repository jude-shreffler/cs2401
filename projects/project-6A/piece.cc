#include "piece.h"
#include <iostream>
#include "colors.h"

using namespace std;

ostream& Piece::output(ostream& outs) const {
    if (occupied == 1) {
        outs << " ";
    } else if (occupied == 0) {
        outs << BLACK << "@" << WHITE;
    } else if (occupied == 2) {
        outs << "@";
    }

    return outs;
}

ostream& operator << (ostream& outs, const Piece& p) {
    p.output(outs);
    return outs;
}