#ifndef PIECE_H
#define PIECE_H

#include <iostream>

class Piece {
    public:
        /// constructor
        Piece(int o = 1) {occupied = o;}

        /// setter
        void setOccupied(const int o) {(o >= 0 && o <= 2) ? occupied = o : occupied = 1;}

        /// getter
        int getOccupied() const {return occupied;}

        /// helpers
        void flip() {(occupied == 0) ? occupied = 2 : occupied = 0;}
        std::ostream& output(std::ostream& outs) const;

    private:
        int occupied; /// 0, 1, or 2 (0 - Human : 1 - Neutral : 2 - PC)
};

std::ostream& operator << (std::ostream& outs, const Piece& p);

#endif