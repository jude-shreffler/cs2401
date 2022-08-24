#include "othello.h"
#include <iostream>
#include "colors.h"
#include <string>
#include <queue>
#include <cctype>

#include<unistd.h> // for debug purposes

using namespace std;
using namespace main_savitch_14;

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

    cout << D_GREEN_B;

    for (int i = 0; i < 100; ++i) {
        cout << " ";
    }
    for (int i = 0; i < 100; ++i) {
        cout << "\n";
    }

    cout << "        ....              s                                 ..       ..             \n" <<
            "    .x~X88888Hx.         :8      .uef^\"               x .d88\"  x .d88\"              \n" <<
            "   H8X 888888888h.      .88    :d88E                   5888R    5888R          u.   \n" <<
            "  8888:`*888888888:    :888ooo `888E            .u     \'888R    \'888R    ...ue888b  \n" <<
            "  88888:        `%8  -*8888888  888E .z8k    ud8888.    888R     888R    888R Y888r \n" <<
            ". `88888          ?>   8888     888E~?888L :888\'8888.   888R     888R    888R I888> \n" <<
            "`. ?888%           X   8888     888E  888E d888 \'88%\"   888R     888R    888R I888> \n" <<
            "  ~*??.            >   8888     888E  888E 8888.+\"      888R     888R    888R I888> \n" <<
            " .x88888h.        <   .8888Lu=  888E  888E 8888L        888R     888R   u8888cJ888  \n" <<
            ":\"\"\"8888888x..  .x    ^%888*    888E  888E \'8888c. .+  .888B .  .888B .  \"*888*P\"   \n" <<
            "`    `*888888888\"       \'Y\"    m888N= 888>  \"88888%    ^*888%   ^*888%     \'Y\"      \n" <<
            "        \"\"***\"\"                 `Y\"   888     \"YP\'       \"%       \"%                \n" <<
            "                                     J88\"                                           \n" <<
            "                                     @%                                             \n" <<
            "                                   :\"                                               \n";
    cout << "\n";
    cout << "                   .-. .-. .-. .-. .-.   .-. . . .-. .-. .-. \n" <<
            "                   |-' |(  |-  `-. `-.   |-  |\\|  |  |-  |(  \n" << 
            "                   '   ' ' `-' `-' `-'   `-' ' `  '  `-' ' ' \n";
    
    string temp;
    getline(cin, temp);  

    //DEBUG:
    //unsigned int microsecond = 1000000;
    //usleep(microsecond / 3); //sleeps for 3 second       
}

void Othello::make_move(const string& move) {
    if (toupper(move[0]) == 'X' && toupper(move[1] == 'X')) {
        return;
    }

    int i = int(move[1] - '0' - 1);
    int j = ((isupper(move[0])) ? move[0] - 'A' : move[0] - 'a');
    board[i][j].setOccupied(
        ((last_mover() == game::who::HUMAN) ? 2 : 0));

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
                board[i+m][j-m].flip();
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

    game::make_move(move);
}

void Othello::restart() {
}

game::who Othello::winning() const {
    // count human and pc pieces, then return which is winning
    int comCount = 0;
    int humCount = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j <8; ++j) {
            if (board[i][j].getOccupied() == 0) {
                ++humCount;
            } else if (board[i][j].getOccupied() == 2) {
                ++comCount;
            }
        }
    }

    game::who win;

    if (humCount > comCount) {
        win = game::who::HUMAN;
    } else if (humCount == comCount) {
        win = game::who::NEUTRAL;
    } else {
        win = game::who::COMPUTER;
    }

    return win;
}

string Othello::get_user_move() const{
	string answer;

	display_message("Make your move (enter \"xx\" to skip): ");
	getline(cin, answer);
	return answer;
}

game* Othello::clone() const {
    return new Othello(*this);
}

void Othello::compute_moves(queue<string>& moves) const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            char let = 'a' + j;
            char num = i + '1';
            string move = string(1, let) + string(1, num);
            if (is_legal(move)) {
                moves.push(move);
            }
        }
    }
}

void Othello::display_status() const {

    string fill = "                     "; 
    cout << fill << "     Player 1 is " << Piece(0) << " , Player 2 is " << Piece(2) << endl; 
    cout << fill << "     A   B   C   D   E   F   G   H" << endl;
    for (int i = 0; i < 8; ++i) {
        if (i == 0) {
            cout << fill << D_GRAY << "   ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗" << WHITE;
        } else { 
            cout << fill << D_GRAY << "   ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣" << WHITE;
        }
        cout << endl << fill << " " << (i + 1) << D_GRAY << " ║ " << WHITE;
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << D_GRAY << " ║ " << WHITE;
        }
        cout << endl;
    }
    cout << fill << D_GRAY << "   ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝" << WHITE << endl;
}

int Othello::evaluate() const {
    // count human and pc pieces, then return pc - human
    int comCount = 0;
    int humCount = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j <8; ++j) {
            if (board[i][j].getOccupied() == 0) {
                ++humCount;
            } else if (board[i][j].getOccupied() == 2) {
                ++comCount;
            }
        }
    }

    return comCount - humCount;
}

bool Othello::is_game_over() const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            char let = 'a' + j;
            char num = i + '1';
            string move = string(1, let) + string(1, num) + string(1, 'a');
            if (is_legal(move)) {
                return false;
            }
        }
    }

    return true;
}

bool Othello::is_legal(const string& move) const {
    if (move.length() == 3) { // move length being 3 denotes that Othello::is_game_over is calling the
                              // function, and therefore needs the move checked for player 1 and player 2.
                              // so, we first check the move from the point of view of the player who went
                              // last, then the player who goes next
        int i = move[1] - '1';
        int j = ((isupper(move[0])) ? move[0] - 'A' : move[0] - 'a');

        if (board[i][j].getOccupied() != 1) {
            return false;
        }

        int checkFor = next_mover();
        int thisMover = last_mover();

        for (int n = 1; i - n >= 0; ++n) { // check up
            int check = board[i - n][j].getOccupied();

            if (n == 1) {
                if (check != checkFor) {
                    break;
                } else {
                    continue;
                }
            }

            if (check == checkFor)  {
                continue;
            } else if (check == thisMover) {
                return true;
            } else {
                break;
            }
        }

        for (int n = 1; i + n < 8; ++n) { // check down
            int check = board[i + n][j].getOccupied();

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
            int check = board[i][j - n].getOccupied();

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
            int check = board[i][j + n].getOccupied();

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
            int check = board[i - n][j - n].getOccupied();

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
            int check = board[i + n][j - n].getOccupied();

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
            int check = board[i - n][j + n].getOccupied();

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
            int check = board[i + n][j + n].getOccupied();

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
    }

    if (toupper(move[0]) == 'X' && toupper(move[1] == 'X')) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                char let = 'a' + j;
                char num = i + '1';
                string move = string(1, let) + string(1, num);
                if (is_legal(move)) {
                    return false;
                }
            }
        }

        return true;
    }

    int i = move[1] - '1';
    int j = ((isupper(move[0])) ? move[0] - 'A' : move[0] - 'a');

    if (board[i][j].getOccupied() != 1) {
        return false;
    }

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