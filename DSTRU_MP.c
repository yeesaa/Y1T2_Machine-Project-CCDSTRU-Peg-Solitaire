#include <stdio.h>
#include <string.h>

#define Size 3

int game [Size][Size];

/*
    make a tic tac toe game 
*/

// initialize the board with empty cells
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// print the board to the console
void print_board() {
    printf("  1 2 3\n");
    printf(" -------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n");
        printf(" -------\n");
    }
}


int main()
{
    initialize_board();
        
    print_board();




    return 0;
}