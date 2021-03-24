/* 
    Program will generate a number from 0 to 20.
    You will then ask user to guess it.
    Program will indicate to the user if each guess is too high or too low.
    User wins the game if they can guess the number within five tries.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int random_num = 0, player_guess = 0, tries = 5;
    time_t t;

    /* Initialize random number generator */
    srand((unsigned) time(&t));

    /* Generate a random number */
    random_num = rand() % 21;

    printf("This is a guessing game.\n");
    printf("I have chosen a number between 0 and 20 which you must guess.\n");
 
    /* Prompt user to guess the number */
    while (tries > 0) {
        printf("\nYou have %i tr%s left\n", tries, tries > 1? "ies" : "y");
        printf("Enter your guess: ");
        scanf("%i", &player_guess);
        
        if (player_guess == random_num) {
            printf("Congratulations! You guessed it!\n");
            printf("\nThanks for playing!\n");
            return 0;
        }
        else if (player_guess > random_num) {
            printf("\nSorry, %i is wrong. My number is less than that.\n", player_guess);
        }
        else if (player_guess < random_num) {
                printf("Sorry, %i is wrong. My number is greater than that.\n", player_guess);
        }
        else {
            printf("You can only enter numbers between 0 and 20.\n");
        }

        --tries;
    }

    printf("\nSorry you ran out of tries. The number was %i.\n", random_num);
    printf("\nThanks for playing!\n");
}