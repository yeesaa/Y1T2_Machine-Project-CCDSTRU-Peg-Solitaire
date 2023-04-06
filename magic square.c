#include <stdio.h>

int main()
{
    int magic_square[3][3] = {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}};
    int player_choice, row, col, turn, j, i;
    char player_mark = 'X';

    printf("Welcome to the 3x3 Magic Square game!\n");
    printf("You will play against the computer.\n");

    for (turn = 1; turn <= 9; turn++)
    {
        // print current game state
        printf("\nCurrent board:\n\n");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%c ", magic_square[i][j] == player_mark ? player_mark : '_');
            }
            printf("\n");
        }

        // get player's choice
        printf("\nPlayer %c, please choose a number from 1-9: ", player_mark);
        scanf("%d", &player_choice);

        // validate player's choice
        if (player_choice < 1 || player_choice > 9)
        {
            printf("\nInvalid choice. Please choose a number from 1-9.\n");
            turn--;
            continue;
        }
        
        row = (player_choice - 1) / 3;
        col = (player_choice - 1) % 3;
        
		if (magic_square[row][col] != player_choice)
        {
            printf("\nThat square is already occupied. Please choose another number.\n");
            turn--;
            continue;
        }

        // update game state
        magic_square[row][col] = player_mark;

        // check if game is won
        if ((magic_square[0][0] + magic_square[0][1] + magic_square[0][2] == 15 && magic_square[1][0] + magic_square[1][1] + magic_square[1][2] == 15 && magic_square[2][0] + magic_square[2][1] + magic_square[2][2] == 15) &&
            (magic_square[0][0] + magic_square[1][0] + magic_square[2][0] == 15 && magic_square[0][1] + magic_square[1][1] + magic_square[2][1] == 15 && magic_square[0][2] + magic_square[1][2] + magic_square[2][2] == 15) &&
            (magic_square[0][0] + magic_square[1][1] + magic_square[2][2] == 15 && magic_square[0][2] + magic_square[1][1] + magic_square[2][0] == 15))
        {
            printf("\nPlayer %c wins!\n", player_mark);
            break;
        }

        // switch players
        player_mark = player_mark == 'X' ? 'O' : 'X';
    }

    // game over
    printf("\nFinal board:\n\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%c ", magic_square[i][j]);
        }
        printf("\n");
    }

    return 0;
}
