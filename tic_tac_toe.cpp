#include <iostream>
#include <string>

int NUM_ROWS = 3;
int NUM_COLS = 3;

enum Character { CH_X, CH_O, CH_EMPTY };

void build_game_board(Character game_board[][3]);
void display_game_board(Character game_board[][3]);
void make_selection(Character player, int row, int col, Character game_board[][3]);
void display_player_avatar(Character player);

bool is_on_game_board(int row, int col);
bool square_already_filled(int row, int col, Character game_board[][3]);

std::string get_player_avatar(Character player);
std::string convert_character_to_symbol(Character c);

int prompt_for_selection(std::string message);

Character check_for_winner(Character game_board[][3]);
Character check_rows(Character game_board[][3]);
Character check_cols(Character game_board[][3]);
Character check_diagonals(Character game_board[][3]);

int main() {

    Character game_board[3][3];
    Character player_1 = CH_X;
    Character player_2 = CH_O;
    Character current_player = player_1;
    
    Character winner = CH_EMPTY;

    int row;
    int col;

    build_game_board(game_board);
    display_game_board(game_board);

    while (winner == CH_EMPTY) {
        display_player_avatar(current_player);
        row = prompt_for_selection("Select row: ");
        col = prompt_for_selection("Select col: ");
    
        make_selection(current_player, row, col, game_board);
        display_game_board(game_board); 

        winner = check_for_winner(game_board);

        current_player = current_player == player_1 ? player_2 : player_1;
    }

    std::cout << get_player_avatar(winner) << " wins!!!" << std::endl;

    return 0;
}

Character check_diagonals(Character game_board[][3]) {
    if (game_board[0][0] == game_board[1][1] && game_board[0][0] == game_board[2][2]) {
        return game_board[0][0];
    } 
    if (game_board[0][2] == game_board[1][1] && game_board[0][2] == game_board[2][0]) {
        return game_board[0][2];
    } 
    return CH_EMPTY;
}

Character check_cols(Character game_board[][3]) {
    for (int col = 0; col < NUM_COLS; col++) {
        bool all_same_character = true;
        Character first_character = game_board[0][col];
        for (int row = 1; row < NUM_ROWS; row++) {
            if (game_board[row][col] != first_character) {
                all_same_character = false;
                break;
            }
        }
        if (all_same_character) return first_character;
    }
    return CH_EMPTY;
}

Character check_rows(Character game_board[][3]) {
    for (int row = 0; row < NUM_ROWS; row++) {
        bool all_same_character = true;
        Character first_character = game_board[row][0];
        for (int col = 1; col < NUM_COLS; col++) {
            if (game_board[row][col] != first_character) {
                all_same_character = false;
                break;
            }
        }
        if (all_same_character) return first_character;
    }
    return CH_EMPTY;
}

Character check_for_winner(Character game_board[][3]) {
    Character winner;
    winner = check_rows(game_board);
    if (winner != CH_EMPTY) return winner;
    winner = check_cols(game_board);
    if (winner != CH_EMPTY) return winner;
    winner = check_diagonals(game_board);
    return winner;
}

int prompt_for_selection(std::string message) {
    int row_col_selection;
    std::cout << message;
    std::cin >> row_col_selection;
    return row_col_selection;
}

void display_player_avatar(Character player) {
    std::cout << "Current Player: " << get_player_avatar(player) << std::endl;
}

std::string get_player_avatar(Character player) {
    return player == CH_X ? "X" : "O";
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
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            game_board[row][col] = CH_EMPTY;
        }
    }
}
