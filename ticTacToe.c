/* A simple tic tac toe game between two players.
 *
 * Constraints: 
 * 1. Does not check for non-numeric values when
 *    prompted to select a space on the board.
 * 2. "Invalid Option" does not display due to system("clear")
 * 3. Players cannot be a computer.
 */


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void drawBoard(void);
void markBoard(char mark, int location);
bool checkWinner();

char BOARD[10] = {'0','1','2','3','4','5','6','7','8','9'};

int main(void)
{
    int player = 1,location = 1;
    int count = 0; // tracks the number of occupied spaces in the board
    char mark;
    bool isWinner = false;

    while (isWinner == false)
    {
        drawBoard();

        // Change turns
        player = ( player % 2 ) ? 1 : 2;
        mark = player == 1 ? 'X' : 'O';

        // Prompt current player to select a space on the board
        printf("Player %i, select an unoccupied number from the board: ", player);
        scanf("%i", &location);

        /* Check if the space selected by player is valid.
         * If valid, mark the board.
         * If not, ask player to select an unoccupied space again. */
        if (location >= 1 && location <=9) {
            if (BOARD[location] != 'X' && BOARD[location] != 'O') {
                markBoard(mark, location);
                drawBoard();
                player += 1;
                count = count + 1;
            }
            else {
                printf("Invalid Option.\n");
                getchar();
            }
        } 
        else {
            printf("Invalid Option.\n");
            getchar();
        }

        // Checks if there's a winner
        isWinner = checkWinner();

        if (isWinner == true) {
            player --;
            printf("\n\n==> PLAYER %i is the Winner\n\n", player);
            break;
        }
        else if (isWinner == false && count == 9) {
            printf("\n\n==> It's a Draw!\n");
            break;
        }
        else {
            continue;
        }
    }
   
    return 0;
}

// Draws the board
void drawBoard(void)
{
    system("clear");
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", BOARD[1], BOARD[2], BOARD[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", BOARD[4], BOARD[5], BOARD[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", BOARD[7], BOARD[8], BOARD[9]);
    printf("     |     |     \n");

    return;
}

// Marks the player's selected space
void markBoard(char mark, int location)
{
    BOARD[location] = mark;
    return;
}

// Checks for winner
bool checkWinner()
{
    if (BOARD[1] == BOARD[2] && BOARD[2] == BOARD[3]) {
        return true;
    }
    else if (BOARD[4] == BOARD[5] && BOARD[5] == BOARD[6]) {
        return true;
    }
    else if (BOARD[7] == BOARD[8] && BOARD[8] == BOARD[9]) {
        return true;
    }
    else if (BOARD[1] == BOARD[4] && BOARD[4] == BOARD[7]) {
        return true;
    }
    else if (BOARD[2] == BOARD[5] && BOARD[5] == BOARD[8]) {
        return true;
    }
    else if (BOARD[3] == BOARD[6] && BOARD[6] == BOARD[9]) {
        return true;
    }
    else if (BOARD[1] == BOARD[5] && BOARD[5] == BOARD[9]) {
        return true;
    }
    else if (BOARD[3] == BOARD[5] && BOARD[5] == BOARD[7]) {
        return true;
    }
    else {
        return false;
    }
}