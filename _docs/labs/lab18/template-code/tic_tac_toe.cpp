#include "tic_tac_toe.h"

#define BOARD_SIZE 9
#define ONGOING -1
#define OVER_TIE 0
#define OVER_WIN 1
#define P1_SYMBOL 'X'
#define P2_SYMBOL 'O'
#define PLAYER_1 0
#define PLAYER_2 1
#define MAX_VAL 1
#define TIE_VAL 0
#define MIN_VAL -1
#define MAX_DEPTH 5

tic_tac_toe::tic_tac_toe() {
    //TODO
        // initialize all member variables: m_current_player, m_board, m_ai_mode
        // game starts with player one
        // default constructor sets m_ai_mode to false
        // dynamically allocate the board and populate it with numbers 1-9 so player knows how to pick spot 
}

tic_tac_toe::tic_tac_toe(bool ai_mode) {
    //TODO
        // same thing as default constructor, except m_ai_mode is set to ai_mode
}

tic_tac_toe::~tic_tac_toe() {
    //TODO
        // delete the board (hint: recall lab 5)
}

int tic_tac_toe::game_status(char* board) {
    //TODO
    //HINT: USE THE MACROS GIVEN:
        //OVER_WIN if either player won
        //OVER_TIE if board is full and no player won
        //ONGOING if board still has open spots
}

std::string tic_tac_toe::draw_board(char* board) {
    std::string partial_divider = "     |     |     \n";
    std::string full_divider = "_____|_____|_____\n" + partial_divider;
    std::string bar_divider = "  |  ";
    std::string front_space = "  ";
    
    std::string str("\n");
    str += partial_divider;
    str += front_space + board[0] + bar_divider + board[1] + bar_divider + board[2] + "\n";
    str += full_divider;
    str += front_space + board[3] + bar_divider + board[4] + bar_divider + board[5] + "\n";
    str += full_divider;
    str += front_space + board[6] + bar_divider + board[7] + bar_divider + board[8] + "\n";
    str += partial_divider + "\n";

    return str;
}

bool tic_tac_toe::make_move(int location) {
    char symbol;

    if (m_current_player == PLAYER_1) { 
        symbol = P1_SYMBOL;
    } else {
        symbol = P2_SYMBOL;
    }

    if (location == 0 && m_board[0] == '1') {
        m_board[0] = symbol;
    } else if (location == 1 && m_board[1] == '2') {
        m_board[1] = symbol;
    } else if (location == 2 && m_board[2] == '3') {
        m_board[2] = symbol;
    } else if (location == 3 && m_board[3] == '4') {
        m_board[3] = symbol;
    } else if (location == 4 && m_board[4] == '5') {
        m_board[4] = symbol;
    } else if (location == 5 && m_board[5] == '6') {
        m_board[5] = symbol;
    } else if (location == 6 && m_board[6] == '7') {
        m_board[6] = symbol;
    } else if (location == 7 && m_board[7] == '8') {
        m_board[7] = symbol;
    } else if (location == 8 && m_board[8] == '9') {
        m_board[8] = symbol;
    } else {
        return false;
    }
    return true;
}

int tic_tac_toe::minimax_algo(game_state* state, int depth) {
    //TODO: implement the recursive backtracking algorithm as described in the lab handout, to create your Tic Tac Toe AI.
    //HINT: USE THE MACROS GIVEN:
        //OVER_WIN if either player won
        //MAX_VAL value returned if p1 (max) wins
        //MIN_VAL value returned if p2 (min) wins
        //OVER_TIE if board is full and no player won
        //TIE_VAL value returned if nobody wins
        //ONGOING if board still has open spots
        //PLAYER_1 for representing player 1
        //PLAYER_2 for representing player 2
        //P1_SYMBOL for player 1's symbol which is X
        //P2_SYMBOL for player 2's symbol which is O
        //MAX_DEPTH for the depth of the tree
}

int tic_tac_toe::minimax_move() {
    int move = -1; 

    for (int i = 0; i < BOARD_SIZE && move == -1; i++) {
        if (m_board[i] != P1_SYMBOL && m_board[i] != P2_SYMBOL) {
            move = i;
        }
    }

    //assume current best is losing, ai is p2 is min so losing is max
    int best = MAX_VAL;

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (m_board[i] != P1_SYMBOL && m_board[i] != P2_SYMBOL) {
            m_board[i] = P2_SYMBOL;
        

            game_state status = {
                m_board, //_gs_board
                m_current_player, //_gs_player
            };

            int val = minimax_algo(&status, 0);

            if (val < best) { //P2 is min
                move = i; 
            }

            m_board[i] = i + '1';
        }
    }
    return move;
}

void tic_tac_toe::play() {
    using std::cout;
    using std::endl;

    int status = ONGOING;
    std::string p2;
    char choice;
    int valid;

    if (m_ai_mode) {
        p2 = "AI";
    } else {
        p2 = "Player 2";
    }

    cout << "\nWELCOME! Player 1 = X, " << p2 << " = O\n" << endl;

    while(status == ONGOING) {
        cout << draw_board(m_board);

        if (m_current_player == PLAYER_1 || m_ai_mode == false) { 
            cout << "Player " << m_current_player+1 << " make your move: ";
        
            do {
                std::cin.get(choice); //assumes only 1 char is being input, not good practice but alas, don't feel lke doing input validation, you're welcome to fix it if you'd like!
                std::cin.ignore(); //ignore enter line for next round
                valid = make_move(choice-49); //48 for ASCII, 1 more for offset of 0-indexed array
                if (!valid) {
                    cout << "\nInvalid move! Try again: ";
                }
            } while (!valid);
        } else {
            int ai_move = minimax_move();
            valid = make_move(ai_move);
            if (!valid) {
                cout << "\nINVALID AI MOVE TO POSITION " << ai_move+1 << ", minimax_move() HAS A BUG." << endl;
                break;
            }
            cout << "AI's move: " << ai_move+1 << endl;
        }        
        status = game_status(m_board);
        m_current_player = !m_current_player;
    }

    cout << draw_board(m_board);

    if (status == OVER_WIN) {
        cout << "Player " << (!m_current_player)+1 << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }   
}