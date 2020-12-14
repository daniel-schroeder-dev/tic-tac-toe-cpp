#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int NUM_ROWS = 3;
int NUM_COLS = 3;

enum Character { CH_X, CH_O, CH_EMPTY };

void build_game_board(Character game_board[][3]);
void display_game_board(Character game_board[][3]);
void make_selection(Character player, int row, int col, Character game_board[][3]);
bool is_on_game_board(int row, int col);
bool square_already_filled(int row, int col, Character game_board[][3]);

std::string convert_character_to_symbol(Character c);

int main() {

    Character game_board[3][3];
    Character player_1 = CH_X;
    Character player_2 = CH_O;
    Character current_player = player_1;
    
    bool should_continue = true;

    int row;
    int col;

    build_game_board(game_board);
    display_game_board(game_board);

    while (should_continue) {
        std::cout << "Select row: ";
        std::cin >> row;
        std::cout << "Select col: ";
        std::cin >> col;
    
        make_selection(current_player, row, col, game_board);
        display_game_board(game_board); 

        current_player = current_player == player_1 ? player_2 : player_1;
    }

    return 0;
}

bool square_already_filled(int row, int col, Character game_board[][3]) {
    return game_board[row][col] != CH_EMPTY;
}

bool is_on_game_board(int row, int col) {
    return (row >= 0 && row < NUM_ROWS) && (col >= 0 && col < NUM_COLS);
}

void make_selection(Character player, int row, int col, Character game_board[][3]) {
    if (!is_on_game_board(row, col) || square_already_filled(row, col, game_board)) {
        std::cout << "Invalid selection, you lose your turn!" << std::endl;
    } else {
        game_board[row][col] = player;
    }
}

std::string convert_character_to_symbol(Character c) {
    switch (c) {
        case CH_X:
            return "X";
            break;
        case CH_O:
            return "O";
            break;
        case CH_EMPTY:
            return " ";
            break;
        default:
            return "AHHHHHH!";
            break;
    }
}

void display_game_board(Character game_board[][3]) {
    std::cout << "----------------" << std::endl;
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            std::cout << " | " << convert_character_to_symbol(game_board[row][col]);
        }
        std::cout << " |\n";
    }
    std::cout << "----------------" << std::endl;

}

void build_game_board(Character game_board[][3]) {
    srand(time(NULL));
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            game_board[row][col] = CH_EMPTY;
        }
    }
}
