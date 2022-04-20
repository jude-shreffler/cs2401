#include <string>

using namespace std;

bool is_game_over() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            char let = 'a' + j;
            char num = i + '1';
            string move = string(1, let) + string(1, num);
            if (is_legal(move)) {
                return true;
            }
        }
    }
    return false;
}

bool is_legal(const string& move) const {
    int i = move[1] - '1';
    int j = ((isupper(move[0])) ? move[0] - 'A' : move[0] - 'a');

    if (board[i][j].getOccupied() != 1) {
        return false;
    }

    int checkFor = last_mover();
    int thisMover = next_mover();

    //int checkFor = (last_mover() == game::who::HUMAN ? 0 : 2);  // use these if the above dont work
    //int thisMover = (last_mover() == game::who::HUMAN ? 2 : 0); //

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

int main() {

    return 0;
}