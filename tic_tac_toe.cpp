#include <iostream>

int NUM_ROWS = 3;
int NUM_COLS = 3;

enum Character { CH_X, CH_O, CH_EMPTY };

void build_game_board(Character game_board[][3]);
void display_game_board(Character game_board[][3]);


int main() {

    Character game_board[3][3];

    build_game_board(game_board);
    display_game_board(game_board);

    return 0;
}

void display_game_board(Character game_board[][3]) {
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            std::cout << "| " << CH_EMPTY << " |";
        }
        std::cout << "\n";
    }
}

void build_game_board(Character game_board[][3]) {
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            game_board[row][col] = CH_EMPTY;
        }
    }
}
