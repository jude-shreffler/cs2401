#include "othello.h"
#include <iostream>
#include "colors.h"
#include <string>
#include <queue>
#include <cctype>

using namespace std;

Othello::Othello() {
    for (int i = 0; i < 7; ++i){
        for (int j = 0; j < 7; j++) {
            board[i][j] = Piece(1);
        }
    }

    board[3][4] = Piece(0);
    board[4][3] = Piece(0);
    board[3][3] = Piece(2);
    board[4][4] = Piece(2);
}

void Othello::make_move(const string& move) {
    int i = int(move[1] - '0' - 1);
    int j = ((isupper(move[0])) ? move[0] - 'A' : move[0] - 'a');
    board[i][j].setOccupied(
        ((last_mover() == main_savitch_14::game::who::HUMAN) ? 2 : 0));

    int checkFor = last_mover();
    int thisMover = next_mover();

    for (int n = 1; i - n >= 0; ++n) { // check up
        int check = board[i-n][j].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            /// do the flipping
            for (int m = 1; m < n; ++m) {
                board[i-m][j].flip();
            }
            break;
        } else {
            break;
        }
    }

    for (int n = 1; i + n < 8; ++n) { // check down
        int check = board[i+n][j].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            /// do the flipping
            for (int m = 1; m < n; ++m) {
                board[i+m][j].flip();
            }
            break;
        } else {
            break;
        }
    }

    for (int n = 1; j - n >= 0; ++n) { // check left
        int check = board[i][j-n].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            /// do the flipping
            for (int m = 1; m < n; ++m) {
                board[i][j-m].flip();
            }
            break;
        } else {
            break;
        }
    }

    for (int n = 1; j + n < 8; ++n) { // check right
        int check = board[i][j+n].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            /// do the flipping
            for (int m = 1; m < n; ++m) {
                board[i][j+m].flip();
            }
            break;
        } else {
            break;
        }
    }

    for (int n = 1; i - n >= 0 && j - n >= 0; ++n) { // check up-left
        int check = board[i-n][j-n].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            /// do the flipping
            for (int m = 1; m < n; ++m) {
                board[i-m][j-m].flip();
            }
            break;
        } else {
            break;
        }
    }

    for (int n = 1; i + n < 8 && j - n >= 0; ++n) { // check down-left
        int check = board[i+n][j-n].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            /// do the flipping
            for (int m = 1; m < n; ++m) {
                board[i-m][j-m].flip();
            }
            break;
        } else {
            break;
        }
    }

    for (int n = 1; i - n >= 0 && j + n < 8; ++n) { // check up-right
        int check = board[i-n][j+n].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            /// do the flipping
            for (int m = 1; m < n; ++m) {
                board[i-m][j+m].flip();
            }
            break;
        } else {
            break;
        }
    }

    for (int n = 1; i + n < 8 && j + n < 8; ++n) { // check down-right
        int check = board[i+n][j+n].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            /// do the flipping
            for (int m = 1; m < n; ++m) {
                board[i+m][j+m].flip();
            }
            break;
        } else {
            break;
        }
    }    
}

void Othello::restart() {
}

main_savitch_14::game::who Othello::winning() const {
    return main_savitch_14::game::who();
}

main_savitch_14::game* Othello::clone() const {
    return new Othello();
}

void Othello::compute_moves(queue<string>& moves) const {
}

void Othello::display_status() const {
    cout << MENU << "Player 1 is X, Player 2 is O" << RESET  << endl;
    cout << "     A   B   C   D   E   F   G   H" << endl;
    for (int i = 0; i < 8; ++i) {
        if (i == 0) {
            cout << "   ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗";
        } else {
            cout << "   ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣";
        }
        cout << endl << " " << (i + 1) << " ║ ";
        for (int j = 0; j < 8; j++) {
            board[i][j].output();
            cout << " ║ ";
        }
        cout << endl;
    }
    cout << "   ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝" << endl;
}

int Othello::evaluate() const {
    return 0;
}

bool Othello::is_game_over() const {
    return false;
}

bool Othello::is_legal(const string& move) const {
    int i = move[1] - '0' - 1;
    int j = ((isupper(move[0])) ? move[0] - 'A' : move[0] - 'a');

    int checkFor = (last_mover() == main_savitch_14::game::who::HUMAN ? 0 : 2);
    int thisMover = (last_mover() == main_savitch_14::game::who::HUMAN ? 2 : 0);

    for (int n = 1; i - n >= 0; ++n) { // check up
        int check = board[i-n][j].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            return true;
        } else {
            break;
        }
    }

    for (int n = 1; i + n < 8; ++n) { // check down
        int check = board[i+n][j].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            return true;
        } else {
            break;
        }
    }

    for (int n = 1; j - n >= 0; ++n) { // check left
        int check = board[i][j-n].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            return true;
        } else {
            break;
        }
    }

    for (int n = 1; j + n < 8; ++n) { // check right
        int check = board[i][j+n].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            return true;
        } else {
            break;
        }
    }

    for (int n = 1; i - n >= 0 && j - n >= 0; ++n) { // check up-left
        int check = board[i-n][j-n].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            return true;
        } else {
            break;
        }
    }

    for (int n = 1; i + n < 8 && j - n >= 0; ++n) { // check down-left
        int check = board[i+n][j-n].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            return true;
        } else {
            break;
        }
    }

    for (int n = 1; i - n >= 0 && j + n < 8; ++n) { // check up-right
        int check = board[i-n][j+n].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            return true;
        } else {
            break;
        }
    }

    for (int n = 1; i + n < 8 && j + n < 8; ++n) { // check down-right
        int check = board[i+n][j+n].getOccupied();

        if (n == 1) {
            if (check != checkFor) {
                break;
            } else {
                continue;
            }
        }

        if (check == checkFor) {
            continue;
        } else if (check == thisMover) {
            return true;
        } else {
            break;
        }
    }

    return false;
}