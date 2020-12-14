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
std::string convert_character_to_symbol(Character c);

int main() {

    Character game_board[3][3];
    Character player_1 = CH_X;
    Character player_2 = CH_O;

    build_game_board(game_board);
    display_game_board(game_board);

    make_selection(player_1, 0, 0, game_board);
    make_selection(player_2, 1, 1, game_board);
    display_game_board(game_board);

    return 0;
}

void make_selection(Character player, int row, int col, Character game_board[][3]) {
    game_board[row][col] = player;
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
