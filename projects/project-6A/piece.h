#ifndef PIECE_H
#define PIECE_H

class Piece {
    public:
        /// constructor
        Piece(int o = 0) {occupied = o;}

        /// setter
        void setOccupied(const int o) {(o >= 0 && o <= 2) ? occupied = o : occupied = 0;}

        /// getter
        int getOccupied() const {return occupied;}

        /// helpers
        void flip() {(occupied == 1) ? occupied = 2 : occupied = 1;}
        void output() const;

    private:
        int occupied; /// 0, 1, or 2
};

#endif