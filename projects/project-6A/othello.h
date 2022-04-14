#ifndef OTHELLO_H
#define OTHELLO_H

#include "game.h"
#include "piece.h"
#include <string>

const std::string D_GREEN_B = "\e[48;5;22m";
const std::string D_GRAY = "\e[38;5;234     m";

class Othello : public main_savitch_14::game {
    public:
        /// constructor
        Othello();

        /// required overrides
        /// call original at end of these
        void make_move(const std::string& move);
        void restart();

        /// optional overrides
        main_savitch_14::game::who winning() const;

        /// purely virtual functions from game
        main_savitch_14::game* clone() const;
        void compute_moves(std::queue<std::string>& moves) const;
        void display_status() const;
        int evaluate() const;
        bool is_game_over() const;
        bool is_legal(const std::string& move) const;

    private:
        Piece board[8][8];
};

#endif