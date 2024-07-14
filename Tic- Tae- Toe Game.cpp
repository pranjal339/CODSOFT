#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;


void initialize_board(vector<vector<char>>& board);
void print_board(const vector<vector<char>>& board);
bool check_win(const vector<vector<char>>& board, char player);
bool is_board_full(const vector<vector<char>>& board);
bool is_valid_move(const vector<vector<char>>& board, int row, int col);
void update_board(vector<vector<char>>& board, int row, int col, char player);
char switch_player(char current_player);
bool play_again();

int main() {
    char current_player = 'X';
    vector<vector<char>> board(3, vector<char>(3, ' '));
    bool game_over = false;

    do {
        initialize_board(board);

        while (!game_over) {
            print_board(board);

            
            int row, col;
            do {
                cout << "Player " << current_player << ", enter your move (row column): ";
                cin >> row >> col;
                row--; 
                col--; 

                if (!is_valid_move(board, row, col)) {
                    cout << "Invalid move! Please try again.\n";
                }
            } while (!is_valid_move(board, row, col));

            
            update_board(board, row, col, current_player);

            
            if (check_win(board, current_player)) {
                print_board(board);
                cout << "Player " << current_player << " wins!\n";
                game_over = true;
            } else if (is_board_full(board)) {
                print_board(board);
                cout << "It's a draw!\n";
                game_over = true;
            } else {
                
                current_player = switch_player(current_player);
            }
        }

        
        game_over = !play_again();
        if (!game_over) {
            
            current_player = 'X';
            initialize_board(board);
        }
    } while (!game_over);

    cout << "Thanks for playing Tic Tac Toe!\n";

    return 0;
}

void initialize_board(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void print_board(const vector<vector<char>>& board) {
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool check_win(const vector<vector<char>>& board, char player) {
    
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool is_board_full(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool is_valid_move(const vector<vector<char>>& board, int row, int col) {
    
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

void update_board(vector<vector<char>>& board, int row, int col, char player) {
    board[row][col] = player;
}

char switch_player(char current_player) {
    return (current_player == 'X') ? 'O' : 'X';
}

bool play_again() {
    char choice;
    cout << "Do you want to play again? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}
